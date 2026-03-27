# cd.device/CD_GETGEOMETRY



   NAME

       CD_GETGEOMETRY -- return the geometry of the drive.
   FUNCTION

```c
       This command returns a full set of information about the
       layout of the drive. The information is returned in the
       [DriveGeometry](../Includes_and_Autodocs_3._guide/node0604.html#line134) structure pointed to by io_Data.
```
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_GETGEOMETRY
       io_Data         pointer to a [DriveGeometry](../Includes_and_Autodocs_3._guide/node0604.html#line134) structure
       io_Length       sizeof(struct DriveGeometry)
```
   IO REQUEST RESULT

```c
       io_Error  - 0 for success, or an error code as defined in
                   [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
       io_Actual - length of data transferred.
```
   SEE ALSO

```c
       CD_GETNUMTRACKS, [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)
```
