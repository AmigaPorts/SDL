# trackdisk.device/TD_CHANGESTATE



NAME

    TD_CHANGESTATE -- check if a disk is currently in a drive.
FUNCTION

    This command checks to see if there is currently a disk in a drive.
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      TD_CHANGESTATE
    io_Flags        0 or IOF_QUICK
```
IO REQUEST RESULT

```c
    io_Error  - 0 for success, or an error code as defined in
                [<devices/trackdisk.h>](../Includes_and_Autodocs_2._guide/node005B.html)
    io_Actual - if io_Error is 0, this tells you whether a disk is in
                the drive. 0 means there is a disk, while anything else
                indicates there is no disk.
```
