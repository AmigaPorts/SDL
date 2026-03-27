---
title: Amiga® Hardware Reference Manual: D System Memory Maps
manual: hardware
chapter: hardware
section: amiga-hardware-reference-manual-d-system-memory-maps
functions: [AllocMem]
libraries: [exec.library]
---

# Amiga® Hardware Reference Manual: D System Memory Maps

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A true software memory map, showing system utilization of the various
sections of RAM and free space is not provided, nor possible with the
Amiga.

All memory is dynamically allocated by the memory manager at boot time,
and the actual locations of system structures may change from
release-to-release, machine-to-machine, or boot-to-boot (see the
AllocMem() function  in the exec.library for more details).

Likewise, Amiga applications are compiled in such a way that they can be
dynamically relocated at run time by the system loader.

To find the location of system structures, application software should use
the function interface provided in the operating system.  If this is not
possible then the address of a data structure should be obtained by
searching the lists of system structures maintained by Exec.  The first
step is to fetch the address of the exec.library from location 4; this is
the only absolute memory location in the system.  All other system data
structures are indirectly linked to this base address.

Though a detailed system memory map is not possible, this section does
present the general layout of memory areas within the current generation
of Amiga computers. To ensure maximum compatibility, avoid relying on the
address ranges given here.  Instead use the system provided interfaces to
ask for the system reources you need.

 [A1000, A500 and A2000 Memory Map](hardware/d-system-memory-maps-a1000-a500-and-a2000-memory-map.md) 
 [A3000 Memory Map](hardware/d-system-memory-maps-a3000-memory-map.md) 

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
