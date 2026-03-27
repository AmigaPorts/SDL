---
title: D / Errors / Crashes--Subtasks, Interrupts
manual: libraries
chapter: libraries
section: d-errors-crashes-subtasks-interrupts
functions: []
libraries: []
---

# D / Errors / Crashes--Subtasks, Interrupts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If part of your code runs on a different stack or the system stack, you
must turn off compiler stack-checking options.  If part of your code is
called directly by the system or by other tasks, you must use long
code/long data or use special compiler flags or options to assure that the
correct base registers are set up for your subtask or interrupt code.

