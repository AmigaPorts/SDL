---
title: 26 / / Interrupt Servers / Interrupt Server Register Usage
manual: libraries
chapter: libraries
section: 26-interrupt-servers-interrupt-server-register-usage
functions: []
libraries: []
---

# 26 / / Interrupt Servers / Interrupt Server Register Usage

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 D0 Scratch.

 D1 Scratch.

 A0 Scratch except in certain cases (see [note above](libraries/26-servicing-interrupts-interrupt-servers.md)).

 A1 Points to the data area specified by the [is_Data](libraries/26-servicing-interrupts-interrupt-data-structure.md) field of the

```c
    [Interrupt](libraries/26-servicing-interrupts-interrupt-data-structure.md) structure.  Because this pointer is always fetched
    (regardless of whether you use it), it is to your advantage to make
    some use of it (scratch).
```
 A5 Points to your interrupt code (scratch).

 A6 Scratch.

In a server chain, the interrupt is cleared automatically by the system.
Having a server clear its interrupt is not recommended and not necessary
(clearing could cause the loss of an interrupt on [PORTS](libraries/26-introduction-sequence-of-events-during-an-interrupt.md) or [EXTER](libraries/26-introduction-sequence-of-events-during-an-interrupt.md)).

Here is an example of a program to install and remove a low-priority
vertical blank interrupt server:


```c
     [vertb.c](libraries/lib-examples-vertb-c.md) 
```
This is the assembler VertBServer installed by the C example:


```c
     [vertbserver.asm](libraries/lib-examples-vertbserver-asm.md) 
```
