# exec.library/OpenDevice



NAME

    OpenDevice -- gain access to a device
SYNOPSIS

```c
    error = OpenDevice(devName, unitNumber, iORequest, flags)
    D0                 A0       D0          A1         D1

    BYTE OpenDevice(STRPTR,ULONG,struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *,ULONG);
```
FUNCTION

```c
    This function opens the named device/unit and initializes the given
    I/O request block.  Specific documentation on opening procedures
    may come with certain devices.

    The device may exist in memory, or on disk; this is transparent to
    the OpenDevice caller.

    A full path name for the device name is legitimate.  For example
    "test:devs/fred.device".  This allows the use of custom devices
    without requiring the user to copy the device into the system's
    DEVS: directory.
```
NOTES

```c
    All calls to OpenDevice should have matching calls to CloseDevice!

    Devices on disk cannot be opened until after DOS has been
    started.

    As of V36 tasks can safely call OpenDevice, though DOS may open
    system requesters (e.g., asking the user to insert the Workbench
    disk if DEVS: is not online).  You must call this function from a
    DOS [Process](../Includes_and_Autodocs_2._guide/node0078.html#line38) if you want to turn off DOS requesters.
```
INPUTS

    devName - requested device name

    unitNumber - the unit number to open on that device.  The format of
            the unit number is device specific.  If the device does
            not have separate units, send a zero.

    iORequest - the I/O request block to be returned with
            appropriate fields initialized.

    flags - additional driver specific information.  This is sometimes
            used to request opening a device with exclusive access.
RESULTS

```c
    error - Returns a sign-extended copy of the io_Error field
            of the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19).  Zero if successful, else an error code
            is returned.
```
BUGS

```c
    AmigaDOS file names are not case sensitive, but Exec lists are.  If
    the library name is specified in a different case than it exists on
    disk, unexpected results may occur.

    Prior to V36, tasks could not make OpenDevice calls requiring disk
    access (since tasks are not allowed to make dos.library calls).
    Now OpenDevice is protected from tasks.
```
SEE ALSO

```c
    [CloseDevice](../Includes_and_Autodocs_2._guide/node04CC.html), [DoIO](../Includes_and_Autodocs_2._guide/node034B.html), [SendIO](../Includes_and_Autodocs_2._guide/node037A.html), [CheckIO](../Includes_and_Autodocs_2._guide/node033E.html), [AbortIO](../Includes_and_Autodocs_2._guide/node04F7.html), [WaitIO](../Includes_and_Autodocs_2._guide/node038B.html)
```
