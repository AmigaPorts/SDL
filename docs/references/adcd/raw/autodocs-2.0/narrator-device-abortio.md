# narrator.device/AbortIO



NAME

    AbortIO - Abort an IO request
SYNOPSIS

```c
    AbortIO(IORequest)
               A1
```
FUNCTION

```c
    Exec library call to abort a specified READ or WRITE request.
    The [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) may be in the queue or currently active.  If
    currently active, the request is immediately stopped and then
    removed.
```
INPUTS

```c
    Pointer to the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block to be aborted.
```
RESULTS

```c
    io_Error field in the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block set to #IOERR_ABORTED.
```
SEE ALSO

