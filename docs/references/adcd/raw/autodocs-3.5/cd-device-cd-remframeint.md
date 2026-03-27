# cd.device/CD_REMFRAMEINT



   NAME

       CD_REMFRAMEINT -- remove a CD-frame interrupt handler.
   IO REQUEST

```c
       The same IO request used for [CD_ADDFRAMEINT](../Includes_and_Autodocs_3._guide/node00A2.html).

       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_REMFRAMEINT
       io_Length       sizeof(struct Interrupt)
       io_Data         pointer to [Interrupt](../Includes_and_Autodocs_3._guide/node061D.html#line21) structure
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
```
   FUNCTION

```c
       This command removes a CD-frame software interrupt added
       by a previous use of [CD_ADDFRAMEINT](../Includes_and_Autodocs_3._guide/node00A2.html).
```
   BUGS

   SEE ALSO

```c
       [CD_ADDFRAMEINT](../Includes_and_Autodocs_3._guide/node00A2.html), [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
```
