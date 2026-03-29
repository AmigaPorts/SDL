# ADR-007: Lazy Device Open Pattern

## Status

Accepted

## Date

2026-03-20

## Context

AmigaOS device I/O (audio.device, timer.device, etc.) requires a `MsgPort` for asynchronous communication. When an I/O request completes, the device sends a message to the MsgPort, which sets a signal bit in the **owning task** (the task that created the MsgPort via `CreateMsgPort()`).

This is documented in ADCD chapter 22: signal bits are allocated per-task, and a signal set by one task's MsgPort cannot wake a different task's `Wait()` call. Concretely:

1. Task A calls `CreateMsgPort()` -- signal bit is allocated in Task A's signal mask
2. Task A calls `OpenDevice()` and `SendIO()` -- device will signal Task A's MsgPort on completion
3. If Task B calls `WaitIO()` on that request, it calls `Wait()` on the signal bit -- but that signal bit belongs to Task A, so Task B waits forever

SDL2's architecture initializes subsystems (audio, timer) in the main thread but may use them from different threads. For example:

- `SDL_Init(SDL_INIT_AUDIO)` is called from the main thread
- SDL2 creates an internal audio thread that calls `PlayDevice()` / `WaitDevice()` in a loop
- If the audio device was opened in the main thread, `WaitIO()` in the audio thread hangs

This caused real hangs during Phase 3 development.

## Decision

**Open AmigaOS devices lazily in the thread that will perform I/O on them, not during subsystem initialization.**

The pattern:
1. `SDL_Init()` / `OpenDevice()` only probes whether the device exists (open and immediately close, or check library availability)
2. The actual `CreateMsgPort()` + `OpenDevice()` + `CreateIORequest()` happens on first use in the worker thread
3. `CloseDevice()` + `DeleteIORequest()` + `DeleteMsgPort()` happens in the same worker thread during shutdown

This is implemented as a "lazy open" idiom: a flag tracks whether the device has been opened, and the first call to the I/O function triggers the open sequence.

## Consequences

### Positive

- Eliminates cross-task MsgPort hangs
- Each thread owns its own MsgPort and signal bits, matching AmigaOS design
- `WaitIO()` always wakes the correct task

### Negative

- First I/O operation has higher latency (device open overhead)
- Error handling is deferred -- a device open failure during `SDL_Init()` would be caught early; with lazy open, it surfaces later during playback or timing
- Slightly more complex lifecycle management (open/close in worker thread instead of centralized init/quit)

### Neutral

- The lazy open cost is amortized over the lifetime of the subsystem (typically opened once)
- This pattern is used by other AmigaOS audio software that separates I/O into dedicated tasks
