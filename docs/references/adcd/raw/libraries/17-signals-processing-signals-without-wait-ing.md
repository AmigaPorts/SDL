# 17 / Signals / Processing Signals Without Wait()ing


In some cases an application may need to process signals but cannot go to
sleep to wait for them.  For example, a compiler might want to check to
see if the user hit Control-C, but it can't to go to sleep to check for
the break because that will stop the compiler.  In this case, the task can
periodically check its own signal bits for the Ctrl-C break signal using
the Exec library function, [SetSignal()](../Includes_and_Autodocs_2._guide/node037E.html):


```c
    oldsignals = ULONG SetSignal(ULONG newsignals, ULONG signalmask);
```
Although [SetSignal()](../Includes_and_Autodocs_2._guide/node037E.html) can change a task's signal bits, it can also monitor
them.  The following fragment illustrates using SetSignal() to poll a
task's signal bits for a Ctrl-C break:


```c
    /* Get current state of signals */
    signals = SetSignal(0L, 0L);

    /* check for Ctrl-C */
    if (signals & SIGBREAKF_CTRL_C)
    {
        /* The Ctrl-C signal has been set, take care of processing it... */

        /* ...then clear the Ctrl-C signal */
        SetSignal(0L, SIGBREAKF_CTRL_C);
    }
```
If your task is waiting for signals, but is also waiting for other events
that have no signal bit (such as input characters from standard input),
you may need to use [SetSignal()](../Includes_and_Autodocs_2._guide/node037E.html).  In such cases, you must be careful not
to poll in a tight loop (also known as busy-waiting).  Busy-waiting hogs
CPU time and degrades the performance of other tasks.  One easy way around
this is for a task to sleep briefly within its polling loop by using the
timer.device, or the graphics function [WaitTOF()](../Libraries_Manual_guide/node0390.html), or (if the task is a
[Process](../Libraries_Manual_guide/node0287.html#line51)) the DOS library [Delay()](../Includes_and_Autodocs_2._guide/node0292.html)) or [WaitForChar()](../Includes_and_Autodocs_2._guide/node030E.html) functions.

For more information on signals, see the "[Exec Signals](../Libraries_Manual_guide/node02D1.html)" chapter of this
manual.

