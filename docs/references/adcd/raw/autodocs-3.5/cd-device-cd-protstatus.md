# cd.device/CD_PROTSTATUS



   NAME

       CD_PROTSTATUS -- return whether the current disk is write-protected.
   FUNCTION

       This command is used to determine whether the current disk is
       write-protected.  Currently, this function always returns write-
       protected status.  If write-once CDs are made available at some point,
       this may change.
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_PROTSTATUS
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
       io_Actual - 0 means the disk is NOT write-protected, while any other
                   value indicates it is.
```
