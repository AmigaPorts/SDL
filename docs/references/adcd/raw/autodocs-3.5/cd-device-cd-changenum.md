# cd.device/CD_CHANGENUM



   NAME

       CD_CHANGENUM -- return the current value of the disk-change counter.
   FUNCTION

       This command returns the current value of the disk-change counter
       The disk change counter is incremented each time a disk is inserted
       or removed from the cd unit.
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_CHANGENUM
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
       io_Actual - if io_Error is 0, this contains the current value of the
                   disk-change counter.
```
