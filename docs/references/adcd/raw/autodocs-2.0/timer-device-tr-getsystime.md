# timer.device/TR_GETSYSTIME



NAME

    TR_GETSYSTIME -- get the system time.
FUNCTION

```c
    Ask the system what time it is.  The system time starts off at
    zero at power on, but may be initialized via the [TR_SETSYSTIME](../Includes_and_Autodocs_2._guide/node04FF.html)
    call.

    System time is monotonically increasing, and guaranteed to be
    unique (except when the system time is set backwards).
```
TIMER REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       preset by timer in [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by timer in [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      TR_GETSYSTIME
    io_Flags        IOF_QUICK permitted
```
RESULTS

```c
    tr_time         a [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structure with the current system
                        time
```
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    [timer.device/TR_SETSYSTIME](../Includes_and_Autodocs_2._guide/node04FF.html),
    [timer.device/GetSysTime()](../Includes_and_Autodocs_2._guide/node04FA.html),
```
BUGS

