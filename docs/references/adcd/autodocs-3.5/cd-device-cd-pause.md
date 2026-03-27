---
title: cd.device/CD_PAUSE
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-pause
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_PAUSE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_PAUSE -- Pause or unPause play command.
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_PAUSE
       io_Data         NULL
       io_Length       pausemode : 1 = pause play; 0 = do not pause play;
       io_Offset       0
```
   RESULTS

       io_Actual - if io_Error is 0, this contains the previous pause state.
   FUNCTION

```c
       This command will place the CD in, or take the CD out of pause mode.
       The desired pause state is placed in io_Length.  This command only
       effects play commands.  When the audio is playing and the pausemode
       is set, this command will immediately pause the audio output
       suspending the play command until the play is unpaused.  When audio
       is not playing and the pausemode is set, this command will set the
       pause mode (having no immediate effect).  When a play command is
       submitted, the laser will seek to the appropriate position and pause
       at that spot.  The play command will be suspended until the play is
       unpaused (or the play is aborted).
```
   EXAMPLE

   NOTES

   BUGS

   SEE ALSO

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
