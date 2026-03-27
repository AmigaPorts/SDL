# timer.device/AbortIO



NAME

    AbortIO -- Remove an existing timer request.
SYNOPSIS

```c
    error = AbortIO( [timerequest](../Includes_and_Autodocs_2._guide/node0053.html#line36) )
    D0               A1

    LONG AbortIO( struct [timerequest](../Includes_and_Autodocs_2._guide/node0053.html#line36) * );
```
FUNCTION

    This is an exec.library call.

    This routine removes a timerquest from the timer.  It runs in
    the context of the caller.
INPUTS

```c
    [timerequest](../Includes_and_Autodocs_2._guide/node0053.html#line36) - the timer request to be aborted
```
RETURNS

    0  if the request was aborted, io_Error will also be set to
        IOERR_ABORTED.
    -1 otherwise
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    exec.library/AbortIO()
```
BUGS

