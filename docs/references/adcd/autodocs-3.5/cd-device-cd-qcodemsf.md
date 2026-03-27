---
title: cd.device/CD_QCODEMSF
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-qcodemsf
functions: [CheckIO, OpenDevice, SendIO]
libraries: [exec.library]
---

# cd.device/CD_QCODEMSF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_QCODEMSF -- Report current disk position.
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_QCODEMSF
       io_Data         pointer to [QCode](autodocs-3.5/include-devices-cd-h.md) structure
       io_Length       0 - MUST be zero (for future compatability)
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```
   FUNCTION

```c
       This command reports current subcode Q channel time information.  This
       command only returns data when CD Audio is playing (or paused).  At
       any other time, an error is returned.  The Q-Code packet consists of:

       struct [QCode](autodocs-3.5/include-devices-cd-h.md) {

           [UBYTE](autodocs-3.5/include-exec-types-h.md)        CtlAdr;        /* Data type / [QCode](autodocs-3.5/include-devices-cd-h.md) type           */
           [UBYTE](autodocs-3.5/include-exec-types-h.md)        Track;         /* Track number                     */
           [UBYTE](autodocs-3.5/include-exec-types-h.md)        Index;         /* Track subindex number            */
           [UBYTE](autodocs-3.5/include-exec-types-h.md)        Zero;          /* The "Zero" byte of Q-Code packet */
           union LSNMSF TrackPosition; /* Position from start of track     */
           union LSNMSF DiskPosition;  /* Position from start of disk      */
           };
```
   EXAMPLE


```c
       struct [QCode](autodocs-3.5/include-devices-cd-h.md) qcode;

       ior->io_Command = CD_QCODEMSF;  /* Retrieve TOC information */
       ior->io_Length  = 0;            /* MUST be zero             */
       ior->io_Data    = (APTR)qcode;  /* Here's where we want it  */
       [DoIO](autodocs-3.5/exec-library-doio-2.md) (ior);

       if (!ior->io_Error) {           /* Command succeeded        */

           printf("Current position is: %02d:%02d:%02dn",
               qcode.DiskPosition.MSF.Minute,
               qcode.DiskPosition.MSF.Second,
               qcode.DiskPosition.MSF.Frame);
           }
```
   NOTES

```c
       This function may not return immediately.  It may take several frames
       to pass by before a valid Q-Code packet can be returned.  Use [SendIO()](autodocs-3.5/exec-library-sendio-2.md)
       and [CheckIO()](autodocs-3.5/exec-library-checkio-2.md) if response time is critical, and the information is
       not.
```
   BUGS

   SEE ALSO

```c
       [CD_PLAYMSF](autodocs-3.5/cd-device-cd-playmsf.md), [CD_PLAYLSN](autodocs-3.5/cd-device-cd-playlsn.md), [CD_PLAYTRACK](autodocs-3.5/cd-device-cd-playtrack.md), [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```

---

## See Also

- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
