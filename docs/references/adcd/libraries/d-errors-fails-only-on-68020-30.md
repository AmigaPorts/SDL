---
title: D / Errors / Fails only on 68020/30
manual: libraries
chapter: libraries
section: d-errors-fails-only-on-68020-30
functions: [GetCC]
libraries: [exec.library]
---

# D / Errors / Fails only on 68020/30

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following programming practices can cause this problem: using the
upper bytes of addresses as flags; doing signed math on addresses;
self-modifying code; using the MOVE SR assembler instruction (use Exec
[GetCC()](libraries/21-processor-and-cache-control-condition-code-register.md) instead); software delay loops; assumptions about the order in
which asynchronous tasks will finish.  The following differences in
68020/30 can cause problems: data and/or instruction caches must be
flushed if data or code is changed by DMA or other non-processor
modification; different exception stack frame; interrupt autovectors may
be moved by VBR; 68020/30 CLR instruction does a single write access
unlike the 68000 CLR instruction which does a separate read and write
access (this might affect a read-triggered register in I/O space--use MOVE
instead).

---

## See Also

- [GetCC — exec.library](../autodocs/exec.library.md#getcc)
