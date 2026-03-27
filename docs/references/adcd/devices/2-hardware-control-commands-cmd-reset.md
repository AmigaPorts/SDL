---
title: 2 / Hardware Control Commands / CMD_RESET
manual: devices
chapter: devices
section: 2-hardware-control-commands-cmd-reset
functions: []
libraries: []
---

# 2 / Hardware Control Commands / CMD_RESET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[CMD_RESET](autodocs-2.0/audio-device-cmd-reset.md) restores all the audio hardware registers. It clears the attach
bits, restores the audio interrupt vectors if the programmer has changed
them, and performs the [CMD_FLUSH](devices/2-hardware-control-commands-cmd-flush.md) command to cancel all requests to the
channels. CMD_RESET also unstops channels that have had a [CMD_STOP](devices/2-hardware-control-commands-cmd-stop.md)
performed on them. [CMD_RESET](devices/2-hardware-control-commands-cmd-reset.md) does not unlock channels that have been
locked by [ADCMD_LOCK](devices/2-allocation-and-arbitration-commands-adcmd-lock.md).

