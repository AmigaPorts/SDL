---
title: 6 Blitter Hardware / Blitter Key Points
manual: hardware
chapter: hardware
section: 6-blitter-hardware-blitter-key-points
functions: []
libraries: []
---

# 6 Blitter Hardware / Blitter Key Points

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is a list of some key points that should be remembered when
programming the blitter.

*  Write  [BLTSIZE](hardware/6-blitter-hardware-dma-channels.md)  last; writing this register starts the blit.

*  Modulos and pointers are in bytes; width is in words and height is in
   pixels.  The least significant bit of all pointers and modulos is
   ignored.

*  The order of operations in the blitter is  [masking](hardware/6-blitter-hardware-shifts-and-masks.md) ,  [shifting](hardware/6-blitter-hardware-shifts-and-masks.md) , logical
   combination of sources,  [area fill](hardware/6-blitter-hardware-area-fill-mode.md) , and  [zero flag](hardware/6-blitter-hardware-zero-flag.md)  setting.

*  In ascending mode, the blitter increments the pointers, adds the
   modulos, and  [shifts](hardware/6-blitter-hardware-shifts-and-masks.md)  to the right.

*  In  [descending mode](hardware/6-blitter-hardware-descending-mode.md) , the blitter decrements the pointers, subtracts
   the modulos, and shifts to the left.

*   [Area fill](hardware/6-blitter-hardware-area-fill-mode.md)  only works correctly in  [descending mode](hardware/6-blitter-hardware-descending-mode.md) .

*  Check  [BLTDONE](hardware/6-blitter-hardware-blitter-done-flag.md)  before writing blitter registers or using the results
   of a blit.

*   [Shifts](hardware/6-blitter-hardware-shifts-and-masks.md)  are done on immediate data as soon as it is loaded.


```c
    [ECS blitter](hardware/c-ecs-hardware-and-the-graphics-library-big-blits.md) .
```
   -------------
   For information relating to the blitter hardware in the Enhanced Chip
   Set, see  [Appendix C](hardware/amiga-hardware-reference-manual-c-enhanced-chip-set.md) .


 [Example:  Clearmem](hardware/hard-examples-clearmem-asm.md) 
 [Example:  Simpleline](hardware/hard-examples-simpleline-asm.md) 
 [Example:  Rotatebits](hardware/hard-examples-rotatebits-asm.md) 

