---
title: exec.library/SumKickData
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-sumkickdata
functions: [SumKickData]
libraries: [exec.library]
---

# exec.library/SumKickData

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SumKickData -- compute the checksum for the Kickstart delta list
SYNOPSIS

```c
    checksum = SumKickData()
    D0

    ULONG SumKickData(void);
```
FUNCTION

```c
    The Amiga system has some ROM (or Kickstart) resident code that
    provides the basic functions for the machine.  This code is
    unchangeable by the system software.  This function is part of a
    support system to modify parts of the ROM.

    The ROM code is linked together at run time via ROMTags (also known
    as [Resident](autodocs-2.0/includes-exec-resident-h.md) structures, defined in [exec/resident.h)](autodocs-2.0/includes-exec-resident-h.md).  These tags tell
    Exec's low level boot code what subsystems exist in which regions of
    memory.  The current list of ROMTags is contained in the ResModules
    field of [ExecBase](autodocs-2.0/includes-exec-execbase-h.md).  By default this list contains any ROMTags found
    in the address ranges $F80000-$FFFFFF and $F00000-$F7FFFF.

    There is also a facility to selectively add or replace modules to the
    ROMTag list.  These modules can exist in RAM, and the memory they
    occupy will be deleted from the memory free list during the boot
    process.  SumKickData() plays an important role in this run-time
    modification of the ROMTag array.

    Three variables in [ExecBase](autodocs-2.0/includes-exec-execbase-h.md) are used in changing the ROMTag array:
    KickMemPtr, KickTagPtr, and KickCheckSum. KickMemPtr points to a
    linked list of [MemEntry](autodocs-2.0/includes-exec-memory-h.md) structures. The memory that these [MemEntry](autodocs-2.0/includes-exec-memory-h.md)
    structures reference will be allocated (via AllocAbs) at boot time.
    The [MemEntry](autodocs-2.0/includes-exec-memory-h.md) structure itself must also be in the list.

    KickTagPtr points to a long-word array of the same format as the
    ResModules array.  The array has a series of pointers to ROMTag
    structures.  The array is either NULL terminated, or will have an
    entry with the most significant bit (bit 31) set.  The most
    significant bit being set says that this is a link to another
    long-word array of ROMTag entries.  This new array's address can be
    found by clearing bit 31.

    KickCheckSum has the result of SumKickData().  It is the checksum of
    both the KickMemPtr structure and the KickTagPtr arrays.  If the
    checksum does not compute correctly then both KickMemPtr and
    KickTagPtr will be ignored.

    If all the memory referenced by KickMemPtr can't be allocated then
    KickTagPtr will be ignored.

    There is one more important caveat about adding ROMTags. All this
    ROMTag magic is run very early on in the system -- before expansion
    memory is added to the system. Therefore any memory in this
    additional ROMTag area must be addressable at this time. This means
    that your ROMTag code, [MemEntry](autodocs-2.0/includes-exec-memory-h.md) structures, and resident arrays
    cannot be in expansion memory.  There are two regions of memory that
    are acceptable:  one is chip memory, and the other is "Ranger" memory
    (memory in the range between $C00000-$D80000).

    [Remember](autodocs-2.0/includes-intuition-intuition-h.md) that changing an existing ROMTag entry falls into the
    "heavy magic" category -- be very careful when doing it.  The odd are
    that you will blow yourself out of the water.
```
NOTE

    SumKickData was introduced in the 1.2 release
RESULT

    Value to be stuffed into ExecBase->KickCheckSum.
WARNING

```c
    After writing to KickCheckSum, you should push the data cache.
    This prevents potential problems with large copyback style caches.
    A call to [CacheClearU](autodocs-2.0/exec-library-cacheclearu.md) will do fine.
```
SEE ALSO

```c
    [InitResident](autodocs-2.0/exec-library-initresident.md), [FindResident](autodocs-2.0/exec-library-findresident.md)
```

---

## See Also

- [SumKickData — exec.library](../autodocs/exec.library.md#sumkickdata)
