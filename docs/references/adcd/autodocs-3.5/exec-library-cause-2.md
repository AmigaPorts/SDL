---
title: exec.library/Cause
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-cause-2
functions: []
libraries: []
---

# exec.library/Cause

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       Cause -- cause a software interrupt
   SYNOPSIS
```c
       Cause(interrupt)
```
	     A1


```c
       void Cause(struct [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) *);
```
   FUNCTION
	This function causes a software interrupt to occur.  If it is
	called from user mode (and processor level 0), the software
	interrupt will preempt the current task.  This call is often used
	by high-level hardware interrupts to defer medium-length processing
	down to a lower interrupt level.  Note that a software interrupt is
	still a real interrupt, and must obey the same restrictions on what
	system function it may call.

	Currently only 5 software interrupt priorities are implemented:
	-32, -16, 0, +16, and +32.  Priorities in between are truncated,
	values outside the -32/+32 range are not allowed.

   NOTE
	When setting up the [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) structure, set the node type to
	NT_INTERRUPT, or NT_UNKOWN.

   IMPLEMENTATION
	1> Checks if the node type is NT_SOFTINT.  If so does nothing since
	   the softint is already pending.  No nest count is maintained.
	2> Sets the node type to NT_SOFTINT.
	3> Links into one of the 5 priority queues.
	4> Pokes the hardware interrupt bit used for softints.

	The node type returns to NT_INTERRUPT after removal from the list.

   INPUTS
	interrupt - pointer to a properly initialized interrupt node

   BUGS
	Unlike other Interrupts, SoftInts must preserve the value of A6.

