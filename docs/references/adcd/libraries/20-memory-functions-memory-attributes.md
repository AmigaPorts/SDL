---
title: 20 / Memory Functions / Memory Attributes
manual: libraries
chapter: libraries
section: 20-memory-functions-memory-attributes
functions: []
libraries: []
---

# 20 / Memory Functions / Memory Attributes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When asking the system for memory, an application can ask for memory with
certain attributes.  The currently supported flags are listed below. Flags
marked "V37" are new memory attributes for Release 2.  Allocations which
specify these new bits may fail on earlier systems.

MEMF_ANY

    This indicates that there is no requirement for either Fast or Chip
    memory.  In this case, while there is Fast memory available, Exec
    will only allocate Fast memory.  Exec will allocate Chip memory if
    there is not enough Fast memory.
MEMF_CHIP

    This indicates the application wants a block of chip memory, meaning
    it wants memory addressable by the Amiga custom chips.  Chip memory
    is required for any data that will be accessed by custom chip DMA.
    This includes screen memory, images that will be blitted, sprite
    data, copper lists, and audio data, and pre-V37 floppy disk buffers.
    If this flag is not specified when allocating memory for these types
    of data, your code will fail on machines with expanded memory.
MEMF_FAST

    This indicates a memory block outside of the range that the special
    purpose chips can access.  "FAST" means that the special-purpose
    chips do not have access to the memory and thus cannot cause
    processor bus contention, therefore processor access will likely be
    faster.  Since the flag specifies memory that the custom chips cannot
    access, this flag is mutually exclusive with the MEMF_CHIP flag.  If
    you specify the MEMF_FAST flag, your allocation will fail on any
    Amiga that has only CHIP memory.  Use MEMF_ANY if you would prefer
    FAST memory.
MEMF_PUBLIC

```c
    This indicates that the memory should be accessible to other tasks.
    Although this flag doesn't do anything right now, using this flag
    will help ensure compatibility with possible future features of the
    OS (like virtual memory and memory protection).
```
MEMF_CLEAR

    This indicates that the memory should be initialized with zeros.
MEMF_LOCAL (V37)

    This indicates memory which is located on the motherboard which is
    not initialized on reset.
MEMF_24BITDMA (V37)

    This indicates that the memory should be allocated within the 24 bit
    address space, so that the memory can be used in Zorro-II expansion
    device DMA transactions.  This bit is for use by Zorro-II DMA devices
    only.  It is not for general use by applications.
MEMF_REVERSE (V37)

    Indicates that the memory list should be searched backwards for the
    highest address memory chunk which can be used for the memory
    allocation.
If an application does not specify any attributes when allocating memory,
the system tries to satisfy the request with the first memory available on
the system memory lists, which is MEMF_FAST if available, followed by
MEMF_CHIP.


    Make Sure You Have Memory.
    --------------------------
    Always check the result of any memory allocation to be sure the type
    and amount of memory requested is available.  Failure to do so will
    lead to trying to use an non-valid pointer.
