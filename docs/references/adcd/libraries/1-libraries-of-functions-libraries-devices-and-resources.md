---
title: 1 / / Libraries of Functions / Libraries, Devices and Resources
manual: libraries
chapter: libraries
section: 1-libraries-of-functions-libraries-devices-and-resources
functions: [OpenLibrary]
libraries: [exec.library]
---

# 1 / / Libraries of Functions / Libraries, Devices and Resources

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Most of the Amiga's OS routines are organized into groups of shared
[run-time](libraries/1-libraries-of-functions-another-kind-of-function-library.md) libraries.  The Amiga also has specialized function groups called
devices and resources that programmers use to perform basic I/O operations
or access low-level hardware.

Devices and resources are similar in concept to a shared [run-time](libraries/1-libraries-of-functions-another-kind-of-function-library.md) library.
They are managed by [Exec](libraries/1-dynamic-memory-architecture-exec-the-system-executive.md) and must be opened before they can be used.
Their functions are separate from the programs that use them and are
accessed dynamically at run time.  Multiple programs can access the device
or resource even though only one copy exists in memory (a few resources
can only be used by one program at a time.)

   ________________      ________________
  |                |    |                |
  | AmigaDOS CLI   |    |   Workbench    |
  | & utilities    |    | Icons/Drawers/ |
  |                |    |   Utilities    |
  |________________|    |________________|
         |   |_________       |   |
         |    _________|______|   |
         |   |      ___|____      |
         |   |     /        \     |
         |   |    / Console  \    |
         |   |   |  Device    |   |
         |   |    \          /    |
         |   |     \________/     |
         |   |         |______    |
   ______|___|_____        ___|___|________
  |                |      |                |
  |   AmigaDOS     |      |   Intuition    |
  |   Processes,   |      | Windows,Menus  |
  |  File System   |      | Gadgets,Events |
  |________________|      |________________|
         |              ______|   |   |______
         |          ___|____      |   _______|________
         |         /        \     |  |                |
         |        /  Input   \    |  |    Layers      |
         |       |   Device   |   |  |    Library     |
         |        \          /    |  |                |
         |         \________/     |  |________________|
         |             |          |    ______|
         |             |     _____|___|______
         |             |    |                |
         |             |    |    Graphics    |
         |             |    |   Rendering    |
         |             |    |   Text, Gels   |
         |             |    |________________|
     ____|___       ___|____        |         ________       ________
    /        \     /        \       |        /        \     /        \
   /  SCSI &  \   / Keyboard \      |       /  Audio   \   /  Serial  \
  | Trackdisk  | | & Gameport |     |      |   Device   | | & Parallel |
   \  Device  /   \  Devices /      |       \          /   \  Devices /
    \________/     \________/       |        \________/     \________/
         |             |            |             |              |
   ______|_____________|____________|_____________|______________|______
  |                                                                     |
  |    Exec: Tasks, Messages, Interrupts, I/O, Libraries and Devices    |
  |_____________________________________________________________________|
         |             |            |             |            |
   ______|_____________|____________|_____________|____________|________
  |              |            |             |             |             |
  | Disk Control |  Keyboard  |  Graphics   |    Audio    |  I/O Ports  |
  |              |  & Mouse   |             |             |             |
  |______________|____________|_____________|_____________|_____________|




                Figure 1-1: Amiga System Software Hierarchy
Devices and resources are managed by [Exec](libraries/1-dynamic-memory-architecture-exec-the-system-executive.md) just as libraries are.  For more
information on devices and resources, see the chapter on [Exec Device I/O](libraries/19-exec-device-i-o.md)
later in this book or refer to the Amiga ROM Kernel Reference Manual:
[Devices](devices/contents-2.md) for detailed descriptions of each device.
  _____________________________________________________________________
 |                                                                     |
 | What Every Amiga Programmer Should Know:                            |
 | ----------------------------------------                            |
 | The functions in the Amiga OS are accessed through shared [run-time](libraries/1-libraries-of-functions-another-kind-of-function-library.md)  |
 | libraries.  Libraries must be opened before their functions may be  |
 | used.  The system's master library, [Exec](libraries/1-dynamic-memory-architecture-exec-the-system-executive.md), is always open.  The Exec |
 | function [OpenLibrary()](libraries/1-programming-in-the-amiga-environment-libraries-of.md) is used to open all other libraries.         |
 |_____________________________________________________________________|

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
