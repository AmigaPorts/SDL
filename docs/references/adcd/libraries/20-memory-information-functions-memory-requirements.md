---
title: 20 / / Memory Information Functions / Memory Requirements
manual: libraries
chapter: libraries
section: 20-memory-information-functions-memory-requirements
functions: [AvailMem]
libraries: [exec.library]
---

# 20 / / Memory Information Functions / Memory Requirements

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The same attribute flags used in memory allocation routines are valid for
the memory information routines.  There is also an additional flag,
[MEMF_LARGEST](autodocs-2.0/includes-exec-memory-h.md), which can be used in the [AvailMem()](libraries/20-memory-info-functions-calling-memory-information.md) routine to find out what
the largest available memory block of a particular type is.  Specifying
the [MEMF_TOTAL](autodocs-2.0/includes-exec-memory-h.md) flag will return the total amount of memory currently
available.

---

## See Also

- [AvailMem — exec.library](../autodocs/exec.library.md#availmem)
