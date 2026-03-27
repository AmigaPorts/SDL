---
title: 33 / / Storing LCIs / StoreItemInContext()
manual: libraries
chapter: libraries
section: 33-storing-lcis-storeitemincontext
functions: [StoreItemInContext]
libraries: [iffparse.library]
---

# 33 / / Storing LCIs / StoreItemInContext()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[StoreItemInContext()](autodocs-2.0/iffparse-library-storeitemincontext.md) is used when you already have a pointer to the
[ContextNode](libraries/33-context-functions-context-nodes.md) to which you want to attach your [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md).  It is called like so:


```c
    StoreItemInContext (iff, lci, contextnode);
```
[StoreItemInContext()](autodocs-2.0/iffparse-library-storeitemincontext.md) links your [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) into the specified [ContextNode](libraries/33-context-functions-context-nodes.md).  Then
it searches the ContextNode to see if there is another LCI with the same
type, ID, and identification values.  If so, the old one is deleted.

---

## See Also

- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)
