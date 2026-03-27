---
title: 2 / Hardware Control Commands / ADCMD_PERVOL
manual: devices
chapter: devices
section: 2-hardware-control-commands-adcmd-pervol
functions: []
libraries: []
---

# 2 / Hardware Control Commands / ADCMD_PERVOL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[ADCMD_PERVOL](autodocs-2.0/audio-device-adcmd-pervol.md) lets you change the volume and period of a [CMD_WRITE](devices/2-hardware-control-commands-cmd-write.md) that is
in progress. The change can take place immediately or you can set the
ADIOF_SYNCCYCLE flag to have the change occur at the end of the cycle.
This is useful to produce vibratos, glissandos, tremolos, and volume
envelopes in music or to change the volume of a sound.

