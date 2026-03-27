# trackdisk.device/TD_SEEK



NAME

    TD_SEEK/ETD_SEEK -- control positioning of the drive heads.
FUNCTION

```c
    These commands are currently provided for internal diagnostics,
    disk repair, and head cleaning only.

    TD_SEEK and ETD_SEEK move the drive heads to the track specified. The
    io_Offset field should be set to the (byte) offset to which the seek is
    to occur. TD_SEEK and ETD_SEEK do not verify their position until the
    next read. That is, they only move the heads; they do not actually read
    any data.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      TD_SEEK or ETD_SEEK
    io_Flags        0 or IOF_QUICK
    io_Offset       byte offset from the start of the disk describing
                    where to move the head to.
    iotd_Count      (ETD_SEEK only) maximum allowable change counter
                    value.
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](../Includes_and_Autodocs_2._guide/node005B.html)
```
