---
title: intuition.library/AllocRemember
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-allocremember
functions: [AllocMem, AllocRemember, FreeRemember]
libraries: [exec.library, intuition.library]
---

# intuition.library/AllocRemember

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AllocRemember -- [AllocMem()](autodocs-2.0/exec-library-allocmem.md) with tracking to make freeing easy.
```
SYNOPSIS

```c
    MemBlock = AllocRemember( RememberKey, Size, Flags )
    D0                        A0           D0    D1

    APTR AllocRemember( struct [Remember](autodocs-2.0/includes-intuition-intuition-h.md) **, ULONG, ULONG );
```
FUNCTION
```c
    This routine calls the Exec [AllocMem()](autodocs-2.0/exec-library-allocmem.md) function for you, but also links
    the parameters of the allocation into a master list, so that
    you can simply call the Intuition routine [FreeRemember()](autodocs-2.0/intuition-library-freeremember.md) at a later
    time to deallocate all allocated memory without being required to
    remember the details of the memory you've allocated.

    This routine will have two primary uses:
```
   -   Let's say that you're doing a long series of allocations in a

       procedure.  If any one of the allocations fails, your program
        may need to abort the procedure.  Abandoning ship correctly
        involves freeing up what memory you've already allocated.  This
        procedure allows you to free up that memory easily, without being
        required to keep track of how many allocations you've already done,
        what the sizes of the allocations were, or where the memory was
        allocated.
   -   Also, in the more general case, you may do all of the allocations


```c
       in your entire program using this routine.  Then, when your
       program is exiting, you can free it all up at once with a
       simple call to [FreeRemember()](autodocs-2.0/intuition-library-freeremember.md).

    You create the "anchor" for the allocation master list by creating
    a variable that's a pointer to struct [Remember](autodocs-2.0/includes-intuition-intuition-h.md), and initializing
    that pointer to NULL.  This is called the RememberKey.  Whenever
    you call AllocRemember(), the routine actually does two memory
    allocations, one for the memory you want and the other for a copy
    of a [Remember](autodocs-2.0/includes-intuition-intuition-h.md) structure.  The [Remember](autodocs-2.0/includes-intuition-intuition-h.md) structure is filled in
    with data describing your memory allocation, and it's linked
    into the master list pointed to by your RememberKey.  Then, to
    free up any memory that's been allocated, all you have to do is
    call [FreeRemember()](autodocs-2.0/intuition-library-freeremember.md) with your RememberKey.

    Please read the [FreeRemember()](autodocs-2.0/intuition-library-freeremember.md) function description, too.  As you will
    see, you can select either to free just the link nodes and keep all the
    allocated memory for yourself, or to free both the nodes and your
    memory buffers.
```
INPUTS

```c
    RememberKey = the address of a pointer to struct [Remember](autodocs-2.0/includes-intuition-intuition-h.md).  Before the
    very first call to AllocRemember, initialize this pointer to NULL.

    Size = the size in bytes of the memory allocation.  Please refer to the
        [exec.library/AllocMem()](autodocs-2.0/exec-library-allocmem.md) function for details.
    Flags = the specifications for the memory allocation.  Please refer to
        the [exec.library/AllocMem()](autodocs-2.0/exec-library-allocmem.md) function for details.
```
EXAMPLE

```c
    struct [Remember](autodocs-2.0/includes-intuition-intuition-h.md) *RememberKey;
    RememberKey = NULL;
    buffer = AllocRemember(&RememberKey, BUFSIZE, MEMF_CHIP);
    if (buffer)
    {
        /* Use the buffer */
        ...
    }
    FreeRemember(&RememberKey, TRUE);
```
RESULT

    If the memory allocation is successful, this routine returns the byte
    address of your requested memory block.  Also, the node to your block
    will be linked into the list pointed to by your RememberKey variable.
    If the allocation fails, this routine returns NULL and the list pointed
    to by RememberKey, if any, will be unchanged.
BUGS

```c
    This function makes two allocations for each memory buffer
    you request.  This is neither fast nor good for memory
    fragmentation.

    This function should use the exec AllocPool() function internally,
    at least for the [Remember](autodocs-2.0/includes-intuition-intuition-h.md) headers.
```
SEE ALSO

```c
    [FreeRemember()](autodocs-2.0/intuition-library-freeremember.md), [exec.library/AllocMem()](autodocs-2.0/exec-library-allocmem.md)
```

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [AllocRemember — intuition.library](../autodocs/intuition.library.md#allocremember)
- [FreeRemember — intuition.library](../autodocs/intuition.library.md#freeremember)
