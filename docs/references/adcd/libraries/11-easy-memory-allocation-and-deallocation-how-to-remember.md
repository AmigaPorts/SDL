---
title: 11 / Easy Memory Allocation and Deallocation / How to Remember
manual: libraries
chapter: libraries
section: 11-easy-memory-allocation-and-deallocation-how-to-remember
functions: [AllocRemember, FreeRemember]
libraries: [intuition.library]
---

# 11 / Easy Memory Allocation and Deallocation / How to Remember

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To use Intuition's memory functions, first create an anchor for the memory
to be allocated by declaring a variable that is a pointer to a [Remember](libraries/11-easy-memory-allocation-and-deallocation-the-remember.md)
structure and initializing that pointer to NULL.  This variable is called
the remember key.


```c
    struct Remember *rememberKey = NULL;
```
Call [AllocRemember()](libraries/11-easy-memory-allocation-and-deallocation-helps-you.md) with the address of the remember key, along with the
memory requirements for the specific allocation.  Multiple allocations may
be made before a call to [FreeRemember()](libraries/11-easy-memory-allocation-and-deallocation-helps-you.md).


```c
    memBlockA = AllocRemember(&rememberKey, SIZE_A,
                              MEMF_CLEAR | MEMF_PUBLIC);
    if (memBlockA == NULL)
        {
        /* error: allocation failed */
        printf("Memory allocation failed.\n");
        }
    else
        {
        /* use the memory here */
        printf("Memory allocation succeeded.\n");
        }
```
[AllocRemember()](libraries/11-easy-memory-allocation-and-deallocation-helps-you.md) actually performs two memory allocations per call, one for
the memory requested and the other for a [Remember](libraries/11-easy-memory-allocation-and-deallocation-the-remember.md) structure.  The Remember
structure is filled in with data describing the allocation, and is linked
into the list to which the remember key points.

To free memory that has been allocated, simply call [FreeRemember()](libraries/11-easy-memory-allocation-and-deallocation-helps-you.md) with
the correct remember key.


```c
    void FreeRemember(&rememberKey, TRUE);
```
This will free all the memory blocks previously allocated with
[AllocRemember()](libraries/11-easy-memory-allocation-and-deallocation-helps-you.md) in a single call.

---

## See Also

- [AllocRemember — intuition.library](../autodocs/intuition.library.md#allocremember)
- [FreeRemember — intuition.library](../autodocs/intuition.library.md#freeremember)
