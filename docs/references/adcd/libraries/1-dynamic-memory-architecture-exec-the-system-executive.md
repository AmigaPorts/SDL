---
title: 1 / / Dynamic Memory Architecture / Exec: The System Executive
manual: libraries
chapter: libraries
section: 1-dynamic-memory-architecture-exec-the-system-executive
functions: []
libraries: []
---

# 1 / / Dynamic Memory Architecture / Exec: The System Executive

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

On the Amiga, the module that keeps track of linked lists is [Exec](libraries/17-introduction-to-exec.md), the
system executive.  Exec is the heart of the Amiga operating system since
it also is in charge of [multitasking](libraries/1-programming-in-the-amiga-environment-multitasking.md), granting access to system resources
(like memory) and managing the Amiga library system.

As [previously discussed](libraries/1-libraries-of-functions-opening-a-library-in-assembler.md), memory location 4 ($0000 0004), also known as
SysBase, contains a [pointer](libraries/26-interrupt-handlers-interrupt-handler-register-usage.md) to the [Exec library](libraries/18-exec-libraries.md) structure.  This is the
only absolutely defined location in the Amiga operating system.  A program
need only know where to find the Exec library to find, use and manipulate
all other system code and data.


                             $04 Sysbase
                                  |
                                  |
                             Exec Library
                                  |
     _____________________________|_____________________________
    |         |         |         |         |         |         |
    |         |         |         |         |         |         |
LIBRARIES  DEVICES    MEMORY  RESOURCES   INTS      PORTS     TASKS
    |         |         |         |         |         |         |
   DOS    Trackdisk   Chunk 1   Potgo      END      IDCMP       |
    |         |         |         |                   |         |
Graphics    Serial    Chunk 2   Keymap              IDCMP      / \
    |         |         |         |                   |       /   \
Intuition  Parallel    END      CIAA              Workbench  /     \
    |         |                   |                   |     /    WAITING
Expansion  Printer              CIAB                 END   /        |
    |         |                   |                       /    File System
  Layers    Input               Disk                     /          |
    |         |                   |                   READY    File System
 Mathffp   Keyboard             MISC                    |           |
    |         |                   |                   Shell    Input.device
   Icon    Gameport              END                    |           |
    |         |                                        RAM         END
 Diskfont   Timer                                       |
    |         |                                    Application
   END      Audio                                    Task 1


              |                                         |
           Console                                 Application
              |                                      Task 2
             END                                        |
                                                       END


         Figure 1-3: Exec and the Organization of the Amiga OS
The diagram above shows how the entire Amiga operating system is built as
a tree starting at SysBase.  Exec keeps linked lists of all the system
libraries, devices, memory, tasks and other data structures.  Each of
these in turn can have its own variables and linked lists of data
structures built onto it.  In this way, the flexibility of the OS is
preserved so that upgrades can be made without jeopardizing [compatibility](libraries/1-introduction-to-amiga-system-libraries-1-3-compatibility.md).
  _______________________________________________________________________
 |                                                                       |
 | What Every Amiga Programmer Should Know:                              |
 | ----------------------------------------                              |
 | The Amiga has a [dynamic memory](libraries/1-programming-in-the-amiga-environment-dynamic-memory.md) map.  There are no fixed locations for |
 | operating system variables and routines.  Do not call ROM routines or |
 | access system data structures directly.  Instead use the indirect     |
 | access methods provided by the system.                                |
 |_______________________________________________________________________|

