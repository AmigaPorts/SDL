---
title: E /Release 2 Changes That Affect Compatibility / Other Hardware Issues
manual: libraries
chapter: libraries
section: e-release-2-changes-that-affect-compatibility-other
functions: []
libraries: []
---

# E /Release 2 Changes That Affect Compatibility / Other Hardware Issues

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * Battery-backed clock is different on A3000.  Use battclock.resource

    to access the real-time clock if battclock.resource can be opened.
  * A 68030 hardware characteristic causes longword-aligned longword

```c
    writes to allocate a valid entry in the data cache,  even if the
    hardware area shouldn't be cached.  This can cause problems for I/O
    registers and shared memory devices.  To solve this: 1) don't do that
    2) flush the cache or 3) use Enforcer Quiet.  See the Motorola 68030
    manual under the description of the Write Allocate bit (which must be
    set for the Amiga to run with the Data Cache).
```
