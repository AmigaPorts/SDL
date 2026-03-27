---
title: cd.device/CD_PLAYTRACK
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-playtrack
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_PLAYTRACK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_PLAYTRACK -- Play one or more tracks of CD audio.
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_PLAYTRACK
       io_Data         NULL
       io_Length       number of tracks to play
       io_Offset       start playing at beginning of this track
```
   RESULTS
```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```
   FUNCTION

```c
       This command causes the drive to play the specified audio track(s).
       The command will return when the audio has completed.

       io_Offset specifies the track number (starting from 1).

       io_Length specifies the number of tracks to play (0 is invalid).
```
   EXAMPLE


```c
       ior->io_Command = CD_PLAYTRACK;    /* Play audio tracks     */
       ior->io_Offset  = STARTTRACK;      /* Start with this track */
       ior->io_Length  = 3;               /* Play three tracks     */
       DoIO(ior);
```
   NOTES


       PLAY commands are asynchronous with many other CD commands.
       Using a separate I/O request, other commands can be sent to the device
       that can change the behavior of the PLAY command.
   BUGS

   SEE ALSO

```c
       [CD_PLAYMSF](autodocs-3.5/cd-device-cd-playmsf.md), [CD_PLAYLSN](autodocs-3.5/cd-device-cd-playlsn.md), [CD_PAUSE](autodocs-3.5/cd-device-cd-pause.md), [CD_SEARCH](autodocs-3.5/cd-device-cd-search.md), [CD_ATTENUATE](autodocs-3.5/cd-device-cd-attenuate.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
