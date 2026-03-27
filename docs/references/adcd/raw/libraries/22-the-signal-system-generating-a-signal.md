# 22 / The Signal System / Generating a Signal


Signals may be generated from both tasks and system interrupts with the
[Signal()](../Includes_and_Autodocs_2._guide/node0381.html) function.


```c
    VOID Signal( struct Task *task, ULONG signalSet );
```
For example [Signal](../Includes_and_Autodocs_2._guide/node0381.html)(tc,mask) would signal the task with the specified mask
signals.  More than one signal can be specified in the mask.  The
following example code illustrates [Wait()](../Libraries_Manual_guide/node02D4.html) and Signal().


```c
     [signals.c](../Libraries_Manual_guide/node058E.html) 
```
