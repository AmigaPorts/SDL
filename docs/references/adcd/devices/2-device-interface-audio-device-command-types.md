---
title: 2 / Device Interface / Audio Device Command Types
manual: devices
chapter: devices
section: 2-device-interface-audio-device-command-types
functions: []
libraries: []
---

# 2 / Device Interface / Audio Device Command Types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Commands for audio use can be divided into two categories:
allocation/arbitration commands and hardware control commands.

There are four allocation/arbitration commands.  These do not actually
produce any sound.  Instead they manage and arbitrate the audio resources
for the many tasks that may be using audio in the Amiga's multitasking
environment.


```c
    [ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md)   - Reserves an audio channel for your program to use.
    [ADCMD_FREE](devices/2-allocation-and-arbitration-commands-adcmd-free.md)       - Frees an audio channel.
    [ADCMD_SETPREC](devices/2-allocation-and-arbitration-commands-adcmd-setprec.md)    - Changes the precedence of a sound in progress.
    [ADCMD_LOCK](devices/2-allocation-and-arbitration-commands-adcmd-lock.md)       - Tells if a channel has been stolen from you.
```
The hardware control commands are used to set up, start, and stop sounds
on the audio device:


```c
    [CMD_WRITE](devices/2-hardware-control-commands-cmd-write.md)        - The main command.  Starts a sound playing.
    [ADCMD_FINISH](devices/2-hardware-control-commands-adcmd-finish.md)     - Aborts a sound in progress.
    [ADCMD_PERVOL](devices/2-hardware-control-commands-adcmd-pervol.md)     - Changes the period (speed) and volume of a sound
                        in progress.
    [CMD_FLUSH](devices/2-hardware-control-commands-cmd-flush.md)        - Clears the audio channels.
    [CMD_RESET](devices/2-hardware-control-commands-cmd-reset.md)        - Resets and initializes the audio device.
    [ADCMD_WAITCYCLE](devices/2-hardware-control-commands-adcmd-waitcycle.md)  - Signals you when a cycle finishes.
    [CMD_STOP](devices/2-hardware-control-commands-cmd-stop.md)         - Temporarily stops a channel from playing.
    [CMD_START](devices/2-hardware-control-commands-cmd-start.md)        - Restarts an audio channel that was stopped.
    [CMD_READ](devices/2-hardware-control-commands-cmd-read.md)         - Returns a pointer to the current IOAudio request.
```
