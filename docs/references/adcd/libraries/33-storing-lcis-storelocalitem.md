---
title: 33 / / Storing LCIs / StoreLocalItem()
manual: libraries
chapter: libraries
section: 33-storing-lcis-storelocalitem
functions: [StoreLocalItem]
libraries: [iffparse.library]
---

# 33 / / Storing LCIs / StoreLocalItem()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [StoreLocalItem()](autodocs-2.0/iffparse-library-storelocalitem.md) function is called as follows:


```c
    error = StoreLocalItem (iff, lci, position);
```
The position argument determines where the [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) is stored.  The possible
values are IFFSLI_ROOT, IFFSLI_TOP, and IFFSLI_PROP.

IFFSLI_ROOT causes [StoreLocalItem()](autodocs-2.0/iffparse-library-storelocalitem.md) to store your [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) in the default
[ContextNode](libraries/33-context-functions-context-nodes.md).

IFFSLI_TOP gets your [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) stored in the top (current) [ContextNode](libraries/33-context-functions-context-nodes.md).


```c
    The LCI Ends When the Current Context Ends.
    -------------------------------------------
    When the current context expires, your [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) will be deleted by
    the parser.
```
IFFSLI_PROP causes your [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) to be stored in the topmost context from which
a property would apply.  This is usually the topmost [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md) or [LIST](libraries/33-the-structure-of-iff-files-composite-data-types.md) chunk.
For example, suppose you had a deeply nested [ILBM FORM](libraries/33-iffparse-library-iff-form-specifications.md), and you wanted to
store the [BMHD](libraries/33-form-ilbm-interpreting-ilbms.md) property in its correct context such that, when the current
FORM context expired, the BMHD property would be deleted.  IFFSLI_PROP
will cause [StoreLocalItem()](autodocs-2.0/iffparse-library-storelocalitem.md) to locate the proper context for such scoping,
and store the LCI there.  See the section on "[Finding the Prop Context](libraries/33-advanced-topics-finding-the-prop-context.md)"
for additional information on the scope of properties.

---

## See Also

- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)
