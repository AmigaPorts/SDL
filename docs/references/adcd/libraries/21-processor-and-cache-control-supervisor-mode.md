---
title: 21 / Processor and Cache Control / Supervisor Mode
manual: libraries
chapter: libraries
section: 21-processor-and-cache-control-supervisor-mode
functions: [SuperState, Supervisor, UserState]
libraries: [exec.library]
---

# 21 / Processor and Cache Control / Supervisor Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

While in supervisor mode, you have complete access to all data and
registers, including those used for task scheduling and exceptions, and
can execute privileged instructions.  In application programs, normally
only task trap code is directly executed in supervisor mode, to be
compatible with the MC68000.  For normal applications, it should never be
necessary to switch to supervisor mode itself, only indirectly through
Exec function calls.  Remember that task switching is disabled while in
supervisor mode.  If it is absolutely needed to execute code in supervisor
mode, keep it as brief as possible.

Supervisor mode can only be entered when a 680x0 exception occurs (an
interrupt or trap).  The [Supervisor()](autodocs-2.0/exec-library-supervisor.md) function allows you to trap an
exception to a specified assembly function.  In this function your have
full access to all registers.  No registers are saved when your function
is invoked.  You are responsible for restoring the system to a sane state
when you are done. You must return to user mode with an RTE instruction.
You must not return to user mode by executing a privileged instruction
which clears the supervisor bit in the [status register](libraries/21-processor-and-cache-control-status-register.md).  Refer to a manual
on the M68000 family of CPUs for information about supervisor mode and
available privileged instructions per processor type.

The MC68000 has two stacks, the user stack (USP) and supervisor stack
(SSP). As of the MC68020 there are two supervisor stacks, the interrupt
stack pointer (ISP) and the master stack pointer (MSP). The [SuperState()](autodocs-2.0/exec-library-superstate.md)
function allows you to enter supervisor mode with the USP used as SSP. The
function returns the SSP, which will be the MSP, if an MC68020 or greater
is used. Returning to user mode is done with the [UserState()](autodocs-2.0/exec-library-userstate.md) function.
This function takes the SSP as argument, which must be saved when
SuperState() is called.  Because of possible problems with stack size,
[Supervisor()](autodocs-2.0/exec-library-supervisor.md) is to be preferred over SuperState().

---

## See Also

- [SuperState — exec.library](../autodocs/exec.library.md#superstate)
- [Supervisor — exec.library](../autodocs/exec.library.md#supervisor)
- [UserState — exec.library](../autodocs/exec.library.md#userstate)
