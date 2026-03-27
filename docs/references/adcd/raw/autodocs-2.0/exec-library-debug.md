# exec.library/Debug



NAME

    Debug -- run the system debugger
SYNOPSIS

```c
    Debug(flags)
          D0

    void Debug(ULONG);
```
FUNCTION

```c
    This function calls the system debugger.  By default this debugger
    is "ROM-WACK".  Other debuggers are encouraged to take over this
    entry point (via [SetFunction()](../Includes_and_Autodocs_2._guide/node037C.html)) so that when an application calls
    Debug(), the alternative debugger will get control.  Currently a
    zero is passed to allow future expansion.
```
NOTE

```c
    The Debug() call may be made when the system is in a questionable
    state; if you have a [SetFunction()](../Includes_and_Autodocs_2._guide/node037C.html) patch, make few assumptions, be
    prepared for [Supervisor](../Includes_and_Autodocs_2._guide/node0386.html) mode, and be aware of differences in the
    Motorola stack frames on the 68000,'10,'20, and '30.
```
SEE ALSO

```c
    [SetFunction](../Includes_and_Autodocs_2._guide/node037C.html)
    your favorite debugger's manual
    the ROM-WACK chapter of the ROM Kernel Manual
```
