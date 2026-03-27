/* Source: ADCD 2.1
 * Section: cd-device-cd-info
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-info.md
 */

       struct [CDInfo](../Includes_and_Autodocs_3._guide/node05E4.html#line132) Info;

       ior->io_Command = CD_INFO;               /* Retrieve drive info.    */
       ior->io_Data    = (APTR)Info;            /* Here's where we want it */
       ior->io_Length  = sizeof(struct CDInfo); /* Return whole structure  */
       DoIO(ior);

       if (!ior->io_Error) {                    /* Command succeeded       */

           if (Info.Status & CDSTSF_PLAYING) printf("Audio is playingn");
           else                              printf("Audio not playingn");
           }
