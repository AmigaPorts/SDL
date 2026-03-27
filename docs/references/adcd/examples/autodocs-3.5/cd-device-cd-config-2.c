/* Source: ADCD 2.1
 * Section: cd-device-cd-config
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-config.md
 */

       /* Configure ReadXL for double-speed reading and turn off ECC when */
       /* the ReadXL command is used.                                     */

       struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) ConfigList[] = {

           { TAGCD_READXLSPEED, 150 },
           { TAGCD_XLECC,       0   },
           { TAG_END,           0   }
           };

           ior->io_Command = CD_CONFIG;
           ior->io_Data    = (APTR)&ConfigList;
           ior->io_Length  = 0;
           DoIO(ior);

           if (ior->io_Error) printf("Could not be configuredn");
