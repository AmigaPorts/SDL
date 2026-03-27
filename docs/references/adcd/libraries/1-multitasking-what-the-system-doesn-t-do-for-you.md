---
title: 1 / / Multitasking / What the System Doesn't Do For You
manual: libraries
chapter: libraries
section: 1-multitasking-what-the-system-doesn-t-do-for-you
functions: []
libraries: []
---

# 1 / / Multitasking / What the System Doesn't Do For You

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga operating system handles most of the housekeeping needed for
[multitasking](libraries/17-introduction-to-exec-multitasking.md), but this does not mean that applications don't have to worry
about multitasking at all.  The current generation of Amiga systems do not
have hardware memory protection, so there is nothing to stop a task from
using memory it has not legally acquired.  An errant task can easily
corrupt some other task by accidentally overwriting its instructions or
data.  Amiga programmers need to be extra careful with memory; one bad
memory pointer can cause the machine to [crash](libraries/d-errors-crashes-and-memory-corruption.md) (debugging utilities such as
MungWall and Enforcer will prevent this).

In fact, Amiga programmers need to be careful with every system resource,
not just memory.  All system resources from audio channels to the floppy
disk drives are shared among tasks.  Before using a resource, you must ask
the system for access to the resource.  This may fail if the resource is
already being used by another task.

Once you have control of a resource, no other task can use it, so give it
up as soon as you are finished.  When your program exits, you must give
everything back whether it's memory, access to a file, or an I/O port. You
are responsible for this, the system will not do it for you automatically.
  ______________________________________________________________________
 |                                                                      |
 | What Every Amiga Programmer Should Know:                             |
 | ----------------------------------------                             |
 | The Amiga is a [multitasking](libraries/17-introduction-to-exec-multitasking.md) computer.  Keep in mind that other       |
 | tasks are running at the same time as your application.  Always ask  |
 | the system for control of any resource you need; some other task may |
 | already be using it.  Give it back as soon as you are done; another  |
 | task may want to use it.  This applies to just about every computing |
 | activity your application can perform.                               |
 |______________________________________________________________________|

