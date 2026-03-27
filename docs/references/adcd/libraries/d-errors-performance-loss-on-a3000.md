---
title: D / Errors / Performance Loss--On A3000
manual: libraries
chapter: libraries
section: d-errors-performance-loss-on-a3000
functions: []
libraries: []
---

# D / Errors / Performance Loss--On A3000

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If your program has "Enforcer hits" (i.e., illegal references to memory
caused by improperly initialized pointers), this will cause Bus Errors.
The A3000 bus error handler contains a built-in delay to let the bus
settle.  If you have many enforcer hits, this could slow your program down
substantially.

