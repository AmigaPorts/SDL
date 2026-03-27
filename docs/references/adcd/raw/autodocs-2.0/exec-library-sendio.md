# exec.library/SendIO



NAME

    SendIO -- initiate an I/O command
SYNOPSIS

```c
    SendIO(iORequest)
           A1

    void SendIO(struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *);
```
FUNCTION

```c
    This function requests the device driver start processing the given
    I/O request.  The device will return control without waiting for
    the I/O to complete.

    The io_Flags field of the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) will be set to zero before the
    request is sent.  See [BeginIO()](../Includes_and_Autodocs_2._guide/node04CB.html) for more details.
```
INPUTS

```c
    iORequest - pointer to an I/O request, or a device specific
                extended [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19).
```
SEE ALSO

```c
    [DoIO](../Includes_and_Autodocs_2._guide/node034B.html), [CheckIO](../Includes_and_Autodocs_2._guide/node033E.html), [WaitIO](../Includes_and_Autodocs_2._guide/node038B.html), [AbortIO](../Includes_and_Autodocs_2._guide/node04F7.html)
```
