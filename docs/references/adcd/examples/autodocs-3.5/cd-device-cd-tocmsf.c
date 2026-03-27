/* Source: ADCD 2.1
 * Section: cd-device-cd-tocmsf
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-tocmsf.md
 */

       This command returns the table of contents of the disk currently in
       the drive.  The table of contents consists of up to 100 entries.
       Entry zero is summary information describing the number of tracks
       and the total number of minutes on the disk.  Entries 1 through N
       contain information about each individual track.  All position
       information will be in MSF format.

       The io_Data field points to an array of CDTOC structures to receive
       the TOC data.

       The io_Length field specifies the total number of entries to be
       fetched.  The array pointed to by io_Data must be at least this many
       elements in size.

       The io_Offset field specifies the entry number at which to start
       copying TOC data into *io_Data.

       Entry zero (the summary entry) contains the following:

       struct [TOCSummary](../Includes_and_Autodocs_3._guide/node05E4.html#line248) {

           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        FirstTrack;    /* First track on disk (always 1)   */
           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        LastTrack;     /* Last track on disk               */
           union LSNMSF LeadOut;       /* Beginning of lead-out track      */
           };

       Track entries (entries 1 through number of tracks) contain:

       struct [TOCEntry](../Includes_and_Autodocs_3._guide/node05E4.html#line256) {

           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        CtlAdr;        /* Q-Code info                  */
           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        Track;         /* Track number                 */
           union LSNMSF Position;      /* Start position of this track */
           };

       CDTOC is described as a union between these two structures:

       union CDTOC {

           struct [TOCSummary](../Includes_and_Autodocs_3._guide/node05E4.html#line248) Summary;  /* First entry is summary info.  */
           struct [TOCEntry](../Includes_and_Autodocs_3._guide/node05E4.html#line256)   Entry;    /* Entries 1-N are track entries */
           };
