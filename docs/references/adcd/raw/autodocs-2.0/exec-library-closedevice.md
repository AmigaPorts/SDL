# exec.library/CloseDevice



NAME

    CloseDevice -- conclude access to a device
SYNOPSIS

```c
    CloseDevice(iORequest)
                A1

    void CloseDevice(struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *);
```
FUNCTION

```c
    This function informs the device that access to a device/unit
    previously opened has been concluded.  The device may perform
    certain house-cleaning operations.

    The user must ensure that all outstanding IORequests have been
    returned before closing the device.  The [AbortIO](../Includes_and_Autodocs_2._guide/node04F7.html) function can kill
    any stragglers.

    After a close, the I/O request structure is free to be reused.
    Starting with V36 exec it is safe to CloseDevice() with an
    [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) that is either cleared to zeros, or failed to
    open.
```
INPUTS

    iORequest - pointer to an I/O request structure
SEE ALSO

```c
    [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
```
