---
title: 2 / ADCMD_ALLOCATE / ADCMD_ALLOCATE Examples
manual: devices
chapter: devices
section: 2-adcmd-allocate-adcmd-allocate-examples
functions: []
libraries: []
---

# 2 / ADCMD_ALLOCATE / ADCMD_ALLOCATE Examples

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are more examples of how to tell [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) your channel
preferences. If you want any channel, but want a right channel first, use
an array containing 1, 8, 2, and 4:

  0001
  1000
  0010
  0100

If you only want a right channel, use 1 and 8 (channels 0 and 3):

  0001
  1000

If you want only a left channel, use 2 and 4  (channels 1 and 2):

  0010
  0100

If you want to allocate a channel and keep it for a sound that can be
interrupted and restarted, allocate it at a certain precedence. If it is
stolen, allocate it again with the ADIOF_NOWAIT flag set to 0. When the
channel is relinquished, you will get it again.

