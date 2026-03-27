# dos.library/Delay



NAME

    Delay -- Delay a process for a specified time
SYNOPSIS

```c
    Delay( ticks )
           D1

    void Delay(ULONG)
```
FUNCTION

```c
    The argument 'ticks' specifies how many ticks (50 per second) to
    wait before returning control.
```
INPUTS

    ticks - integer
BUGS

```c
    Due to a bug in the timer.device in V1.2/V1.3, specifying a timeout
    of zero for Delay() can cause the unreliable timer & floppy disk
    operation.  This is fixed in V36 and later.
```
SEE ALSO

