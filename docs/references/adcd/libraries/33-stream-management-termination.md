---
title: 33 / Stream Management / Termination
manual: libraries
chapter: libraries
section: 33-stream-management-termination
functions: [CloseIFF, OpenIFF]
libraries: [iffparse.library]
---

# 33 / Stream Management / Termination

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Termination is simple.  Just call [CloseIFF](autodocs-2.0/iffparse-library-closeiff.md)(iff).  This may be called at
any time, and terminates IFFParse's transaction with the stream.  The
stream itself is not closed.  The [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md) may be reused; you may safely
call [OpenIFF()](libraries/33-stream-management-initialization.md) on it again.  You are responsible for closing the streams
you opened.  A stream used in an IFFHandle must generally remain open
until you CloseIFF().

---

## See Also

- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
- [OpenIFF — iffparse.library](../autodocs/iffparse.library.md#openiff)
