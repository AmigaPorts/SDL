# timer.device/TR_SETSYSTIME



NAME

    TR_SETSYSTIME -- Set the system time.
FUNCTION

    Set the system idea of what time it is.  The system starts out
    at time "zero" so it is safe to set it forward to the real
    time.  However, care should be taken when setting the time
    backwards.  System time is generally expected to monotonically
    increasing.
TIMER REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       preset by timer in [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by timer in [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      [TR_GETSYSTIME](../Includes_and_Autodocs_2._guide/node04FE.html)
    io_Flags        IOF_QUICK permitted
    tr_time         a [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structure with the current system
                        time
```
RESULTS

    tr_time         will contain junk
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    [timer.device/TR_GETSYSTIME](../Includes_and_Autodocs_2._guide/node04FE.html),
    [timer.device/GetSysTime()](../Includes_and_Autodocs_2._guide/node04FA.html),
```
BUGS

