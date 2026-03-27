---
title: 33 / / Storing LCIs / FindLocalItem()
manual: libraries
chapter: libraries
section: 33-storing-lcis-findlocalitem
functions: [FindLocalItem]
libraries: [iffparse.library]
---

# 33 / / Storing LCIs / FindLocalItem()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After you've stored your [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) in a [ContextNode](libraries/33-context-functions-context-nodes.md), you will no doubt want to
be able to find it again later.  You do this with the function
[FindLocalItem()](autodocs-2.0/iffparse-library-findlocalitem.md), which is called as follows:


```c
    lci = FindLocalItem (iff, type, id, ident);
```
[FindLocalItem()](autodocs-2.0/iffparse-library-findlocalitem.md) attempts to locate an [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) having the specified type, ID,
and identification values.  The search proceeds as follows (refer to
[Figure 33-3](libraries/33-context-functions-context-specific-data-localcontextitems.md) to understand this better).

[FindLocalItem()](autodocs-2.0/iffparse-library-findlocalitem.md) starts at the top (current) [ContextNode](libraries/33-context-functions-context-nodes.md) and searches all
[LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md)s in that context.  If no matching LCIs are found, it proceeds down the
context stack to the next ContextNode and searches all its LCIs.  The
process repeats until it finds the desired LCI (whereupon it returns a
pointer to it), or reaches the end without finding anything (where it
returns NULL).


```c
    Context Stack Position.
    -----------------------
    [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md)s higher in the stack will "override" lower LCIs with the
    same type, ID, and identification field.  This is how property
    scoping is handled.  As [ContextNode](libraries/33-context-functions-context-nodes.md)s are popped off the context
    stack, all its LCIs are deleted as well.  See the section on
    "[Freeing LCIs](libraries/33-advanced-topics-freeing-lcis.md)" below for additional information on deleting LCIs.
```

---

## See Also

- [FindLocalItem — iffparse.library](../autodocs/iffparse.library.md#findlocalitem)
