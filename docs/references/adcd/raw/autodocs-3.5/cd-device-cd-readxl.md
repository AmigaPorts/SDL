# cd.device/CD_READXL



   NAME

```c
       CD_READXL -- [Read](../Includes_and_Autodocs_3._guide/node01A0.html) from CD-ROM into memory via transfer list.
```
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_READXL
       io_Data         pointer to transfer list (i.e. struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *).
       io_Length       maximum transfer length (WORD multiple) or 0.
       io_Offset       byte offset from the start of the disk describing
                       where to read data from, must be a WORD multiple.
```
   RESULTS

```c
       io_Error        0 for success, or an error code as described in
                       [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
       io_Actual       if io_Error is 0, number of bytes actually transferred
```
   FUNCTION

```c
       This command starts reading data off the disk at the specified
       location and deposits it into memory according to the nodes in a
       transfer list.  The pointer to the list of transfer nodes is placed
       in io_Data.  If you have a non-circular transfer list, simply set
       io_Length to 0 (0 is special and means ignore io_Length) -- your
       transfer will end when your transfer list has been exhausted.  If you
       have a circular transfer list, the list will never end.  In this case,
       the transfer will terminate when io_Length bytes have been
       transferred.

       The fields in the [CDXL](../Includes_and_Autodocs_3._guide/node05E4.html#line225) node structure are:

       struct  [CDXL](../Includes_and_Autodocs_3._guide/node05E4.html#line225) {

           struct [MinNode](../Includes_and_Autodocs_3._guide/node062F.html#line30)  Node;         /* double linkage                */
           char           *Buffer;       /* data destination              */
           [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39)            Length;       /* must be even # bytes          */
           [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39)            Actual;       /* bytes transferred             */
           [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37)            IntData;      /* interrupt server data segment */
           VOID            (*IntCode)(); /* interrupt server code entry   */
           };

       The philosophy here is that you set up the buffers you want filled,
       create [CDXL](../Includes_and_Autodocs_3._guide/node05E4.html#line225) nodes describing the locations and sizes of these
       buffers, link all the nodes together in the order that you'd like
       (even make a circular list for animations), and execute the command.
       The data will be streamed into the appropriate buffers until the
       list has been exhausted, an entry with a Length of zero is
       encountered, io_Length bytes have been transferred (if io_Length is
       non-zero), or the command is aborted with [AbortIO()](../Includes_and_Autodocs_3._guide/node0574.html).

       If you fill in the (*IntCode)() field with a pointer to an interrupt
       routine, your routine will be called when the transfer for the node
       is complete.  Your code will be called before the driver proceeds to
       the next node.  The interrupt should follow the same rules as standard
       interrupts (see [AddIntServer](../Includes_and_Autodocs_3._guide/node01DA.html) of Exec autodocs).  Register A2 will
       contain a pointer to the node just completed.  You may manipulate the
       list from within the interrupt. Your code must be brief (this is an
       interrupt).  When returning from this interrupt, D0 should be cleared
       and an RTS instruction should be used to return.

       Servers are called with the following register conventions:

           D0 - scratch
           D1 - scratch

           A0 - scratch
           A1 - server is_Data pointer (scratch)
           A2 - pointer to [CDXL](../Includes_and_Autodocs_3._guide/node05E4.html#line225) node just completed

           A5 - jump vector register (scratch)

           all other registers must be preserved
```
   EXAMPLE

   NOTES

       Try to make sure that small buffers are not overused.  Each time
       a node is completed, an interrupt is generated.  If you find that
       your computer is acting sluggish, or the CD_READXL command is
       aborting, you are probably generating too many interrupts.  It is
       not efficient to have more than a few of these interrupts generated
       within a vertical blank.

       Unlike the READ command, the READXL command will not retry a sector
       if there is an error.  Since the READXL command's purpose is primarily
       for animations, data streaming is considered more important than the
       data itself.  An error will be returned in io_Error if a data error
       did occur.  This command will never drop to a lower speed in the event
       of an error.
   BUGS

   SEE ALSO

```c
       [CMD_READ](../Includes_and_Autodocs_3._guide/node057F.html), [CD_SEEK](../Includes_and_Autodocs_3._guide/node00B7.html), Autodocs - [AddIntServer](../Includes_and_Autodocs_3._guide/node01DA.html)
```
