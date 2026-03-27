# 22 / The Signal System / Signal Allocation


As mentioned above, a task assigns its own meaning to a particular signal.
Because certain system libraries may occasionally require the use of a
signal, there is a convention for signal allocation.  It is unwise ever to
make assumptions about which signals are actually in use.

Before a signal can be used, it must be allocated with the [AllocSignal()](../Includes_and_Autodocs_2._guide/node0333.html)
function.  When a signal is no longer needed, it should be freed for reuse
with [FreeSignal()](../Includes_and_Autodocs_2._guide/node0356.html).


```c
    BYTE AllocSignal( LONG signalNum );
    VOID FreeSignal( LONG signalNum );
```
[AllocSignal()](../Includes_and_Autodocs_2._guide/node0333.html) marks a signal as being in use and prevents the accidental
use of the same signal for more than one event.  You may ask for either a
specific signal number, or more commonly, you would pass -1 to request the
next available signal.  The state of the newly allocated signal is cleared
(ready for use).  Generally it is best to let the system assign you the
next free signal.  Of the 32 available signals, the lower 16 are reserved
for system use.  This leaves the upper 16 signals free for application
programs to allocate.  Other subsystems that you may call depend on
AllocSignal().

The following C example asks for the next free signal to be allocated for
its use:


```c
    if (-1 == (signal = AllocSignal(-1)))
        printf("no signal bits available\n");
    else
        {
        printf("allocated signal number %ld\n", signal);
        /* Other code could go here */
        FreeSignal(signal)
        }
```
The value returned by [AllocSignal()](../Includes_and_Autodocs_2._guide/node0333.html) is a signal bit number. This value
cannot be used directly in calls to signal-related functions without first
being converted to a mask:


```c
    mask = 1L << signal;
```
It is important to realize that signal bit allocation is relevant only to
the running task.  You cannot allocate a signal from another task.  Note
that functions which create a signal [MsgPort](../Libraries_Manual_guide/node02EB.html#line12) will allocate a signal from
the task that calls the function.  Such functions include [OpenWindow()](../Libraries_Manual_guide/node0103.html),
[CreatePort()](../Libraries_Manual_guide/node02EC.html), and [CreateMsgPort()](../Libraries_Manual_guide/node02EC.html#line39).  For this reason, only the creating
task may [Wait()](../Libraries_Manual_guide/node02D4.html) (directly or indirectly) on the MsgPort's signal.
Functions which call Wait() include [DoIO()](../Libraries_Manual_guide/node029F.html#line8), [WaitIO()](../Libraries_Manual_guide/node02A0.html#line48) and [WaitPort()](../Libraries_Manual_guide/node02F1.html#line9).

