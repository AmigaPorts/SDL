# 21 / Processor and Cache Control / Supervisor Mode


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
interrupt or trap).  The [Supervisor()](../Includes_and_Autodocs_2._guide/node0386.html) function allows you to trap an
exception to a specified assembly function.  In this function your have
full access to all registers.  No registers are saved when your function
is invoked.  You are responsible for restoring the system to a sane state
when you are done. You must return to user mode with an RTE instruction.
You must not return to user mode by executing a privileged instruction
which clears the supervisor bit in the [status register](../Libraries_Manual_guide/node02CB.html).  Refer to a manual
on the M68000 family of CPUs for information about supervisor mode and
available privileged instructions per processor type.

The MC68000 has two stacks, the user stack (USP) and supervisor stack
(SSP). As of the MC68020 there are two supervisor stacks, the interrupt
stack pointer (ISP) and the master stack pointer (MSP). The [SuperState()](../Includes_and_Autodocs_2._guide/node0385.html)
function allows you to enter supervisor mode with the USP used as SSP. The
function returns the SSP, which will be the MSP, if an MC68020 or greater
is used. Returning to user mode is done with the [UserState()](../Includes_and_Autodocs_2._guide/node0388.html) function.
This function takes the SSP as argument, which must be saved when
SuperState() is called.  Because of possible problems with stack size,
[Supervisor()](../Includes_and_Autodocs_2._guide/node0386.html) is to be preferred over SuperState().

