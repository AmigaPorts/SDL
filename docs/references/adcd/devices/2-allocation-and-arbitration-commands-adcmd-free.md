---
title: 2 / Allocation and Arbitration Commands / ADCMD_FREE
manual: devices
chapter: devices
section: 2-allocation-and-arbitration-commands-adcmd-free
functions: []
libraries: []
---

# 2 / Allocation and Arbitration Commands / ADCMD_FREE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[ADCMD_FREE](autodocs-2.0/audio-device-adcmd-free.md) is the opposite of [ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md). When you perform ADCMD_FREE
on a channel, it does a [CMD_RESET](devices/2-hardware-control-commands-cmd-reset.md) command on the hardware and "unlocks"
the channel. It also checks to see if there are other pending allocation
requests. You do not need to perform ADCMD_FREE on channels stolen from
you. If you want channels back after they have been stolen, you must
reallocate them with the same allocation key.

