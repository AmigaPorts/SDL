---
title: K / / Changes from A2000 Bus / Bus Memory Mapping and Cache Support
manual: hardware
chapter: hardware
section: k-changes-from-a2000-bus-bus-memory-mapping-and-cache
functions: []
libraries: []
---

# K / / Changes from A2000 Bus / Bus Memory Mapping and Cache Support

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Another change to the Zorro II implementation is that the  [bus mapping](hardware/d-system-memory-maps-a3000-memory-map.md) 
logic works a little differently.  Zorro II address space is broken up
into memory and I/O address space.  Memory space is the standard 8
megabyte space from $00200000-$009FFFFF.  The I/O address space is mapped
at $00E80000-$00EFFFFF, and a new 1.5 megabyte section (previously
reserved for motherboard devices) from $00A00000-$00B7FFFF.  Zorro II
cycles are not generated for non-Zorro II address space, even for 68000
space resources on the local bus.  So, for example, a CPU access to chip
memory would be visible to a Zorro II PIC in an A2000 backplane, but
invisible to that same PIC in an A3000 backplane.  Since this extra
information on the Zorro II backplane can't be legally used by any PIC
anyway, it should not be used by any existing A2000 PICs.

The reason for the two distinct mapping regions is for  [cache support](hardware/k-advanced-mode-support-logic-cache-support.md)  of
Zorro II PICs.  All access by the local bus* master to Zorro II memory
space results in the local bus cache enable signal being driven and a full
port read (e.g., both bytes) regardless of the actual data transfer size
being requested.  A local bus access to Zorro II I/O space results in the
local bus cache disable signal being driven and the data strobes for reads
indicating the requested transfer size.  This cache mapping mechanism was
first implemented in the A2630 coprocessor card, so it's not an entirely
new concept.

 * The local bus, motherboard bus, and CPU bus are the same thing; the
   immediate 680x0 bus connected directly to the CPU in an Amiga
   computer. Current Amiga computers typically support three distinct
   buses; the expansion bus, local bus, and chip bus.  From the point of
   view of the expansion bus, the local and chip buses appear as a
   unified device which may be master or slave to the expansion bus.

