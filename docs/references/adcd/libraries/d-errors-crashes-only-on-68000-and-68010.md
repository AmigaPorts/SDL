---
title: D / Errors / Crashes--Only on 68000 and 68010
manual: libraries
chapter: libraries
section: d-errors-crashes-only-on-68000-and-68010
functions: []
libraries: []
---

# D / Errors / Crashes--Only on 68000 and 68010

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This can be caused by illegal instructions (80000000.00000004) such as new
68020/30/40 instructions or inline 68881/882 code.  But this is usually
caused by a word or longword access at an odd address.  This is legal on
the 68020 and above, but will generate an Address Error
(80000000.00000003) on a 68000 or 68010.  This can be caused by using
uninitialized pointers, using freed memory, or using system structures
improperly (for example, referencing into [IntuiMessage->IAddress](libraries/9-using-the-idcmp-intuimessages.md) as a
struct [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) *  on a non-Gadget message).

