# cd.device/CD_SEEK



   NAME

       CD_SEEK -- position laser at specified location.
   FUNCTION

       CD_SEEK moves the laser to the approximate position specified.  The
       io_Offset field should be set to the offset to which the head is
       to be positioned.
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_SEEK
       io_Offset       position where head is to be moved (always LSN format)
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
```
