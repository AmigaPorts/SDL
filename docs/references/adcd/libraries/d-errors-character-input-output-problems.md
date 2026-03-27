---
title: D / Errors / Character Input/Output Problems
manual: libraries
chapter: libraries
section: d-errors-character-input-output-problems
functions: [RawKeyConvert]
libraries: [console.device]
---

# D / Errors / Character Input/Output Problems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[RAWKEY](libraries/9-event-message-classes-and-flags-other-flags.md) users must be aware that RAWKEY codes can be different letters or
symbols on national keyboards.  If you need to use RAWKEY, run the codes
through [RawKeyConvert()](autodocs-2.0/console-device-rawkeyconvert.md) (see the "[Intuition Input and Output Methods](libraries/9-event-message-classes-and-flags-other-flags.md)"
chapter) to get proper translation to correct ASCII codes. Improper
display or processing of high-ASCII international characters can be caused
by incorrect tolower()/toupper(), or by sign extension of character values
when switched on or assigned into larger size variables. Use unsigned
variables such as UBYTE (not char) for strings and characters whenever
possible. [Internationally correct string functions](libraries/37-utility-library-international-string-functions.md) are provided in the 2.0
utility.library.

---

## See Also

- [RawKeyConvert — console.device](../autodocs/console.device.md#rawkeyconvert)
