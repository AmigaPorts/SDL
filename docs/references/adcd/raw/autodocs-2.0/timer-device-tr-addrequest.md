# timer.device/TR_ADDREQUEST



NAME

    TR_ADDREQUEST -- Submit a request to wait a period of time.
FUNCTION

```c
    Ask the timer to wait a specified amount of time before
    replying the [timerequest](../Includes_and_Autodocs_2._guide/node0053.html#line36).

    The message may be forced to finish early with an
    [AbortIO()/WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html) pair.
```
TIMER REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       preset by timer in [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by timer in [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      TR_ADDREQUEST
    io_Flags        IOF_QUICK permitted (but ignored)
    tr_time         a [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structure specifying how long the
                        device will wait before replying
```
RESULTS

    tr_time         will be zeroed
NOTES

```c
    This function may be called from interrupts.

    Previous to 2.0, the tr_time field was documented as containing
    junk when the [timerequest](../Includes_and_Autodocs_2._guide/node0053.html#line36) was returned.
```
SEE ALSO

```c
    [timer.device/AbortIO()](../Includes_and_Autodocs_2._guide/node04F7.html),
    [timer.device/TimeDelay()](../Includes_and_Autodocs_2._guide/node0169.html),
```
BUGS

