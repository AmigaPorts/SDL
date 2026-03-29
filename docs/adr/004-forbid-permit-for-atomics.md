# ADR-004: Forbid/Permit for Atomics

## Status

Accepted

## Date

2026-03-15

## Context

SDL2 requires atomic operations (`SDL_AtomicTryLock`, `SDL_AtomicSet`, `SDL_AtomicGet`, `SDL_AtomicCAS`) for its internal synchronization. On modern platforms these map to hardware atomic instructions (x86 LOCK CMPXCHG, ARM LDREX/STREX).

The Motorola 68020+ provides the CAS (Compare-and-Swap) instruction, which is a true hardware atomic. However, there are two problems with using it:

1. **FS-UAE emulation issues:** FS-UAE's CAS emulation has subtle contention behavior that differs from real hardware. Under heavy contention (multiple Exec Tasks doing CAS on the same location), the emulated CAS can produce unexpected results. Since FS-UAE is the primary development and testing environment, this is a practical blocker.

2. **Unnecessary complexity:** AmigaOS 3.x is a single-core cooperative multitasking system. There is no SMP, no out-of-order execution, no store buffer reordering. The only source of concurrency is Exec task switching (and interrupts). `Forbid()` disables task switching; `Permit()` re-enables it. Between a `Forbid()`/`Permit()` pair, the current task has exclusive access to all memory -- a stronger guarantee than CAS provides.

SDL 1.2 for AmigaOS 3.x used the same approach.

## Decision

**Implement SDL2 atomics using Forbid/Permit (task-switch inhibition) instead of 68020 CAS.**

```c
int SDL_AtomicTryLock(SDL_SpinLock *lock)
{
    Forbid();
    if (*lock == 0) {
        *lock = 1;
        Permit();
        return SDL_TRUE;
    }
    Permit();
    return SDL_FALSE;
}
```

This pattern is used for all atomic operations: TryLock, Set, Get, CAS, Add.

## Consequences

### Positive

- Works correctly on both real hardware and FS-UAE
- Simpler to reason about correctness -- Forbid/Permit is the idiomatic AmigaOS synchronization primitive
- No dependency on 68020+ instructions (would work on 68000 if needed)
- Matches the SDL 1.2 AmigaOS implementation

### Negative

- Forbid/Permit disables ALL task switching, not just contention on the target variable. In theory this is heavier than CAS. In practice, the critical sections are a few instructions long, so the window is negligible.
- If AmigaOS ever ran on SMP hardware, this would not be safe. (AmigaOS 3.x is exclusively single-core, so this is not a concern.)

### Neutral

- Performance is equivalent to CAS for the single-core case -- both are a few instructions with no memory bus locking needed
- Interrupt handlers still run during Forbid(), but SDL2 does not use interrupts directly (audio interrupts go through AmigaOS device I/O)
