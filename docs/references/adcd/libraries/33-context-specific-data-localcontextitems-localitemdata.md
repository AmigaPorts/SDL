---
title: 33 / / Context-Specific Data: LocalContextItems / LocalItemData()
manual: libraries
chapter: libraries
section: 33-context-specific-data-localcontextitems-localitemdata
functions: [AllocLocalItem, LocalItemData]
libraries: [iffparse.library]
---

# 33 / / Context-Specific Data: LocalContextItems / LocalItemData()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To get a pointer to an [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md)s data buffer, you use [LocalItemData()](autodocs-2.0/iffparse-library-localitemdata.md):


```c
    buf = LocalItemData (lci);
```
You may read and write the buffer to your heart's content; it is yours.
You should not, however, write beyond the end of the buffer.  The size of
the buffer is what you asked for when you called [AllocLocalItem()](libraries/33-context-specific-data-localcontextitems-alloclocalitem.md).

---

## See Also

- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
- [LocalItemData — iffparse.library](../autodocs/iffparse.library.md#localitemdata)
