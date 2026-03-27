---
title: 21 Exec Tasks / Task Traps
manual: libraries
chapter: libraries
section: 21-exec-tasks-task-traps
functions: []
libraries: []
---

# 21 Exec Tasks / Task Traps

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Task traps are synchronous exceptions to the normal flow of program
control.  They are always generated as a direct result of an operation
performed by your program's code.  Whether they are accidental or
purposely generated, they will result in your program being forced into a
special condition in which it must immediately handle the trap.  Address
error, privilege violation, zero divide, and trap instructions all result
in task traps.  They may be generated directly by the 68000 processor
(Motorola calls them "exceptions") or simulated by software.

A task that incurs a trap has no choice but to respond immediately. The
task must have a module of code to handle the trap.  Your task may be
aborted if a trap occurs and no means of handling it has been provided.
Default trap handling code ([tc_TrapCode](libraries/21-exec-tasks-task-structure.md)) is provided by the OS.  You may
instead choose to do your own processing of traps.  The tc_TrapCode field
is the address of the handler that you have designed to process the trap.
The tc_TrapData field is the address of the data area for use by the trap
handler.

The system's default trap handling code generally displays a Software
Error Requester or Alert containing an exception number and the program
counter or task address.  Processor exceptions generally have numbers in
the range hex 00 to 2F.  The 68000 processor exceptions of particular
interest are as follows.




```c
            Table 21-1: Traps (68000 Exception Vector Numbers)

    2      Bus error            access of nonexistent memory
    3      Address error        long/word access of odd address (68000)
    4      Illegal instruction  illegal opcode (other than Axxx or Fxxx)
    5      Zero divide          processor division by zero
    6      CHK instruction      register bounds error trap by CHK
    7      TRAPV instruction    overflow error trap by TRAPV
    8      Privilege violation  user execution of supervisor opcode
    9      Trace                [status register](libraries/21-processor-and-cache-control-status-register.md) TRACE bit trap
    10     Line 1010 emulator   execution of opcode beginning with $A
    11     Line 1111 emulator   execution of opcode beginning with $F
    32-47  Trap instructions    TRAP N instruction where N = 0 to 15
```
A system alert for a processor exception may set the high bit of the
longword exception number to indicate an unrecoverable error (for example
$80000005 for an unrecoverable processor exception #5).  System alerts
with more complex numbers are generally Amiga-specific software failures.
These are built from the definitions in the <exec/[alerts.h](autodocs-2.0/includes-exec-alerts-h.md)> include file.

The actual stack frames generated for these traps are processor-dependent.
The 68010, 68020, and 68030 processors will generate a different type of
stack frame than the 68000.  If you plan on having your program handle its
own traps, you should not make assumptions about the format of the
supervisor stack frame.  Check the flags in the [AttnFlags](autodocs-2.0/includes-exec-execbase-h.md) field of the
[ExecBase](autodocs-2.0/includes-exec-execbase-h.md) structure for the type of processor in use and process the stack
frame accordingly.

 [Trap Handlers](libraries/21-task-traps-trap-handlers.md)    [Trap Instructions](libraries/21-task-traps-trap-instructions.md) 

