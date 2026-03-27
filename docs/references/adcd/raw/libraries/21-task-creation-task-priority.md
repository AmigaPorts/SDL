# 21 / Task Creation / Task Priority


A task's priority indicates its importance relative to other tasks.
Higher-priority tasks receive the processor before lower-priority tasks
do.  Task priority is stored as a signed number ranging from -128 to +127.
Higher priorities are represented by more positive values; zero is
considered the neutral priority.  Normally, system tasks execute somewhere
in the range of +20 to -20, and most application tasks execute at
priority 0.

It is not wise to needlessly raise a task's priority.  Sometimes it may be
necessary to carefully select a priority so that the task can properly
interact with various system tasks.  The [SetTaskPri()](../Libraries_Manual_guide/node02D0.html#line32) Exec function is
provided for this purpose.

