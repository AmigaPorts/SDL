---
title: D / Errors / Audio--Corrupted Samples
manual: libraries
chapter: libraries
section: d-errors-audio-corrupted-samples
functions: []
libraries: []
---

# D / Errors / Audio--Corrupted Samples

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The bit data for audio samples must be in Chip RAM.  Check your compiler
manual for directives or flags which will place your audio sample data in
Chip RAM.  Or dynamically allocate Chip RAM and copy or load the audio
sample there.

