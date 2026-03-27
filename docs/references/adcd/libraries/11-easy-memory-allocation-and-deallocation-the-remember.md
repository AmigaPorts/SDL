---
title: 11 / Easy Memory Allocation and Deallocation / The Remember Structure
manual: libraries
chapter: libraries
section: 11-easy-memory-allocation-and-deallocation-the-remember
functions: []
libraries: []
---

# 11 / Easy Memory Allocation and Deallocation / The Remember Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Remember structure is defined in <intuition/[intuition](autodocs-2.0/includes-intuition-intuition-h.md)> as follows:


```c
    struct Remember
        {
        struct Remember *NextRemember;
        ULONG RememberSize;
        UBYTE *Memory;
        };
```
Generally, the Remember structure is handled only by the system.  Here are
its fields:


    NextRemember - The link to the next Remember structure.
    RememberSize - The size of the memory tracked by this node.
    Memory       - A pointer to the memory tracked by this node.
