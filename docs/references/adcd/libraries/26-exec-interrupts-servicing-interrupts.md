---
title: 26 Exec Interrupts / Servicing Interrupts
manual: libraries
chapter: libraries
section: 26-exec-interrupts-servicing-interrupts
functions: []
libraries: []
---

# 26 Exec Interrupts / Servicing Interrupts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Interrupts are serviced on the Amiga through the use of interrupt [handlers](libraries/26-servicing-interrupts-interrupt-handlers.md)
and [servers](libraries/26-servicing-interrupts-interrupt-servers.md).  An interrupt handler is a system routine that exclusively
handles all processing related to a particular 4703 interrupt.  An
interrupt server is one of possibly many system routines that are invoked
as the result of a single 4703 interrupt.  Interrupt servers provide a
means of interrupt sharing. This concept is useful for general-purpose
interrupts such as vertical blanking.

At system start, Exec designates certain interrupts as handlers and others
as server chains.  The [PORTS](libraries/26-introduction-sequence-of-events-during-an-interrupt.md), [COPER](libraries/26-introduction-sequence-of-events-during-an-interrupt.md), [VERTB](libraries/26-introduction-sequence-of-events-during-an-interrupt.md), [EXTER](libraries/26-introduction-sequence-of-events-during-an-interrupt.md), and [NMI](libraries/26-introduction-sequence-of-events-during-an-interrupt.md) interrupts are
initialized as server chains.  Therefore, each of these may execute
multiple interrupt routines per each interrupt.  All other interrupts are
designated as handlers and are always used exclusively.

 [Interrupt Data Structure](libraries/26-servicing-interrupts-interrupt-data-structure.md)    [Interrupt Handlers](libraries/26-servicing-interrupts-interrupt-handlers.md) 
 [Environment](libraries/26-servicing-interrupts-environment.md)                 [Interrupt Servers](libraries/26-servicing-interrupts-interrupt-servers.md) 

