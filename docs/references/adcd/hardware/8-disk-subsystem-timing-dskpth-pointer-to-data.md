---
title: 8 / / Disk Subsystem Timing / DSKPTH - Pointer to Data
manual: hardware
chapter: hardware
section: 8-disk-subsystem-timing-dskpth-pointer-to-data
functions: []
libraries: []
---

# 8 / / Disk Subsystem Timing / DSKPTH - Pointer to Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You specify the 32-bit wide address from which or to which the data is to
be transferred. The lowest bit of the address must be zero, and the buffer
must be in Chip memory.  The value must be written as a single long word
to the DSKPTH register ($DFF020).

