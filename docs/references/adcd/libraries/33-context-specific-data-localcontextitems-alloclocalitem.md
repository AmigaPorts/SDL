---
title: 33 / / Context-Specific Data: LocalContextItems / AllocLocalItem()
manual: libraries
chapter: libraries
section: 33-context-specific-data-localcontextitems-alloclocalitem
functions: [AllocLocalItem]
libraries: [iffparse.library]
---

# 33 / / Context-Specific Data: LocalContextItems / AllocLocalItem()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To create an [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md), you use the function [AllocLocalItem()](autodocs-2.0/iffparse-library-alloclocalitem.md):


```c
    lci = AllocLocalItem (type, id, ident, datasize);
```
If successful, you will be returned a pointer to an [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) having the
specified type, ID, and identification values; and with datasize bytes of
buffer space for your application to use.

---

## See Also

- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
