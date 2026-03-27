# sana2.device/CloseDevice


NAME

    CloseDevice -- Close the device.
SYNOPSIS

```c
    CloseDevice(Sana2Req)
                A1

    void CloseDevice(struct IOSana2Req *);
```
FUNCTION

```c
    This function is called by exec.library CloseDevice().

    This function performs whatever cleanup is required at device closes.

    Note that all IORequests MUST be complete before closing. If any are
    pending, your program must AbortIO() then WaitIO() each outstanding
    IORequest to complete them.
```
INPUTS

```c
    Sana2Req        - Pointer to IOSana2Req initialized by OpenDevice().
```
NOTES

SEE ALSO

```c
    exec.library/CloseDevice(), exec.library/OpenDevice()
```
BUGS

