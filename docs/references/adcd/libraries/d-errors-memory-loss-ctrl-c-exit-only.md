---
title: D / Errors / Memory Loss--Ctrl-C Exit Only
manual: libraries
chapter: libraries
section: d-errors-memory-loss-ctrl-c-exit-only
functions: []
libraries: []
---

# D / Errors / Memory Loss--Ctrl-C Exit Only

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You have Amiga-specific resources opened or allocated and you have not
disabled your compiler's automatic Ctrl-C handling (causing all of your
program cleanups to be skipped).  Disable the compiler's Ctrl-C handling
and handle Ctrl-C ([SIGBREAKF_CTRL_C](libraries/17-signals-looking-for-break-keys.md)) yourself.

