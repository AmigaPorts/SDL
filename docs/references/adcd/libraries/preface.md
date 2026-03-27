---
title: Preface
manual: libraries
chapter: libraries
section: preface
functions: []
libraries: []
---

# Preface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This edition of the Amiga ROM Kernel Reference Manual: Libraries provides
the latest information on how to program the Amiga line of personal
computers.  It has been updated for Release 2 of the Amiga
operating system and covers the newest Amiga computer systems including
the A3000.

This book is meant to help you learn how to program the Amiga.  It assumes
some previous experience with programming and familiarity with computers
in general.  Although it is not required, a knowledge of the C programming
language will make it much easier to understand the material in this book.
Most of the Amiga operating system is written in C (with the rest written
in 68000 assembly language), hence C is the language used for the
programming examples.

This book is intended for the following audiences:

   *  C and assembly language programmers who want to create

      application software for the Amiga line of personal computers.
   *  Amiga software developers who want to upgrade their software for

      Release 2 of the operating system.
   *  Anyone who wants to know more about how the Amiga system

      software works.
The Amiga system software is organized into related groups of functions
called libraries.  The same organization is used for this book.  Here is a
brief overview of the contents:

   *  Chapter 1, [Introduction to Amiga System Libraries](libraries/1-introduction-to-amiga-system-libraries.md). A look at

      the Amiga software and hardware architecture with an introduction
      to the basic elements of Amiga programming.
   *  Chapters 2-16, [User Interface Libraries](libraries/user-interface-libraries.md). An in-depth tutorial

      on how to create a graphic user interface for Amiga application
      software using Intuition and related modules including GadTools,
      Workbench, BOOPSI and ASL.
   *  Chapters 17-26, [Exec Library](libraries/exec-library.md). The details on how Exec,

      the system's master module, controls the system with working
      examples of interrupt processing code, subtask creation, lists
      and queues, semaphores, message passing and signalling.
   *  Chapters 27-30, [Graphic Libraries](libraries/graphics-libraries.md). A complete explanation of

      the functions in the graphic and layers library that drive the
      Amiga's display hardware with examples of text rendering, line
      drawing, animation and more.
   *  Chapters 31-37, [Additional Libraries](libraries/additional-libraries.md). Tutorials on how to

      use the Amiga commodities, DOS, IFFParse, keymap, translator
      and other important libraries in the operating system.
   *  [Appendices](libraries/appendices.md). Special sections containing a debugging and

      troubleshooting guide plus a working example library for
      programmers who want to extend the capabilities of the operating
      system.
We suggest that you use this book according to your level of familiarity
with the Amiga system.  Beginners should read the first four chapters and
try the examples to get the basics.  Then browse through the Exec chapters
to get a deeper understanding of how the system works.

Advanced Amiga programmers should read the chapters on new libraries like
 [IFFParse](libraries/33-iffparse-library.md)  and [GadTools](libraries/15-gadtools-library.md) to find out what's new in Release 2.  Also be
sure to review the new [Utility library](libraries/37-utility-library.md) to see how tag item lists have
been used to implement many of the system improvements in Release 2.

There are four other manuals in the Amiga Technical Reference Series.  The
Amiga ROM Kernel Reference Manual:[Devices](devices/contents-2.md) is a companion book to this
volume detailing how to write code for the Amiga's lower level I/O
hardware.  The Amiga ROM Kernel Reference Manual: Includes and Autodocs is
an alphabetically organized reference of ROM function summaries and system
include files.  Both these books are required reading for the serious
programmer.

Also available are the Amiga User Interface Style Guide, an application
design specification and reference work describing how a standard Amiga
application should look and feel; and the Amiga [Hardware](hardware/amiga-hardware-reference-manual-contents.md) Reference
Manual, an in-depth description of the custom chips and other hardware
components underlying the Amiga's sophisticated design.

