---
title: 33 / / Custom Chunk Handlers / Installing a Custom Chunk Handler
manual: libraries
chapter: libraries
section: 33-custom-chunk-handlers-installing-a-custom-chunk-handler
functions: [EntryHandler, StoreLocalItem]
libraries: [iffparse.library]
---

# 33 / / Custom Chunk Handlers / Installing a Custom Chunk Handler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To install an entry handler, you call [EntryHandler()](autodocs-2.0/iffparse-library-entryhandler.md) in the following
manner:


```c
    error = EntryHandler (iff, type, id, position, hookptr, object);
```
An exit handler is installed by saying:


```c
    error = ExitHandler (iff, type, id, position, hookptr, object);
```
In both cases, a handler is installed for chunks having the specified type
and id.  The position argument specifies in what context to install the
handler, and is identical to the position argument used by
[StoreLocalItem()](libraries/33-storing-lcis-storelocalitem.md).  The hookptr argument given above is a pointer to your
[Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) structure.

---

## See Also

- [EntryHandler — iffparse.library](../autodocs/iffparse.library.md#entryhandler)
- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)
