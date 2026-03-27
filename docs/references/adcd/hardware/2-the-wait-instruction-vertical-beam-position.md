---
title: 2 / The WAIT Instruction / Vertical Beam Position
manual: hardware
chapter: hardware
section: 2-the-wait-instruction-vertical-beam-position
functions: []
libraries: []
---

# 2 / The WAIT Instruction / Vertical Beam Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The vertical beam position can be resolved to one line, with a maximum
value of 255. There are actually 262 NTSC (312 PAL) possible vertical
positions. Some minor complications can occur if you want something to
happen within these last six or seven scan lines. Because there are only
eight bits of resolution for vertical beam position (allowing 256
different positions), one of the simplest ways to handle this is shown
below.



```c
     [Copper Instruction](hardware/2-coprocessor-hardware-what-is-a-copper-instruction.md)           Explanation
    --------------------          -----------
     [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for position (0,255)   At this point, the vertical
                                  counter appears to wrap to 0
                                  because the comparison works
                                  on the least significant bits
                                  of the vertical count

     [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for any horizontal       Thus the total of 256 + 6 = 262
    position with vertical        lines of video beam travel during
    position 0 through 5,         which  [Copper instructions](hardware/2-coprocessor-hardware-what-is-a-copper-instruction.md)  can be
    covering the last 6 lines     executed
    of the scan before
     [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  occurs.


    Note that the vertical is like the horizontal.
    ----------------------------------------------
    There are alternating long and short lines, there are also long and
    short fields (interlace only). In NTSC, the fields are 262, then 263
    lines and in PAL, 312, then 313 lines.  This alternation of lines and
    fields produces the standard NTSC 4 field repeating pattern:

          short field ending on short line
          long  field ending on  long line
          short field ending on  long line
          long  field ending on short line
          and back to the beginning...
```
One horizontal count takes one cycle of the system clock (processor is
twice this).


          NTSC- 3,579,545 Hz
          PAL - 3,546,895 Hz
          genlocked- basic clock frequency plus or minus about 2%
