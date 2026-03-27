---
title: 1 / Programming in the Amiga Environment / The Custom Chips
manual: libraries
chapter: libraries
section: 1-programming-in-the-amiga-environment-the-custom-chips
functions: []
libraries: []
---

# 1 / Programming in the Amiga Environment / The Custom Chips

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The most important feature of the Amiga's hardware design is the set of
custom chips that perform specialized tasks independently of the CPU. Each
of the custom chips (named Paula, Agnus, and Denise) is dedicated to a
particular job:

Paula   (8364)            Audio, floppy disk, serial, interrupts
Agnus   (8361/8370/8372)  [Copper](libraries/27-introduction-role-of-the-copper-coprocessor.md) (video coprocessor), blitter, DMA control
Denise  (8362)            Color registers, color DACs (Digital to Analog

```c
                          Converters) and sprites
```
The custom chips can perform work independently of the CPU because they
have DMA, or Direct Memory Access, capability.  DMA means the custom chips
can access special areas of memory by themselves without any CPU
involvement.  (On computer systems without DMA, the CPU must do some or
all of the memory handling for support chips.)  The Amiga's custom chips
make [multitasking](libraries/1-programming-in-the-amiga-environment-multitasking.md) especially effective because they can handle things like
rendering graphics and playing sound independently, giving the CPU more
time to handle the overhead of [task-switching](libraries/1-multitasking-what-the-system-does-for-you.md) and other important jobs.

 [Custom Chip Revisions](libraries/1-the-custom-chips-custom-chip-revisions.md)    [Two Kinds of Memory](libraries/1-the-custom-chips-two-kinds-of-memory.md) 

