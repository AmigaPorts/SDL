# cd.device/CD_CHANGESTATE



   NAME

       CD_CHANGESTATE -- check if a "valid" disk is currently in a drive.
   FUNCTION

       This command checks to see if there is a "valid" disk in a drive.
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_CHANGESTATE
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
       io_Actual - 0 means there is a disk while anything else indicates
                   there is no disk.
```
   NOTES

       A "valid" disk is a disk with a readable table of contents.
