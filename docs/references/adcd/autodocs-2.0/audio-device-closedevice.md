---
title: audio.device/CloseDevice
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-closedevice
functions: []
libraries: []
---

# audio.device/CloseDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CloseDevice - terminate access to the audio device
SYNOPSIS

```c
    CloseDevice(iORequest);
                    A1
```
FUNCTION

```c
    The CloseDevice routine notifies the audio device that it will no
    longer be used.  It takes an I/O audio request block (IOAudio) and
    clears the device pointer (io_Device).  If there are any channels
    allocated with the same allocation key (ioa_AllocKey), CloseDevice
    frees (ADCMD_FREE) them. CloseDevice decrements the open count, and if
    it falls to zero and an expunge (Expunge) is pending, the device is
    expunged.
```
INPUTS

```c
    iORequest   - pointer to audio request block (struct IOAudio)
            io_Device   - pointer to device node, must be set by (or
                          copied from I/O block set by) open (OpenDevice)
            io_Unit     - bit map of channels to free (ADCMD_FREE) (bits 0
                          thru 3 correspond to channels 0 thru 3)
            ioa_AllocKey- allocation key, used to free channels
```
OUTPUTS

```c
    iORequest - pointer to audio request block (struct IOAudio)
            io_Device   - set to -1
            io_Unit     - set to zero
```
