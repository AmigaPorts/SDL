/* Source: ADCD 2.1
 * Section: cd-device-cd-toclsn
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-toclsn.md
 */

       union CDTOC tocarray[100];

       ior->io_Command = CD_TOCLSN;        /* Retrieve TOC information */
       ior->io_Offset  = 0;                /* Start with summary info  */
       ior->io_Length  = 100;              /* Max 99 tracks + summary  */
       ior->io_Data    = (APTR)tocarray;   /* Here's where we want it  */
       [DoIO](../Includes_and_Autodocs_3._guide/node0204.html) (ior);

       if (!ior->io_Error) {               /* Command succeeded        */

           firsttrack   = tocarray[0].Summary.FirstTrack;
           lasttrack    = tocarray[0].Summary.LastTrack;
           totalsectors = tocarray[0].Summary.LeadOut.LSN -
                          tocarray[1].Entry.Position.LSN;
           }
