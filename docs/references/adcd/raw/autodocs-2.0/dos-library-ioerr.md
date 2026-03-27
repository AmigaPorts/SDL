# dos.library/IoErr



NAME

    IoErr -- Return extra information from the system
SYNOPSIS

```c
    error = IoErr()
      D0

    LONG IoErr(void)
```
FUNCTION

```c
    Most I/O routines return zero to indicate an error. When this
    happens (or whatever the defined error return for the routine)
    this routine may be called to determine more information. It is
    also used in some routines to pass back a secondary result.

    Note: there is no guarantee as to the value returned from IoErr()
    after a successful operation, unless to specified by the routine.
```
RESULTS

    error - integer
SEE ALSO

```c
    [Fault()](../Includes_and_Autodocs_2._guide/node02A1.html), [PrintFault()](../Includes_and_Autodocs_2._guide/node02DE.html), [SetIoErr()](../Includes_and_Autodocs_2._guide/node02F8.html)
```
