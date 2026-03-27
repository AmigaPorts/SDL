---
title: 33 / / Other Parsing Modes / IFFPARSE_RAWSTEP
manual: libraries
chapter: libraries
section: 33-other-parsing-modes-iffparse-rawstep
functions: [CurrentChunk, ParseIFF, PropChunk]
libraries: [iffparse.library]
---

# 33 / / Other Parsing Modes / IFFPARSE_RAWSTEP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This mode causes the parser to progress through the stream step by step,
rather than in the automated fashion provided by [IFFPARSE_SCAN](libraries/33-iffparse-library-parsing.md).  In this
mode, [ParseIFF()](libraries/33-parsing-controlling-parsing.md) will return upon every entry to and departure from a
context.

When the parser enters a context, [ParseIFF()](libraries/33-parsing-controlling-parsing.md) will return zero.
[CurrentChunk()](libraries/33-context-nodes-currentchunk.md) will report the type and ID of the chunk just entered, and
the stream will be positioned to read the first byte in the chunk.  When
entering a [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md), [LIST](libraries/33-the-structure-of-iff-files-composite-data-types.md), [CAT](libraries/33-the-structure-of-iff-files-composite-data-types.md) or [PROP](libraries/33-the-structure-of-iff-files-composite-data-types.md) chunk, the longword containing the type
(e.g., [ILBM](libraries/33-iffparse-library-iff-form-specifications.md), [FTXT](libraries/33-iffparse-library-iff-form-specifications.md), etc.) is read by the parser.  In this case, the stream
will be positioned to read the byte immediately following the type.)

When the parser leaves a context, [ParseIFF()](libraries/33-parsing-controlling-parsing.md) will return the value
IFFERR_EOC.  This is not strictly an error, but an indication that you are
about to leave the current context.  [CurrentChunk()](libraries/33-context-nodes-currentchunk.md) will report the type
and ID of the chunk you are about to leave.  The stream is not positioned
predictably within the chunk.

The parser does not call any installed chunk handlers when using this mode
(e.g., property chunks declared with [PropChunk()](libraries/33-controlling-parsing-propchunk-findprop.md) will not be collected).

See the example program, [Sift.c](libraries/lib-examples-sift-c.md), for a demonstration of IFFPARSE_RAWSTEP.

---

## See Also

- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
