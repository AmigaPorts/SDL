# trackdisk.device/TD_GETNUMTRACKS



NAME

    TD_GETNUMTRACKS -- return the number of tracks for the type of disk
                       drive for the unit that was opened.
FUNCTION

    This command returns the number of tracks that are available
    on the disk unit.
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      TD_GETNUMTRACKS
    io_Flags        0 or IOF_QUICK
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](../Includes_and_Autodocs_2._guide/node005B.html)
    io_Actual - if io_Error is 0 this contains the drive type connected to
                this unit.
```
SEE ALSO

```c
    [TD_GETDRIVETYPE](../Includes_and_Autodocs_2._guide/node0528.html)
```
