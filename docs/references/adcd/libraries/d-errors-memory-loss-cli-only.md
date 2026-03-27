---
title: D / Errors / Memory Loss--CLI Only
manual: libraries
chapter: libraries
section: d-errors-memory-loss-cli-only
functions: []
libraries: []
---

# D / Errors / Memory Loss--CLI Only

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Make sure you are testing in a standard environment.  Some third-party
shells dynamically allocate history buffers, or cause other memory
fluctuations.  Also, if your program executes different code when started
from CLI, check that code and its cleanup.  And check your startup.asm if
you wrote your own.

