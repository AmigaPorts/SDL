---
title: 33 / Context Functions / The Default Context
manual: libraries
chapter: libraries
section: 33-context-functions-the-default-context
functions: [AllocIFF, CurrentChunk, ParentChunk, StoreLocalItem]
libraries: [iffparse.library]
---

# 33 / Context Functions / The Default Context

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When you first obtain an [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md) through [AllocIFF()](libraries/33-basic-functions-and-structures-of-iffparse-library.md), a hidden default
context node is created.  You cannot get direct access to this node
through [CurrentChunk()](libraries/33-context-nodes-currentchunk.md) or [ParentChunk()](libraries/33-context-nodes-parentchunk.md).  However, using [StoreLocalItem()](libraries/33-storing-lcis-storelocalitem.md),
you can store information in this context.

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
- [ParentChunk — iffparse.library](../autodocs/iffparse.library.md#parentchunk)
- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)
