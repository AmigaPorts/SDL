# ADR-005: Signal-Based Thread Join

## Status

Accepted

## Date

2026-03-20

## Context

SDL2's `SDL_WaitThread()` must block until a child thread (Exec Task / DOS Process) has fully exited and then retrieve its return value. On POSIX this is `pthread_join()`. On AmigaOS 3.x, there is no direct equivalent.

The initial implementation used `FindTask()` polling: the parent would loop calling `FindTask(child_name)` until it returned NULL, indicating the child task had been removed from the system. This approach had a critical use-after-free bug:

1. Child task finishes its SDL thread function and stores the return value
2. Child calls `RemTask()` (implicitly via process exit)
3. Between steps 1 and 2, or during `RemTask()` itself, the task's memory may be partially freed
4. Parent calls `FindTask(name)` which traverses the Exec task list -- if the child's Task node is being freed concurrently, this reads freed memory

This caused intermittent Guru Meditations (crashes) during thread join, particularly under load.

The ADCD (Amiga Developer CD) volume III, chapter 17 documents the correct pattern for inter-task synchronization using signals: a child task allocates a signal bit in the parent's context, and signals the parent before exiting while holding `Forbid()` to prevent being scheduled out between signaling and actually exiting.

## Decision

**Use the ADCD III-17 SIGF_SINGLE signal pattern for thread join.**

The implementation:

1. **Parent (SDL_SYS_CreateThread):** Allocates a signal bit (`AllocSignal()`) and stores it in the thread context. Creates the child process via `CreateNewProcTags()`. Uses `Forbid()/Permit()` around process creation to prevent the child from running before the thread context is fully initialized.

2. **Child (thread entry):** Runs the SDL thread function. When finished, stores the return value. Calls `Forbid()` to prevent being scheduled out. Signals the parent task using the pre-allocated signal bit. Returns (process exits). Because `Forbid()` is held, the parent will not be scheduled until after the child's process cleanup completes.

3. **Parent (SDL_SYS_WaitThread):** Calls `Wait(signal_mask)` which blocks until the child signals. When the signal arrives, the child is guaranteed to have exited (because it signaled under `Forbid()`). The parent retrieves the return value and frees the signal bit.

## Consequences

### Positive

- Eliminates the use-after-free crash from FindTask polling
- Follows the documented, recommended AmigaOS pattern for task synchronization
- Zero-cost waiting -- `Wait()` puts the parent to sleep instead of burning CPU in a polling loop
- Race-free by construction -- Forbid() in the child prevents scheduling between signal and exit

### Negative

- Consumes one signal bit per pending thread join (Exec Tasks have 32 signal bits total, of which ~16 are available). This limits the number of simultaneously joinable threads. In practice, SDL2 applications rarely have more than a few threads.
- More complex than polling, but correctness requires this complexity

### Neutral

- The signal bit is allocated in the parent's context and freed after join, so there is no persistent resource consumption
- This pattern is used by the SDL 1.2 AmigaOS port and other well-known Amiga software
