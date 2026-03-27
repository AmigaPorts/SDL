---
title: 33 / Parsing / Controlling Parsing
manual: libraries
chapter: libraries
section: 33-parsing-controlling-parsing
functions: [FindProp, ParseIFF, PropChunk, StopChunk]
libraries: [iffparse.library]
---

# 33 / Parsing / Controlling Parsing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md), if left to itself, wouldn't do anything useful.  Ideally, it
should stop at strategic places so we can look at the chunks.  Here's
where it can get complicated.

There are many functions provided to help control the parsing process;
only the common ones are covered here.  Additional functions are described
in the Autodocs for iffparse.library (for the complete Autodocs, refer to
the Amiga ROM Kernel Reference Manual: [Includes and Autodocs](autodocs-2.0/iffparse-doc.md) also by
Addison-Wesley).

 [StopChunk()](libraries/33-controlling-parsing-stopchunk.md)    [PropChunk()/FindProp()](libraries/33-controlling-parsing-propchunk-findprop.md) 

---

## See Also

- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)
