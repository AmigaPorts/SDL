---
title: D / Errors / Fails only on Chip-RAM-Only Machines
manual: libraries
chapter: libraries
section: d-errors-fails-only-on-chip-ram-only-machines
functions: []
libraries: []
---

# D / Errors / Fails only on Chip-RAM-Only Machines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Caused by specifically asking for or requiring [MEMF_FAST](libraries/20-memory-functions-memory-attributes.md) memory.  If you
don't need Chip RAM, ask for memory type 0L, or [MEMF_CLEAR](libraries/20-memory-functions-memory-attributes.md), or
[MEMF_PUBLIC](libraries/20-memory-functions-memory-attributes.md)|MEMF_CLEAR as applicable.  If there is Fast memory available,
you will be given Fast memory.  If not, you will get Chip RAM.  May also
be caused by trackdisk-level loading of code or data over important system
memory or structures which might reside in low Chip memory on a
Chip-RAM-Only machine.

