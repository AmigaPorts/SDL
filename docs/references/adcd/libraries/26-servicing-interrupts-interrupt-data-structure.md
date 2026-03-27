---
title: 26 / Servicing Interrupts / Interrupt Data Structure
manual: libraries
chapter: libraries
section: 26-servicing-interrupts-interrupt-data-structure
functions: []
libraries: []
---

# 26 / Servicing Interrupts / Interrupt Data Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Interrupt handlers and servers are defined by the Exec [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md)
structure.  This structure specifies an interrupt routine entry point and
data pointer.  The C definition of this structure is as follows:


```c
    struct Interrupt
    {
        struct Node is_Node;
        APTR        is_Data;
        VOID      (*is_Code)();
    };
```
Once this structure has been properly initialized, it can be used for
either a handler or a server.

