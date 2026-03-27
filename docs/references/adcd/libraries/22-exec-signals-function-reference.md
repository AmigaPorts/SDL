---
title: 22 Exec Signals / Function Reference
manual: libraries
chapter: libraries
section: 22-exec-signals-function-reference
functions: [AllocSignal, FreeSignal, SetSignal, Signal, Wait]
libraries: [exec.library]
---

# 22 Exec Signals / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following chart gives a brief description of the Exec functions that
control task signalling.  See the Amiga ROM Kernel Reference Manual:
Includes and Autodocs for details about each call.


                    Table 22-1: Exec Signal Functions
  _______________________________________________________________________
 |                                                                       |
 |   Exec Signal                                                         |
 |    Function                         Description                       |
 |=======================================================================|
 |  [AllocSignal()](autodocs-2.0/exec-library-allocsignal.md)  Allocate a signal bit.                                |
 |   [FreeSignal()](autodocs-2.0/exec-library-freesignal.md)  Free a signal bit allocated with AllocSignal().       |
 |    [SetSignal()](autodocs-2.0/exec-library-setsignal.md)  Query or set the state of the signals for the current |
 |                 task.                                                 |
 |       [Signal()](autodocs-2.0/exec-library-signal.md)  Signal a task by setting signal bits in its [Task](libraries/21-exec-tasks-task-structure.md)      |
 |                 structure.                                            |
 |         [Wait()](autodocs-2.0/exec-library-wait.md)  Wait for one or more signals from other tasks or      |
 |                 interrupts.                                           |
 |_______________________________________________________________________|

---

## See Also

- [AllocSignal — exec.library](../autodocs/exec.library.md#allocsignal)
- [FreeSignal — exec.library](../autodocs/exec.library.md#freesignal)
- [SetSignal — exec.library](../autodocs/exec.library.md#setsignal)
- [Signal — exec.library](../autodocs/exec.library.md#signal)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
