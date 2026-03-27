---
title: cd.device/CD_TOCMSF
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-tocmsf
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_TOCMSF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       CD_TOCMSF -- Return table of contents information from CD (MSF form).
```
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_TOCMSF
       io_Data         pointer to array where TOC is to be stored
       io_Length       number of CDTOC entries to be fetched
       io_Offset       entry to begin at (entry 0 is summary information)
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
       io_Actual       Actual number of entries copied
```
   FUNCTION


```c
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

       struct [TOCSummary](autodocs-3.5/include-devices-cd-h.md) {

           [UBYTE](autodocs-3.5/include-exec-types-h.md)        FirstTrack;    /* First track on disk (always 1)   */
           [UBYTE](autodocs-3.5/include-exec-types-h.md)        LastTrack;     /* Last track on disk               */
           union LSNMSF LeadOut;       /* Beginning of lead-out track      */
           };

       Track entries (entries 1 through number of tracks) contain:

       struct [TOCEntry](autodocs-3.5/include-devices-cd-h.md) {

           [UBYTE](autodocs-3.5/include-exec-types-h.md)        CtlAdr;        /* Q-Code info                  */
           [UBYTE](autodocs-3.5/include-exec-types-h.md)        Track;         /* Track number                 */
           union LSNMSF Position;      /* Start position of this track */
           };

       CDTOC is described as a union between these two structures:

       union CDTOC {

           struct [TOCSummary](autodocs-3.5/include-devices-cd-h.md) Summary;  /* First entry is summary info.  */
           struct [TOCEntry](autodocs-3.5/include-devices-cd-h.md)   Entry;    /* Entries 1-N are track entries */
           };
```
   EXAMPLE

   NOTES

   BUGS

   SEE ALSO

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
