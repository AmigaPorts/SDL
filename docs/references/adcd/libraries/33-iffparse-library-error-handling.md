---
title: 33 IFFParse Library / Error Handling
manual: libraries
chapter: libraries
section: 33-iffparse-library-error-handling
functions: [CloseIFF]
libraries: [iffparse.library]
---

# 33 IFFParse Library / Error Handling

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If at any time during reading or writing you encounter an error, the
[IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md) is left in an undefined state.  Upon detection of an error, you
should perform an abort sequence and [CloseIFF()](libraries/33-stream-management-termination.md) the IFFHandle.  Once
CloseIFF() has been called, the IFFHandle is restored to normalcy and may
be reused.

---

## See Also

- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
