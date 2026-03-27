---
title: D / Errors / Fails only with Enhanced Chips
manual: libraries
chapter: libraries
section: d-errors-fails-only-with-enhanced-chips
functions: []
libraries: []
---

# D / Errors / Fails only with Enhanced Chips

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Usually caused by writing or reading addresses past the end of older
custom chips, or writing something other than 0 (zero) to bits which are
undefined in older chip registers, or failing to mask out undefined bits
when interpreting the value read from a chip register.  Note that system
copper lists are different under 2.0 when ECS chips are present. See
"[Fails only on Chip-RAM-Only Machines](libraries/d-errors-fails-only-on-chip-ram-only-machines.md)".

