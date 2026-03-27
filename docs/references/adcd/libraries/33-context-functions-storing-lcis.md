---
title: 33 / Context Functions / Storing LCIs
manual: libraries
chapter: libraries
section: 33-context-functions-storing-lcis
functions: [FindLocalItem, StoreItemInContext, StoreLocalItem]
libraries: [iffparse.library]
---

# 33 / Context Functions / Storing LCIs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once you've created and initialized an [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md), you'll want to attach it to a
[ContextNode](libraries/33-context-functions-context-nodes.md).  Though a ContextNode can have many LCIs, a given LCI can be
linked to only one ContextNode.  Once linked, an LCI cannot be removed
from a ContextNode (this may change in the future).  Storing an LCI in a
ContextNode is done with the functions StoreLocalItem() and
StoreItemInContext().

 [StoreLocalItem()](libraries/33-storing-lcis-storelocalitem.md)    [StoreItemInContext()](libraries/33-storing-lcis-storeitemincontext.md)    [FindLocalItem()](libraries/33-storing-lcis-findlocalitem.md) 

---

## See Also

- [FindLocalItem — iffparse.library](../autodocs/iffparse.library.md#findlocalitem)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)
- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)
