---
title: 21 / Task Traps / Trap Instructions
manual: libraries
chapter: libraries
section: 21-task-traps-trap-instructions
functions: [AllocSignal, AllocTrap, FreeSignal, FreeTrap]
libraries: [exec.library]
---

# 21 / Task Traps / Trap Instructions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The TRAP instructions in the 68000 generate traps 32-47.  Because many
independent pieces of system code may desire to use these traps, the
[AllocTrap()](autodocs-2.0/exec-library-alloctrap.md) and [FreeTrap()](autodocs-2.0/exec-library-freetrap.md) functions are provided.  These work in a
fashion similar to that used by [AllocSignal()](libraries/22-the-signal-system-signal-allocation.md) and [FreeSignal()](libraries/22-the-signal-system-signal-allocation.md), mentioned
in the "[Exec Signals](libraries/22-the-signal-system-signal-allocation.md)" chapter.

Allocating a trap is simply a bookkeeping job within a task.  It does not
affect how the system calls the trap handler; it helps coordinate who owns
what traps.  Exec does nothing to determine whether or not a task is
prepared to handle a particular trap.  It simply calls your code. It is up
to your program to handle the trap.

To allocate any trap, you can use the following code:


```c
    if (-1 == (trap = AllocTrap(-1)))
        printf("all trap instructions are in use\n");
```
Or you can select a specific trap using this code:


```c
    if (-1 == (trap = AllocTrap(3)))
        printf("trap #3 is in use\n");
```
To free a trap, you use the [FreeTrap()](autodocs-2.0/exec-library-freetrap.md) function passing it the trap number
to be freed.

---

## See Also

- [AllocSignal — exec.library](../autodocs/exec.library.md#allocsignal)
- [AllocTrap — exec.library](../autodocs/exec.library.md#alloctrap)
- [FreeSignal — exec.library](../autodocs/exec.library.md#freesignal)
- [FreeTrap — exec.library](../autodocs/exec.library.md#freetrap)
