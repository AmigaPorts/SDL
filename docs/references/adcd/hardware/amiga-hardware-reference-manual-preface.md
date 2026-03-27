---
title: Amiga® Hardware Reference Manual: Preface
manual: hardware
chapter: hardware
section: amiga-hardware-reference-manual-preface
functions: []
libraries: []
---

# Amiga® Hardware Reference Manual: Preface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga Technical Reference Series is the official guide to programming
Amiga computers.  This revised edition of the Amiga Hardware
Reference Manual provides detailed information about the Amiga's graphics
and audio hardware, and how the Amiga talks to the outside world through
peripheral devices. This edition has been updated for version 2.0 of the
Amiga operating system and covers the newest Amiga computer systems
including the A3000.

This book is intended for the following audiences:

   *  Assembly language programmers who need a more direct way of

      interacting with the Amiga than the routines provided in the system
      software.
   *  Designers who want to interface new peripherals to the Amiga.

   *  Anyone who wants to know how the Amiga hardware works.


Here is a brief overview of the contents:



```c
       [Chapter 1, Introduction](hardware/amiga-hardware-reference-manual-1-introduction.md) . An overview of the hardware and
      survey of the Amiga's graphics and audio features.

       [Chapter 2, Coprocessor Hardware](hardware/amiga-hardware-reference-manual-1-introduction.md) . Using the Copper coprocessor
      to control the entire graphics and audio system; directing
      mid-screen modifications in graphics displays and directing
      register changes during the time between displays.

       [Chapter 3, Playfield Hardware](hardware/amiga-hardware-reference-manual-1-introduction.md) . Creating, displaying and
      scrolling the playfields, one of the basic display elements of
      the Amiga; how the Amiga produces multi-color, bitmapped
      displays.

       [Chapter 4, Sprite Hardware](hardware/amiga-hardware-reference-manual-1-introduction.md) . Using the eight sprite direct
      memory access (DMA) channels to make sprite movable objects;
      creating their data structures, displaying and moving them,
      reusing the DMA channels.

       [Chapter 5, Audio Hardware](hardware/amiga-hardware-reference-manual-1-introduction.md) . Overview of sampled sound; how to
      produce quality sound, simple and complex sounds, and modulated
      sounds.

       [Chapter 6, Blitter Hardware](hardware/amiga-hardware-reference-manual-1-introduction.md) . Using the blitter DMA channel to
      create animation effects and draw lines into playfields.

       [Chapter 7, System Control Hardware](hardware/amiga-hardware-reference-manual-1-introduction.md) . Using the control
      registers to define depth arrangement of graphics objects,
      detect collisions between graphics objects, control direct
      memory access, and control interrupts.

       [Chapter 8, Interface Hardware](hardware/amiga-hardware-reference-manual-1-introduction.md) . How the Amiga talks to the
      outside world through controller ports, keyboard, audio jacks
      and video connectors, serial and parallel interfaces;
      information about the disk controller and RAM expansion slot.

      Appendices. Alphabetical and address-order listings of all the
      graphics and audio system registers and the functions of their
      bits. Also included is a special section on the Amiga's Enhanced
      Chip Set (ECS), system memory maps, descriptions of internal and
      external connectors, specifications for the peripheral interface
      ports, keyboard, and an introduction to the Amiga's Zorro
      expansion bus with detailed specifications for hardware add-on
      designers.
```
We suggest that you use this book according to your level of familiarity
with the Amiga system.  Here are some suggestions:

   *  If this is your initial exposure to the Amiga, read chapter 1, which

      gives a survey of all the hardware features and a brief rundown of
      graphics and audio effects created by hardware interaction.
   *  If you are already familiar with the system and want to acquaint

      yourself with how the various bits in the hardware registers govern
      the way the system functions, browse through chapters 2 through 8.
      Examples are included in these chapters.
   *  For advanced users, the appendices give a concise summary of the


      entire register set and the uses of the individual bits.  Once you
      are familiar with the effects of changes in the various bits, you may
      wish to refer more often to the appendices than to the explanatory
      chapters.
The other manuals in this series are the Amiga User Interface Style Guide,
an application design specification and reference work for Amiga
programmers, the Amiga ROM Kernel Reference Manual: Includes and Autodocs,
an alphabetically organized reference of ROM function summaries and Amiga
system include files, the Amiga ROM Kernel Reference Manual: [Libraries](libraries/contents.md) 
and the Amiga ROM Kernel Reference Manual: [Devices](devices/contents-2.md)  with tutorial-style
chapters on the use of each Amiga system library and device.

