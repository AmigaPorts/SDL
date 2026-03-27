---
title: 26 Exec Interrupts / Introduction
manual: libraries
chapter: libraries
section: 26-exec-interrupts-introduction
functions: []
libraries: []
---

# 26 Exec Interrupts / Introduction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Exec manages the decoding, dispatching, and sharing of all system
interrupts.  This includes control of hardware interrupts, software
interrupts, task-relative interrupts (see the discussion of exceptions in
the "[Exec Tasks](libraries/21-exec-tasks-task-exceptions.md)" chapter), and interrupt disabling and enabling.  In
addition, Exec supports a more extended prioritization of interrupts than
that provided in the 68000.

The proper operation of multitasking depends heavily on the consistent
management of the interrupt system.  Task activities are often driven by
intersystem communication that is originated by various interrupts.

 [Sequence of Events During an Interrupt](libraries/26-introduction-sequence-of-events-during-an-interrupt.md) 
 [Interrupt Priorities](libraries/26-introduction-interrupt-priorities.md) 
 [Nonmaskable Interrupt](libraries/26-introduction-nonmaskable-interrupt.md) 

