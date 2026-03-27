# cd.device/CD_TOCLSN



   NAME

```c
       CD_TOCLSN -- Return table of contents information from CD (LSN form).
```
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_TOCLSN
       io_Data         pointer to array where TOC is to be stored
       io_Length       number of CDTOC entries to be fetched
       io_Offset       entry to begin at (entry 0 is summary information)
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
       io_Actual       Actual number of entries copied
```
   FUNCTION


```c
       This command returns the table of contents of the disk currently in
       the drive.  The table of contents consists of up to 100 entries.
       Entry zero is summary information describing the number of tracks
       and the total number of minutes on the disk.  Entries 1 through N
       contain information about each individual track.  All position
       information will be in LSN format.

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
```
   EXAMPLE


```c
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
```
   NOTES


```c
       In the above example, the amount of data on the disk is calculated as
       being equal to the location of the lead-out track minus the start of
       the first track (which is never zero).
```
   BUGS

   SEE ALSO

