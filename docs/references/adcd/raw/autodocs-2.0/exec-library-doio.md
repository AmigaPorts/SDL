# exec.library/DoIO



NAME

    DoIO -- perform an I/O command and wait for completion
SYNOPSIS

```c
    error = DoIO(iORequest)
    D0           A1

    BYTE DoIO(struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *);
```
FUNCTION

```c
    This function requests a device driver to perform the I/O command
    specified in the I/O request.  This function will always wait until
    the I/O request is fully complete.

    DoIO() handles all the details, including Quick I/O, waiting for
    the request, and removing the reply message, etc..
```
IMPLEMENTATION

```c
    This function first tries to complete the IO via the "Quick I/O"
    mechanism.  The io_Flags field is always set to IOF_QUICK (0x01)
    before the internal device call.

    The LN_TYPE field is used internally to flag completion.  Active
    requests have type NT_MESSAGE.  Requests that have been replied
    have type NT_REPLYMSG.  It is illegal to start IO using a
    still active [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19), or a request with type NT_REPLYMSG.
```
INPUTS

```c
    iORequest - pointer to an [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) initialized by [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
```
RESULTS

```c
    error - a sign-extended copy of the io_Error field of the
            [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19).  Most device commands require that the error
            return be checked.
```
SEE ALSO

```c
    [SendIO](../Includes_and_Autodocs_2._guide/node037A.html), [CheckIO](../Includes_and_Autodocs_2._guide/node033E.html), [WaitIO](../Includes_and_Autodocs_2._guide/node038B.html), [AbortIO](../Includes_and_Autodocs_2._guide/node04F7.html), [amiga.lib/BeginIO](../Includes_and_Autodocs_2._guide/node04CB.html)
```
