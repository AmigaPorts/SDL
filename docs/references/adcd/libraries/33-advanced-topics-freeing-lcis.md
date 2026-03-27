---
title: 33 / Advanced Topics / Freeing LCIs
manual: libraries
chapter: libraries
section: 33-advanced-topics-freeing-lcis
functions: [FreeLocalItem, FreeMem, ParseIFF, SetLocalItemPurge]
libraries: [exec.library, iffparse.library]
---

# 33 / Advanced Topics / Freeing LCIs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Ordinarily, the parser will automatically delete [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md)s you have allocated
and installed.  However, you may have a case where simply [FreeMem()](libraries/20-exec-memory-allocation-memory-functions.md)ing
your LCI is not enough; you may need to free some ancillary memory, or
decrement a counter, or send a signal, or something.  This is where
[SetLocalItemPurge()](autodocs-2.0/iffparse-library-setlocalitempurge.md) comes in.  It is called as follows:


```c
    SetLocalItemPurge (lci, hookptr);
```
When the parser is ready to delete your [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md), your purge handler code will
be called through the [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) you supplied.  You can then perform all your
necessary operations.  One of these operations should be to free the LCI
itself.  This is done with [FreeLocalItem()](autodocs-2.0/iffparse-library-freelocalitem.md):


```c
    FreeLocalItem (lci);
```
This deallocates the memory used to store the [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) and the client buffer
allocated with it.  [FreeLocalItem()](autodocs-2.0/iffparse-library-freelocalitem.md) is only called as part of a custom
purge handler.

As with custom chunk handlers, your purge handler executes in the same
environment as the mainline code that called [ParseIFF()](libraries/33-parsing-controlling-parsing.md).  It is
recommended that you keep purge handlers short and to the point; super
clever stuff should be reserved for custom chunk handlers, or for the
client's mainline code.  Custom purge handlers must always work; failures
will be ignored.

---

## See Also

- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [SetLocalItemPurge — iffparse.library](../autodocs/iffparse.library.md#setlocalitempurge)
