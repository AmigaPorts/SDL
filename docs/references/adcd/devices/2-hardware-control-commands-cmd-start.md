---
title: 2 / Hardware Control Commands / CMD_START
manual: devices
chapter: devices
section: 2-hardware-control-commands-cmd-start
functions: []
libraries: []
---

# 2 / Hardware Control Commands / CMD_START

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[CMD_START](autodocs-2.0/audio-device-cmd-start.md) undoes the CMD_STOP command. Any cycles that were stopped by the
[CMD_STOP](devices/2-hardware-control-commands-cmd-stop.md) command are actually lost because of the impossibility of
determining exactly where the DMA ceased. If the [CMD_WRITE](devices/2-hardware-control-commands-cmd-write.md) command was
playing two cycles and the first one was playing when [CMD_STOP](devices/2-hardware-control-commands-cmd-stop.md) was issued,
the first one is lost and the second one will be played.

This command is also useful when you are playing the same wave form with
the same period out of multiple channels. If the channels are stopped when
the [CMD_WRITE](devices/2-hardware-control-commands-cmd-write.md) commands are issued, CMD_START exactly synchronizes them,
avoiding cancellation and distortion. When channels are allocated, they
are effectively started by the CMD_START command.

