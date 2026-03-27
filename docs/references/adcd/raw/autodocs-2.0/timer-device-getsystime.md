# timer.device/GetSysTime



NAME

```c
    GetSysTime -- Get the system time. (V36)
```
SYNOPSIS

```c
    GetSysTime( Dest )
                A0

    void GetSysTime( struct [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) * );
```
FUNCTION

```c
    Ask the system what time it is.  The system time starts off at
    zero at power on, but may be initialized via the [TR_SETSYSTIME](../Includes_and_Autodocs_2._guide/node04FF.html)
    timer.device command.

    System time is monotonocally increasing and guarenteed to be
    unique (except when the system time is set back).

    A0 will be left unchanged.

    This function is less expensive to use than the [TR_GETSYSTIME](../Includes_and_Autodocs_2._guide/node04FE.html)
    [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19).
```
INPUTS

```c
    Dest -- pointer to a [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structure to hold the system time.
```
RESULTS

```c
    Dest -- the [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structure will contain the system time.
```
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    [timer.device/TR_GETSYSTIME](../Includes_and_Autodocs_2._guide/node04FE.html),
    [timer.device/TR_SETSYSTIME](../Includes_and_Autodocs_2._guide/node04FF.html),
```
BUGS

