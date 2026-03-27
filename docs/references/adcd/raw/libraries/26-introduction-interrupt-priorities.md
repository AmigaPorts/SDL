# 26 / Introduction / Interrupt Priorities


Interrupts are prioritized in hardware and software.  The 68000 CPU
priority at which an interrupt executes is determined strictly by
hardware.  In addition to this, the software imposes a finer level of
pseudo-priorities on interrupts with the same CPU priority. These
pseudo-priorities determine the order in which simultaneous interrupts of
the same CPU priority are processed.  Multiple interrupts with the same
CPU priority but a different pseudo-priority will not interrupt one
another.  Interrupts are serviced by either an exclusive handler or by
server chains to which many servers may be attached, as shown in the Type
field of the table.  The [table above](../Libraries_Manual_guide/node0303.html#line67) summarizes all interrupts by
priority.

The 8520s (also called CIAs) are Amiga peripheral interface adapter chips
that generate the INT2 and INT6 interrupts.  For more information about
them, see the Amiga [Hardware](../Hardware_Manual_guide/node0163.html) Reference Manual.

As described in the Motorola 68000 programmer's manual, interrupts may
nest only in the direction of higher priority.  Because of the
time-critical nature of many interrupts on the Amiga, the CPU priority
level must never be changed by user or system code. When the system is
running in user mode (multitasking), the CPU priority level must remain
set at zero.  When an interrupt occurs, the CPU priority is raised to the
level appropriate for that interrupt. Lowering the CPU priority would
permit unlimited interrupt recursion on the system stack and would
"short-circuit" the interrupt-priority scheme.

Because it is dangerous on the Amiga to hold off interrupts for any period
of time, higher-level interrupt code must perform its business and exit
promptly.  If it is necessary to perform a time-consuming operation as the
result of a high-priority interrupt, the operation should be deferred
either by posting a software interrupt or by signalling a task.  In this
way, interrupt response time is kept to a minimum.  [Software interrupts](../Libraries_Manual_guide/node030D.html)
are described in a later section.

