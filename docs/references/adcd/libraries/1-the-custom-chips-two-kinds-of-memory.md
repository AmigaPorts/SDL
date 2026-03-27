---
title: 1 / / The Custom Chips / Two Kinds of Memory
manual: libraries
chapter: libraries
section: 1-the-custom-chips-two-kinds-of-memory
functions: []
libraries: []
---

# 1 / / The Custom Chips / Two Kinds of Memory

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To keep the Amiga running efficiently, the Amiga has two memory buses and
two kinds of memory.  Chip memory is memory that both the CPU and
[custom chips](libraries/1-programming-in-the-amiga-environment-the-custom-chips.md) can access.  Fast memory is memory that only the CPU (and
certain expansion cards) can access.  Since Chip memory is shared, CPU
access may be slowed down if the custom chips are doing heavy-duty
processing.  CPU access to Fast memory is never slowed down by contention
with the custom chips.

The distinction between Chip memory and Fast memory is very important for
Amiga programmers to keep in mind because any data accessed directly by
the custom chips such as video display data, audio data or sprite data
must be in Chip memory.
  _________________________________________________________________
 |                                                                 |
 | What Every Amiga Programmer Should Know:                        |
 | ----------------------------------------                        |
 | The Amiga has two kinds of memory: Chip memory and Fast memory. |
 | Use the right kind.                                             |
 |_________________________________________________________________|

