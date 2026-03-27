# cd.device/CD_REMCHANGEINT



   NAME

       CD_REMCHANGEINT -- remove a disk change software interrupt handler.
   FUNCTION

```c
       This command removes a disk change software interrupt added
       by a previous use of [CD_ADDCHANGEINT](../Includes_and_Autodocs_3._guide/node00A1.html).
```
   IO REQUEST INPUT

```c
       The same IO request used for [CD_ADDCHANGEINT](../Includes_and_Autodocs_3._guide/node00A1.html).

       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_REMCHANGEINT
       io_Length       sizeof(struct Interrupt)
       io_Data         pointer to [Interrupt](../Includes_and_Autodocs_3._guide/node061D.html#line21) structure
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
```
   SEE ALSO

```c
       [CD_ADDCHANGEINT](../Includes_and_Autodocs_3._guide/node00A1.html), [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
```
