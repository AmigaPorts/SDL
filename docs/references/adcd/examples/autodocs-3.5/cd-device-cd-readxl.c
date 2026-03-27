/* Source: ADCD 2.1
 * Section: cd-device-cd-readxl
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-readxl.md
 */

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
