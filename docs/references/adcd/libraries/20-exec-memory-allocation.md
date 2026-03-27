---
title: 20 Exec Memory Allocation
manual: libraries
chapter: libraries
section: 20-exec-memory-allocation
functions: []
libraries: []
---

# 20 Exec Memory Allocation

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Exec manages all of the free memory currently available in the system.
Using linked list structures, Exec keeps track of memory and provides the
functions to allocate and access it.

When an application needs some memory, it can either declare the memory
statically within the program or it can ask Exec for some memory.  When
Exec receives a request for memory, it looks through its list of free
memory regions to find a suitably sized block that matches the size and
attributes requested.

 [Memory Functions](libraries/20-exec-memory-allocation-memory-functions.md)                     [Other Memory Functions](libraries/20-exec-memory-allocation-other-memory-functions.md) 
 [Allocating Multiple Memory Blocks](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md)    [Function Reference](libraries/20-exec-memory-allocation-function-reference.md) 

