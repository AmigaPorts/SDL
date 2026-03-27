---
title: 21 / Processor and Cache Control / Status Register
manual: libraries
chapter: libraries
section: 21-processor-and-cache-control-status-register
functions: [SetSR]
libraries: [exec.library]
---

# 21 / Processor and Cache Control / Status Register

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The processor status register bits can be set or read with the [SetSR()](autodocs-2.0/exec-library-setsr.md)
function.  This function operates in [supervisor mode](libraries/21-processor-and-cache-control-supervisor-mode.md), thus both the upper
and lower byte of the SR can be read or set.  Be very sure you know what
you are doing when you use this function to set bits in the SR and above
all never try to use this function to enter supervisor mode. Refer to the
M68000 Programmers Reference Manual by Motorola Inc. for information about
the definition of individual SR bits per processor type.

---

## See Also

- [SetSR — exec.library](../autodocs/exec.library.md#setsr)
