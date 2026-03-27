/* Source: ADCD 2.1
 * Section: cd-device-cd-qcodemsf
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-qcodemsf.md
 */

       struct [QCode](../Includes_and_Autodocs_3._guide/node05E4.html#line284) qcode;

       ior->io_Command = CD_QCODEMSF;  /* Retrieve TOC information */
       ior->io_Length  = 0;            /* MUST be zero             */
       ior->io_Data    = (APTR)qcode;  /* Here's where we want it  */
       [DoIO](../Includes_and_Autodocs_3._guide/node0204.html) (ior);

       if (!ior->io_Error) {           /* Command succeeded        */

           printf("Current position is: %02d:%02d:%02dn",
               qcode.DiskPosition.MSF.Minute,
               qcode.DiskPosition.MSF.Second,
               qcode.DiskPosition.MSF.Frame);
           }
