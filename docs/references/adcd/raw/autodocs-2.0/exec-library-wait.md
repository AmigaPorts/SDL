# exec.library/Wait



NAME

    Wait -- wait for one or more signals
SYNOPSIS

```c
    signals = Wait(signalSet)
    D0             D0

    ULONG Wait(ULONG);
```
FUNCTION

```c
    This function will cause the current task to suspend waiting for
    one or more signals.  When one or more of the specified signals
    occurs, the task will return to the ready state, and those signals
    will be cleared.

    If a signal occurred prior to calling Wait(), the wait condition will
    be immediately satisfied, and the task will continue to run without
    delay.
```
CAUTION

```c
    This function cannot be called while in supervisor mode or
    interrupts!  This function will break the action of a [Forbid()](../Includes_and_Autodocs_2._guide/node0353.html) or
    [Disable()](../Includes_and_Autodocs_2._guide/node034A.html) call.
```
INPUT

    signalSet - The set of signals for which to wait.
                Each bit represents a particular signal.
RESULTS

    signals - the set of signals that were active
