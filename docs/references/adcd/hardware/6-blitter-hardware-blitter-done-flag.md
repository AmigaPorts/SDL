---
title: 6 Blitter Hardware / Blitter Done Flag
manual: hardware
chapter: hardware
section: 6-blitter-hardware-blitter-done-flag
functions: []
libraries: []
---

# 6 Blitter Hardware / Blitter Done Flag

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the  [BLTSIZE](hardware/6-blitter-hardware-dma-channels.md)  register is written the blit is started.  The processor
does not stop while the blitter is working, though; they can both work
concurrently, and this provides much of the speed evident in the Amiga.
This does require some amount of care when using the blitter.

A blitter done flag, also called the blitter busy flag, is provided as
DMAF_BLTDONE (bit 14) in  [DMACONR](hardware/7-system-control-hardware-dma-control.md) .  This flag is set when a blit is in
progress.

   About the blitter done flag.
   ----------------------------
   If a blit has just been started but has been locked out of memory
   access because of, for instance, display fetches, this bit may not
   yet be set.  The processor, on the other hand, may be running
   completely uninhibited out of Fast memory or its internal cache, so
   it will continue to have memory cycles.

The solution is to read a chip memory or hardware register address with
the processor before testing the bit.  This can easily be done with the
sequence:


```c
        btst.b  #DMAB_BLTDONE-8,[DMACONR](hardware/7-system-control-hardware-dma-control.md)(a1)
        btst.b  #DMAB_BLTDONE-8,[DMACONR](hardware/7-system-control-hardware-dma-control.md)(a1)
```
where a1 has been preloaded with the address of the hardware registers.
The first "test" of the blitter done bit may not return the correct
result, but the second will.

   NOTE:
   -----
   Starting with the Fat Agnus the blitter busy bit has been "fixed" to
   be set as soon as you write to  [BLTSIZE](hardware/6-blitter-hardware-dma-channels.md)  to start the blit, rather than
   when the blitter gets its first DMA cycle.  However, not all machines
   will use these newer chips, so it is best to rely on the above method
   of testing.

 [Multitasking and the Blitter](hardware/6-blitter-done-flag-multitasking-and-the-blitter.md) 

