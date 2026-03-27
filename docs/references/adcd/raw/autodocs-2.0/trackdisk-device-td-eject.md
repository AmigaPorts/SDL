# trackdisk.device/TD_EJECT



NAME
   TD_EJECT -- eject the disk in the drive, if possible.

FUNCTION

    This command causes the drive to attempt to eject the disk in
    it, if any.  Note that the current trackdisk.device does not
    implement this command, but it might in the future, and other
    trackdisk-compatible drivers may implement this command.
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      TD_EJECT
    io_Flags        0 or IOF_QUICK
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](../Includes_and_Autodocs_2._guide/node005B.html)
```
