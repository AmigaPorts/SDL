---
title: 33 / / Custom Chunk Handlers / Inside a Custom Chunk Handler
manual: libraries
chapter: libraries
section: 33-custom-chunk-handlers-inside-a-custom-chunk-handler
functions: [EntryHandler, ExitHandler, ParseIFF]
libraries: [iffparse.library]
---

# 33 / / Custom Chunk Handlers / Inside a Custom Chunk Handler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The mechanics of receiving parameters through the [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) are covered in the
"[Custom Stream Handlers](libraries/33-advanced-topics-custom-stream-handlers.md)" section, and are not duplicated here.  Refer to
the [EntryHandler()](autodocs-2.0/iffparse-library-entryhandler.md) and [ExitHandler()](autodocs-2.0/iffparse-library-exithandler.md) Autodocs for the contents of the
registers upon entry.

Once inside your handler, you can call nearly all functions in the
iffparse.library, however, you should avoid calling [ParseIFF()](libraries/33-parsing-controlling-parsing.md) from within
chunk handlers.

Your handler runs in the same environment as whoever called [ParseIFF()](libraries/33-parsing-controlling-parsing.md).
The propagation sequence is:



```c
     __________            ____________            ________________
    |          |          |            |          |                |
    | mainline |--calls-->| ParseIFF() |--calls-->| your_handler() |
    |__________|          |____________|          |________________|
```
Thus, your handler runs on your mainline's stack, and can call any OS
functions the mainline code can.  (Your handler will have to set the
global base pointer if your code uses base-relative addressing.)

When leaving the handler, you must follow the standard register
preservation conventions (D0/D1/A0/A1 may be trashed, all others must be
preserved).  D0 contains your return code, which will affect the parser in
a number of ways:

If you return zero (a normal, uneventful return), [ParseIFF()](libraries/33-parsing-controlling-parsing.md) will continue
normally.  If you return the value IFFERR_RETURN2CLIENT, ParseIFF() will
stop and return the value zero to the mainline code.

If you return any other value, [ParseIFF()](libraries/33-parsing-controlling-parsing.md) will stop and return that value
to the mainline code.  This is how you should return error conditions to
the client code.

---

## See Also

- [EntryHandler — iffparse.library](../autodocs/iffparse.library.md#entryhandler)
- [ExitHandler — iffparse.library](../autodocs/iffparse.library.md#exithandler)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
