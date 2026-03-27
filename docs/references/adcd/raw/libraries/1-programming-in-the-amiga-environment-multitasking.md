# 1 / Programming in the Amiga Environment / Multitasking


The key feature of the Amiga's operating system design is [multitasking](../Libraries_Manual_guide/node0287.html).
Multitasking means many programs, or tasks, reside in memory at the same
time sharing system resources with one another.  Programs take turns
running so it appears that many programs are running simultaneously.

[Multitasking](../Libraries_Manual_guide/node0287.html) is based on the concept that a program spends most of its
time waiting for things to happen.  A program waits for events like key
presses, mouse movement, or disk activity.  While a program is waiting,
the CPU is idle.  The CPU could be used to run a different program during
this idle period if there was a convenient method for rapidly switching
from one program to another.  This is what multitasking does.

 [What the System Does For You](../Libraries_Manual_guide/node000B.html) 
 [What the System Doesn't Do For You](../Libraries_Manual_guide/node000C.html) 

