# graphics.library/WaitTOF



NAME

    WaitTOF -- Wait for the top of the next video frame.
SYNOPSIS

```c
    WaitTOF()

    void WaitTOF( void );
```
FUNCTION

    Wait  for vertical blank to occur and all vertical blank
    interrupt routines to complete before returning to caller.
INPUTS

    none
RESULT

    Places this task on the TOF wait queue. When the vertical blank
    interupt comes around, the interrupt service routine will fire off
    signals to all the tasks doing WaitTOF. The highest priority task
    ready will get to run then.
BUGS

SEE ALSO

```c
    [exec.library/Wait()](../Includes_and_Autodocs_2._guide/node038A.html) [exec.library/Signal()](../Includes_and_Autodocs_2._guide/node0381.html)
```
