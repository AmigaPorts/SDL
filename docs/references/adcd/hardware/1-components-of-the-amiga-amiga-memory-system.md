---
title: 1 / Components of the Amiga / Amiga Memory System
manual: hardware
chapter: hardware
section: 1-components-of-the-amiga-amiga-memory-system
functions: []
libraries: []
---

# 1 / Components of the Amiga / Amiga Memory System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As mentioned previously, the custom chips have DMA access to RAM which
allows them to perform graphics, audio, and I/O chores independently of
the CPU.  This shared memory that both the custom chips and the CPU can
access directly is called Chip memory.

The custom chips and the 680x0 CPU share Chip memory on a fully
interleaved basis.  Since the 680x0 only needs to access the Chip memory
bus during each alternate clock cycle in order to run full speed, the rest
of the time the Chip memory bus is free for other activities.  The custom
chips use the memory bus during these free cycles, effectively allowing
the CPU to run at full speed most of the time.

There are some occasions though when the custom chips steal memory cycles
from the 680x0.  In the higher resolution video modes, some or all of the
cycles normally used for processor access are needed by the custom chips
for video refresh.  In that case, the Copper and the blitter in the custom
chips steal time from the 680x0 for jobs they can do better than the
680x0.  Thus, the system DMA channels are designed with maximum
performance in mind.

Even when such cycle stealing occurs, it only blocks the 680x0's access to
the internal, shared memory.  When using ROM or external memory, also
known as Fast memory, the 680x0 always runs at full speed.

The DMA capabilities of the custom chips vary depending on the version of
the chips and the Amiga model.  The original custom chip set found in the
A1000 could access the first 512K of RAM.  Most A1000s have only 512K of
RAM so some of the Chip RAM is used up for operating system overhead.

A later version of the custom chips found in early A500s and A2000s
replaced the original Agnus chip (8361) with a newer version called Fat
Agnus (8370/8371).  The Fat Agnus chip has DMA access to 512K of Chip
memory, just like the original Agnus, but also allows an additional 512K
of internal slow memory or pseudo-fast memory located at ($00C0 0000).
Since the slow memory can be used for operating system overhead, this
allows all 512K of Chip memory to be used by the custom chips.

The name slow memory comes from the fact that bus contention with the
custom chips can still occur even though only the CPU can access the
memory.  Since slow memory is arbitrated by the same gate that controls
Chip memory, the custom chips can block processor access to slow memory in
the higher resolution video modes.

The latest version of Agnus and the custom chips found in most A500s and
A2000s is known as the Enhanced Chip Set or ECS.  ECS Fat Agnus (8372A)
can access up to one megabyte of Chip memory.  It is pin compatible with
the original Fat Agnus (8370/8371) found in earlier A500 and A2000 models.
In addition, ECS Fat Agnus supports both the NTSC and PAL video standards
on a single chip.

In the A3000, the Enhanced Chip Set can access up to two megabytes of Chip
memory.

The amount of Chip memory is important since it determines how much
graphics, audio, and disk data the custom chips can operate on without the
680x0 CPU. Table 1-1 summarizes the basic memory configurations of the
Amiga.




```c
                  Chip RAM     Maximum    Total RAM     Maximum
                (base model)   Chip RAM  (base model)  Total RAM
                ------------   --------  ------------  ---------
     Amiga 1000     256K        512K        256K          9 MB
     Amiga  500     512K        1 MB        1 MB          9 MB
     Amiga 2000     512K        1 MB        1 MB          9 MB
     Amiga 3000     1 MB        2 MB        2 MB     over 1 GB


                Table 1-1: Summary of Amiga Memory Configurations
```
Another primary feature of the Amiga hardware is the ability to
dynamically control which part of the Chip memory is used for the
background display, audio, and sprites.  The Amiga is not limited to a
small, specific area of RAM for a frame buffer.  Instead, the system
allows display bitplanes, sprite processor control lists, coprocessor
instruction lists, or audio channel control lists to be located anywhere
within Chip memory.

This same region of memory can be accessed by the bit blitter.  This
means, for example, that the user can store partial images at scattered
areas of Chip memory and use these images for animation effects by rapidly
replacing on screen material while saving and restoring background images.
In fact, the Amiga includes firmware support for display definition and
control as well as support for animated objects embedded within playfields.

