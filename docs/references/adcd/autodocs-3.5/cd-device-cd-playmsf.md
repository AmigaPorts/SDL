---
title: cd.device/CD_PLAYMSF
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-playmsf
functions: [AbortIO, DoIO, OpenDevice, SendIO]
libraries: [exec.library, timer.device]
---

# cd.device/CD_PLAYMSF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
        CD_PLAYMSF -- Play a selected portion of CD audio (MSF form).
```
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_PLAYMSF
       io_Data         NULL
       io_Length       length of play
       io_Offset       starting position
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```
   FUNCTION

```c
       This command causes the drive to start playing CD audio from the
       specified position until the specified length has passed.

       io_Offset specifies the starting position.  io_Length contains
       the amount of time to play.  All data is specified in MSF format.

       A [DoIO()](autodocs-3.5/exec-library-doio-2.md) will not return until the requested number of sectors
       have been played.  A [SendIO()](autodocs-3.5/exec-library-sendio-2.md) will return as soon as the PLAY
       has been started.  At this time other commands can be sent (like
       CD_PAUSE).  To stop a play before the specified length has been
       reached, use [AbortIO()](autodocs-3.5/timer-device-abortio-2.md).
```
   EXAMPLE

```c
       /* Play two minutes, ten seconds of audio starting at 20 minutes, */
       /* 58 seconds, and 10 frames.                                     */

       ior->io_Command = CD_PLAYMSF;   /* Play CD audio          */
       ior->io_Offset  = 0x00143A0A;   /* $14=20, $3A=58, $0A=10 */
       ior->io_Length  = 0x00020A00;   /* $02=02, $0A=10, $00=00 */
       [DoIO](autodocs-3.5/exec-library-doio-2.md) (ior);
```
   NOTES

   BUGS

   SEE ALSO

```c
       [CD_PLAYTRACK](autodocs-3.5/cd-device-cd-playtrack.md), [CD_PAUSE](autodocs-3.5/cd-device-cd-pause.md), [CD_SEARCH](autodocs-3.5/cd-device-cd-search.md), [CD_ATTENUATE](autodocs-3.5/cd-device-cd-attenuate.md)
```

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
