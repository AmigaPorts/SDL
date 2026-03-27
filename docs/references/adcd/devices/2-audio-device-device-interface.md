---
title: 2 Audio Device / Device Interface
manual: devices
chapter: devices
section: 2-audio-device-device-interface
functions: []
libraries: []
---

# 2 Audio Device / Device Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The audio device operates like the other Amiga I/O devices.  To make
sound, you first open the audio device, then send I/O requests to it, and
then close it when finished.  See "[Introduction to Amiga System Devices](devices/1-introduction-to-amiga-system-devices-using-a-device.md)"
chapter for general information on device usage.

Audio device commands use an extended I/O request block named IOAudio to
send commands to the audio device.  This is the standard IORequest block
with some extra fields added at the end.

struct IOAudio
{
```c
    struct IORequest ioa_Request;/* I/O request block. See exec/io.h.    */
    WORD   ioa_AllocKey;       /* Alloc. key filled in by audio device   */
    UBYTE  *ioa_Data;          /* Pointer to a sample or allocation mask */
    ULONG  ioa_Length;         /* Length of sample or allocation mask.   */
    UWORD  ioa_Period;         /* Sample playback speed                  */
    UWORD  ioa_Volume;         /* Volume of sound                        */
    UWORD  ioa_Cycles;         /* # of times to play sample. 0=forever.  */
    struct Message ioa_WriteMsg;/* Filled in by device- usually not used */
```
};

See the include file devices/[audio.h](autodocs-2.0/includes-devices-audio-h.md) for the complete structure definition.

 [Opening The Audio Device](devices/2-device-interface-opening-the-audio-device.md) 	 [Audio And System I/O Functions](devices/2-device-interface-audio-and-system-i-o-functions.md) 
 [Audio Device Command Types](devices/2-device-interface-audio-device-command-types.md)      [Closing The Audio Device](devices/2-device-interface-closing-the-audio-device.md) 
 [Scope Of Audio Commands](devices/2-device-interface-scope-of-audio-commands.md) 

