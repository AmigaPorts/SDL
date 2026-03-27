# amiga.lib/BeginIO



NAME

    BeginIO -- initiate asynchronous device I/O
SYNOPSIS

```c
    BeginIO(ioReq)

    VOID BeginIO(struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *);
```
FUNCTION

```c
    This function takes an [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19), and passes it directly to the
    "BeginIO" vector of the proper device.  This is equivalent to
    [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html), except that io_Flags is not cleared. A good understanding
    of Exec device I/O is required to properly use this function.

    This function does not wait for the I/O to complete.
```
INPUTS

```c
    ioReq - an initialized and opened [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) structure with the
            io_Flags field set to a reasonable value (set to 0 if you do
            not require io_Flags).
```
SEE ALSO

```c
    [exec.library/DoIO()](../Includes_and_Autodocs_2._guide/node034B.html), [exec.library/SendIO()](../Includes_and_Autodocs_2._guide/node037A.html), [exec.library/WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)
```
