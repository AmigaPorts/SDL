---
title: 32 Expansion Library / Function Reference
manual: libraries
chapter: libraries
section: 32-expansion-library-function-reference
functions: []
libraries: []
---

# 32 Expansion Library / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the expansion library functions
that are useful for expansion device drivers and related applications.
See the Amiga ROM Kernel Reference Manual: Includes and Autodocs for the
complete descriptions of all the expansion library functions.


                 Table 32-2: Expansion Library Functions
  ______________________________________________________________________
 |                                                                      |
 |            Function                 Description                      |
 |======================================================================|
 |          [FindConfigDev()](autodocs-2.0/expansion-library-findconfigdev.md)  Returns a pointer to the [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md)         |
 |                           structure of a given expansion device.     |
 |----------------------------------------------------------------------|
 |            [MakeDosNode()](autodocs-2.0/expansion-library-makedosnode.md)  Creates the DOS device node for disk and   |
 |                           similar expansion devices.                 |
 |             [AddDosNode()](autodocs-2.0/expansion-library-adddosnode.md)  Adds a DOS device node to the system.      |
 |            [AddBootNode()](autodocs-2.0/expansion-library-addbootnode.md)  Adds an [autobooting](libraries/32-expansion-board-drivers-rom-based-and-autoboot-drivers.md) DOS device node to the |
 |                           system (V36).                              |
 |----------------------------------------------------------------------|
 |      [GetCurrentBinding()](autodocs-2.0/expansion-library-getcurrentbinding.md)  Returns a pointer to the CurrentBinding    |
 |                           structure of a given device.               |
 |      [SetCurrentBinding()](autodocs-2.0/expansion-library-setcurrentbinding.md)  Set up for reading the CurrentBinding with |
 |                           GetCurrentBinding().                       |
 |    [ObtainConfigBinding()](autodocs-2.0/expansion-library-obtainconfigbinding.md)  Protect the [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) structure with a     |
 |                           semaphore.                                 |
 |   [ReleaseConfigBinding()](autodocs-2.0/expansion-library-releaseconfigbinding.md)  Release a semaphore on ConfigDev set up    |
 |                           with ObtainCurrentBinding().               |
 |______________________________________________________________________|

