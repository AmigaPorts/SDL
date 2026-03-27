---
title: 2 / ADCMD_ALLOCATE / The Allocation Key
manual: devices
chapter: devices
section: 2-adcmd-allocate-the-allocation-key
functions: []
libraries: []
---

# 2 / ADCMD_ALLOCATE / The Allocation Key

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you want to perform multi-channel commands, all the channels must have
the same key since the [IOAudio](devices/2-audio-device-device-interface.md) block has only one allocation key field.
The channels must all have that same key even when they were not allocated
simultaneously. If you want to use a key you already have, you can pass
that key in the ioa_AllocKey field and [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) can allocate other
channels with that existing key. The ADCMD_ALLOCATE command returns a new
and unique key only if you pass it a zero in the allocation key field.

