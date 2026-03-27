---
title: 26 Exec Interrupts / Function Reference
manual: libraries
chapter: libraries
section: 26-exec-interrupts-function-reference
functions: [AddIntServer, Cause, Disable, Enable, RemIntServer, SetIntVector]
libraries: [exec.library]
---

# 26 Exec Interrupts / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following chart gives a brief description of the Exec functions that
control interrupts.  See the Amiga ROM Kernel Reference Manual: Includes
and Autodocs for details about each call.


                   Table 26-2: Exec Interrupt Functions
  ________________________________________________________________________
 |                                                                        |
 | Interrupt Function                Description                          |
 |========================================================================|
 |  [AddIntServer()](autodocs-2.0/exec-library-addintserver.md)  Add an interrupt server to a system server chain.     |
 |         [Cause()](autodocs-2.0/exec-library-cause.md)  Cause a software interrupt.                           |
 |       [Disable()](autodocs-2.0/exec-library-disable.md)  Disable interrupt processing.                         |
 |        [Enable()](autodocs-2.0/exec-library-enable.md)  Restart system interrupt processing.                  |
 |  [RemIntServer()](autodocs-2.0/exec-library-remintserver.md)  Remove an interrupt server from a system server chain.|
 |  [SetIntVector()](autodocs-2.0/exec-library-setintvector.md)  Set a new handler for a system interrupt vector.      |
 |________________________________________________________________________|

---

## See Also

- [AddIntServer — exec.library](../autodocs/exec.library.md#addintserver)
- [Cause — exec.library](../autodocs/exec.library.md#cause)
- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
- [RemIntServer — exec.library](../autodocs/exec.library.md#remintserver)
- [SetIntVector — exec.library](../autodocs/exec.library.md#setintvector)
