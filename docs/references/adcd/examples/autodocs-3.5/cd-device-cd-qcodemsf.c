/* Source: ADCD 2.1
 * Section: cd-device-cd-qcodemsf
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-qcodemsf.md
 */

       This command reports current subcode Q channel time information.  This
       command only returns data when CD Audio is playing (or paused).  At
       any other time, an error is returned.  The Q-Code packet consists of:

       struct [QCode](../Includes_and_Autodocs_3._guide/node05E4.html#line284) {

           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        CtlAdr;        /* Data type / [QCode](../Includes_and_Autodocs_3._guide/node05E4.html#line284) type           */
           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        Track;         /* Track number                     */
           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        Index;         /* Track subindex number            */
           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        Zero;          /* The "Zero" byte of Q-Code packet */
           union LSNMSF TrackPosition; /* Position from start of track     */
           union LSNMSF DiskPosition;  /* Position from start of disk      */
           };
