# 26 Exec Interrupts / Introduction


Exec manages the decoding, dispatching, and sharing of all system
interrupts.  This includes control of hardware interrupts, software
interrupts, task-relative interrupts (see the discussion of exceptions in
the "[Exec Tasks](../Libraries_Manual_guide/node02C5.html)" chapter), and interrupt disabling and enabling.  In
addition, Exec supports a more extended prioritization of interrupts than
that provided in the 68000.

The proper operation of multitasking depends heavily on the consistent
management of the interrupt system.  Task activities are often driven by
intersystem communication that is originated by various interrupts.

 [Sequence of Events During an Interrupt](../Libraries_Manual_guide/node0303.html) 
 [Interrupt Priorities](../Libraries_Manual_guide/node0304.html) 
 [Nonmaskable Interrupt](../Libraries_Manual_guide/node0305.html) 

