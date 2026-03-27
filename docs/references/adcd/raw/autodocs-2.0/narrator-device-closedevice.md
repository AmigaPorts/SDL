# narrator.device/CloseDevice



NAME

    CloseDevice - terminates access to the narrator device
SYNOPSIS

```c
    CloseDevice(IORequest)
                   A1
```
FUNCTION

```c
    Close invalidates the IO_UNIT and IO_DEVICE fields in the
    [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block, preventing subsequent IO until another
    [OpenDevice](../Includes_and_Autodocs_2._guide/node04C8.html).  CloseDevice also reduces the open count.  If
    the count goes to 0 and the expunge bit is set, the device
    is expunged.  If the open count goes to zero and the delayed
    expunge bit is not set, CloseDevice sets the expunge bit.
```
INPUTS

```c
    A valid [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block with its io_Message structure, and
    io_Device and io_Unit fields properly initialized.  These
    fields are initialized by [OpenDevice](../Includes_and_Autodocs_2._guide/node04C8.html).
```
RESULTS

```c
    CloseDevice invalidates the unit and device pointers in the
    [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block.
```
SEE ALSO

