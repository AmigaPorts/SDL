---
title: 33 / / Controlling Parsing / PropChunk()/FindProp()
manual: libraries
chapter: libraries
section: 33-controlling-parsing-propchunk-findprop
functions: [FindProp, ParseIFF, PropChunk, StopChunk]
libraries: [iffparse.library]
---

# 33 / / Controlling Parsing / PropChunk()/FindProp()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In the case of a [FORM ILBM](libraries/33-iffparse-library-iff-form-specifications.md), certain chunks are defined as being able to
appear in any order.  Among these are the [BMHD](libraries/33-form-ilbm-interpreting-ilbms.md), [CMAP](libraries/33-form-ilbm-interpreting-ilbms.md), and [CAMG](libraries/33-form-ilbm-interpreting-ilbms.md). Typically,
BMHD appears first, followed by CMAP and CAMG, but you can't make this
assumption.  The [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) and ILBM standards require you to assume these chunks
will appear in any order.  So ideally, what you'd like to do is collect
them as they arrive, but not do anything with them until you actually need
them.

This is where [PropChunk()](autodocs-2.0/iffparse-library-propchunk.md) comes in.  The syntax for PropChunk() is
identical to [StopChunk()](libraries/33-controlling-parsing-stopchunk.md):


```c
    error = PropChunk (iff, ID_ILBM, ID_BMHD);
```
When you call [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md), the parser will look for chunks declared with
[PropChunk()](autodocs-2.0/iffparse-library-propchunk.md).  When it sees them, the parser will internally copy the
contents of the chunk into memory for you before continuing its parsing.

When you're ready to examine the contents of the chunk, you use the
function [FindProp()](autodocs-2.0/iffparse-library-findprop.md):


```c
    StoredProperty = FindProp (iff, ID_ILBM, ID_BMHD);
```
[FindProp()](autodocs-2.0/iffparse-library-findprop.md) returns a pointer to a struct [StoredProperty](autodocs-2.0/includes-libraries-iffparse-h.md), which contains
the chunk size and data.  If the chunk was never encountered, NULL is
returned.  This permits you to process the property chunks in any order
you wish, regardless of how they appeared in the file.  This provides much
better control of data interpretation and also reduces headaches.  The
following fragment shows how [ILBM BitMapHeader](libraries/33-form-ilbm-ilbm-bmhd-bitmapheader-chunk.md) data could be accessed
after using [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md) with [PropChunk](autodocs-2.0/iffparse-library-propchunk.md)(iff, ID_ILBM, ID_BMHD):


```c
    struct StoredProperty *sp;      /* defined in iffparse.h */
    struct BitMapHeader *bmhd;      /* defined in IFF spec   */

    if (sp = FindProp(iff, ID_ILBM, ID_BMHD))
            {
            /* If property is BMHD, sp->sp_Data is ptr to data in BMHD */
            bmhd = (struct BitMapHeader *)sp->sp_Data;
            printf("BMHD: PageWidth      = %ld\n",bmhd->PageWidth);
            }
```

---

## See Also

- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)
