---
title: D / Errors / Fails only on 68000
manual: libraries
chapter: libraries
section: d-errors-fails-only-on-68000
functions: []
libraries: []
---

# D / Errors / Fails only on 68000

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following programming practices can be the cause of this problem:
software delay loops; word or longword access of an odd address (illegal
on the 68000).  Note that this can occur under 2.0 if you reference
[IntuiMessage->IAddress](libraries/9-using-the-idcmp-intuimessages.md) as a structure pointer without first determining
that the [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)'s [Class](libraries/9-using-the-idcmp-intuimessages.md) is defined as having a structure pointer in
its IAddress; use of the assembler CLR instruction on a hardware register
which is triggered by any access.  The 68000 CLR instruction performs two
accesses (read and write) while 68020/30 CLR does a single write access.
Use MOVE instead; assumptions about the order in which asynchronous tasks
will finish; use of compiler flags which have generated inline 68881/68882
math coprocessor instructions or 68020/30 specific code.

