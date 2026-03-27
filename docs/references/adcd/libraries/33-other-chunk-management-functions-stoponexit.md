---
title: 33 / / Other Chunk Management Functions / StopOnExit()
manual: libraries
chapter: libraries
section: 33-other-chunk-management-functions-stoponexit
functions: [ParseIFF, StopChunk, StopOnExit]
libraries: [iffparse.library]
---

# 33 / / Other Chunk Management Functions / StopOnExit()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Whereas [StopChunk()](libraries/33-controlling-parsing-stopchunk.md) will stop the parser just as it enters the declared
chunk, [StopOnExit()](autodocs-2.0/iffparse-library-stoponexit.md) will stop just before it leaves the chunk. This is
useful for finding the end of [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md)s, which would indicate that you've
collected all possible data in this FORM and may now act on it.


```c
    /* Ask ParseIFF() to stop with IFFERR_EOC when leaving a FORM ILBM */
    StopOnExit(iff,ID_ILBM, ID_FORM);
```

---

## See Also

- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)
- [StopOnExit — iffparse.library](../autodocs/iffparse.library.md#stoponexit)
