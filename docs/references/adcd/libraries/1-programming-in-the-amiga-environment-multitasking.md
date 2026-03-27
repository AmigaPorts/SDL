---
title: 1 / Programming in the Amiga Environment / Multitasking
manual: libraries
chapter: libraries
section: 1-programming-in-the-amiga-environment-multitasking
functions: []
libraries: []
---

# 1 / Programming in the Amiga Environment / Multitasking

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The key feature of the Amiga's operating system design is [multitasking](libraries/17-introduction-to-exec-multitasking.md).
Multitasking means many programs, or tasks, reside in memory at the same
time sharing system resources with one another.  Programs take turns
running so it appears that many programs are running simultaneously.

[Multitasking](libraries/17-introduction-to-exec-multitasking.md) is based on the concept that a program spends most of its
time waiting for things to happen.  A program waits for events like key
presses, mouse movement, or disk activity.  While a program is waiting,
the CPU is idle.  The CPU could be used to run a different program during
this idle period if there was a convenient method for rapidly switching
from one program to another.  This is what multitasking does.

 [What the System Does For You](libraries/1-multitasking-what-the-system-does-for-you.md) 
 [What the System Doesn't Do For You](libraries/1-multitasking-what-the-system-doesn-t-do-for-you.md) 

