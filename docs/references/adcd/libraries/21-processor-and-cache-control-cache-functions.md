---
title: 21 / Processor and Cache Control / Cache Functions
manual: libraries
chapter: libraries
section: 21-processor-and-cache-control-cache-functions
functions: []
libraries: []
---

# 21 / Processor and Cache Control / Cache Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As of the MC68020 all processors have an instruction cache, 256 bytes on
the MC68020 and MC68030 and 4 KBytes on a [MC68040](libraries/21-processor-and-cache-control-the-68040-and-cpu-caches.md).  The MC68030 and
MC68040 have data caches as well, 256 bytes and 4 KBytes respectively. All
the processors load instructions ahead of the program counter (PC), albeit
it that the MC68000 and MC68010 only prefetch one and two words
respectively. This means the CPU loads instructions ahead of the current
program counter.  For this reason self-modifying code is strongly
discouraged.  If your code modifies or decrypts itself just ahead of the
program counter, the pre-fetched instructions may not match the modified
instructions.  If self-modifying code must be used, flushing the cache is
the safest way to prevent this.

