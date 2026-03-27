# trackdisk.device/TD_CHANGENUM



NAME

    TD_CHANGENUM -- return the current value of the disk-change counter.
FUNCTION

```c
    This command returns the current value of the disk-change counter (as
    used by the enhanced commands). The disk change counter is incremented
    each time a disk is inserted or removed from the trackdisk unit.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      TD_CHANGENUM
    io_Flags        0 or IOF_QUICK
```
IO REQUEST RESULT

```c
    io_Error  - 0 for success, or an error code as defined in
                [<devices/trackdisk.h>](../Includes_and_Autodocs_2._guide/node005B.html)
    io_Actual - if io_Error is 0, this contains the current value of the
                disk-change counter.
```
