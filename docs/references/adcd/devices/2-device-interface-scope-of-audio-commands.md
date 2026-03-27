---
title: 2 / Device Interface / Scope Of Audio Commands
manual: devices
chapter: devices
section: 2-device-interface-scope-of-audio-commands
functions: []
libraries: []
---

# 2 / Device Interface / Scope Of Audio Commands

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Most audio commands can operate on multiple channels.  The exceptions are
[ADCMD_WAITCYCLE](devices/2-hardware-control-commands-adcmd-waitcycle.md), [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) and [CMD_READ](autodocs-2.0/audio-device-cmd-read.md), which can only operate on one
channel at a time.  You specify the channel(s) that you want to use by
setting the appropriate bits in the [ioa_Request.io_Unit](devices/2-audio-device-device-interface.md) field of the
IOAudio block.  If you send a command for a channel that you do not own,
your command will be ignored.  For more details, see the section on
"[Allocation and Arbitration](devices/2-audio-device-allocation-and-arbitration-commands.md)" below.

