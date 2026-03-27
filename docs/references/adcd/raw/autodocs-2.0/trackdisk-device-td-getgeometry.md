# trackdisk.device/TD_GETGEOMETRY



NAME
   TD_GETGEOMETRY -- return the geometry of the drive.

FUNCTION

```c
    This command returns a full set of information about the
    layout of the drive. The information is returned in the
    [DriveGeometry](../Includes_and_Autodocs_2._guide/node005B.html#line136) structure pointed to by io_Data.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      TD_GETGEOMETRY
    io_Flags        0 or IOF_QUICK
    io_Data         Pointer to a [DriveGeometry](../Includes_and_Autodocs_2._guide/node005B.html#line136) structure
    io_Length       sizeof(struct DriveGeometry)
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](../Includes_and_Autodocs_2._guide/node005B.html)
```
NOTE

    This information may change when a disk in inserted when
    certain hardware is present.
SEE ALSO

```c
    [TD_GETDRIVETYPE](../Includes_and_Autodocs_2._guide/node0528.html), [TD_GETNUMTRACKS](../Includes_and_Autodocs_2._guide/node052A.html)
```
