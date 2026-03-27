---
title: 15 Resources / BattMem Resource
manual: devices
chapter: devices
section: 15-resources-battmem-resource
functions: []
libraries: []
---

# 15 Resources / BattMem Resource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The battery-backed memory (BattMem) preserves a small portion of Amiga
memory while the system is powered off.  Some of the information stored in
this memory is used during the system boot sequence.

The battmem resource provides access to the BattMem.  Four functions allow
you to use the BattMem.


```c
                              BattMemResource Functions
                              -------------------------
     [ObtainBattSemaphore()](autodocs-2.0/battmem-resource-obtainbattsemaphore.md)    Obtain exclusive access to the BattMem.

     [ReadBattMem()](autodocs-2.0/battmem-resource-readbattmem.md)            Read a bitstring from the BattMem.  You
                              specify the bit position and the number of
                              bits you wish to read.

     [ReleaseBattSemaphore()](autodocs-2.0/battmem-resource-releasebattsemaphore.md)   Relinquish exclusive access to the BattMem.

     [WriteBattMem()](autodocs-2.0/battmem-resource-writebattmem.md)           Write a bitstring to the BattMem.  You
                              specify the bit position and the number of
                              bits you wish to write.
```
The system considers BattMem to be a set of bits rather than bytes. This
is done to conserve the limited space available. All bits are reserved,
and applications should not read, or write undefined bits. Writing bits
should be done with extreme caution since the settings will survive
power-down/power-up. You can find the bit definitions in the BattMem
include files resources/[battmembitsamiga.h](autodocs-2.0/includes-resources-battmembitsamiga-h.md), resources/[battmembitsamix.h](autodocs-2.0/includes-resources-battmembitsamix-h.md)
and resources/[battmembitsshared.h](autodocs-2.0/includes-resources-battmembitsshared-h.md). They should be consulted before you do
anything with the resource.

   You Don't Need This Resource.
   -----------------------------
   The BattMem resource is basically for system use only.  There is
   generally no reason for applications to use it. It is documented here
   simply for completeness.

Additional information on the battmem resource can be found in the include
files and the Autodocs for the battmem resource.


```c
                        BattMem Resource Information
                --------------------------------------------
                INCLUDES        resources/[battmem.i](autodocs-2.0/includes-resources-battmem-i.md)
                                resources/[battmembitsamiga.h](autodocs-2.0/includes-resources-battmembitsamiga-h.md)
                                resources/[battmembitsamix.h](autodocs-2.0/includes-resources-battmembitsamix-h.md)
                                resources/[battmembitsshared.h](autodocs-2.0/includes-resources-battmembitsshared-h.md)
                AUTODOCS        [battmem.doc](autodocs-2.0/battmem-doc.md)
```
