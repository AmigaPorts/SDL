---
title: cd.device/CD_ATTENUATE
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-attenuate
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_ATTENUATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       CD_ATTENUATE -- Attenuate CD audio volume (immediately or gradually)
```
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_ATTENUATE
       io_Data         NULL
       io_Length       duration of volume fade in frames
       io_Offset       target volume level (0 - 0x7FFF) (-1 = status only)
```
   RESULTS

```c
       io_Error        Returns an error if drive does not support attenuation
       io_Actual       current volume level (fade may be monitored)
```
   FUNCTION

```c
       This command will ramp the CD audio volume up or down from its
       current value to the value contained in io_Offset.  The range is 0
       (silence) to 0x7FFF (full volume).  If -1 is specified as the target,
       the attenuation will not be modified; the current attenuation value
       will be returned in io_Actual.

       io_Length contains the duration of the fade.  In seconds, this is
       io_Length divided by the current frame rate (usually 75).

       Note that this command returns before the fade has completed.  Thus,
       once started, a fade cannot be aborted.  You can, however, send a
       new CD_ATTENUATE command, which will immediately override any fade
       currently in progress.  An io_Length of zero means attenuate
       immediately.

       If a gradual attenuation command is sent before the play command, the
       fade will begin as soon as the play command is sent.
```
   EXAMPLE

   NOTES

       This command has no effect on Amiga audio volume, only CD audio.

       If the drive does not support volume attenuation, but does support
       mute, a value of under $0800 should be considered mute, and equal
       to or above should be full volume.  If chunky attenuation is
       supported, the drive should do the best it can.  If the drive does
       not support volume attenuation at all, an error should be returned.
       Even if only mute is supported, if gradual attenuation is requested,
       the device should still emulate the fade command and mute based on
       the $0800 boundary.
   BUGS

   SEE ALSO

```c
       [CD_INFO](autodocs-3.5/cd-device-cd-info.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
