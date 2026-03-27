---
title: 2 / Hardware Control Commands / ADCMD_WAITCYCLE
manual: devices
chapter: devices
section: 2-hardware-control-commands-adcmd-waitcycle
functions: []
libraries: []
---

# 2 / Hardware Control Commands / ADCMD_WAITCYCLE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is a single-channel command. [ADCMD_WAITCYCLE](autodocs-2.0/audio-device-adcmd-waitcycle.md) is replied to when the
current cycle has completed.  If there is no [CMD_WRITE](devices/2-hardware-control-commands-cmd-write.md) in progress, it
returns immediately.

