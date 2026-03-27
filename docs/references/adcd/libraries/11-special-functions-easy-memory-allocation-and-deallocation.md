---
title: 11 Special Functions / Easy Memory Allocation and Deallocation
manual: libraries
chapter: libraries
section: 11-special-functions-easy-memory-allocation-and-deallocation
functions: [AllocRemember, FreeRemember]
libraries: [intuition.library]
---

# 11 Special Functions / Easy Memory Allocation and Deallocation

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Intuition has a pair of routines that enable applications to make multiple
memory allocations which are easily deallocated with a single call.  The
Intuition routines for memory management are [AllocRemember()](libraries/11-easy-memory-allocation-and-deallocation-helps-you.md) and
[FreeRemember()](libraries/11-easy-memory-allocation-and-deallocation-helps-you.md).  These routines rely upon the [Remember](libraries/11-easy-memory-allocation-and-deallocation-the-remember.md) structure to track
allocations.

 [Intuition Helps You Remember](libraries/11-easy-memory-allocation-and-deallocation-helps-you.md)    [The Remember Structure](libraries/11-easy-memory-allocation-and-deallocation-the-remember.md) 
 [How to Remember](libraries/11-easy-memory-allocation-and-deallocation-how-to-remember.md)                 [An Example of Remembering](libraries/lib-examples-remembertest-c.md) 

---

## See Also

- [AllocRemember — intuition.library](../autodocs/intuition.library.md#allocremember)
- [FreeRemember — intuition.library](../autodocs/intuition.library.md#freeremember)
