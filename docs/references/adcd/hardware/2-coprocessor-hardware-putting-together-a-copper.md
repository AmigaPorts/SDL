---
title: 2 Coprocessor Hardware / Putting Together a Copper Instruction List
manual: hardware
chapter: hardware
section: 2-coprocessor-hardware-putting-together-a-copper
functions: []
libraries: []
---

# 2 Coprocessor Hardware / Putting Together a Copper Instruction List

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Copper instruction list contains all the register resetting done
during the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  interval and the register modifications
necessary for making mid-screen alterations. As you are planning what will
happen during each display field, you may find it easier to think of each
aspect of the display as a separate subsystem, such as playfields,
sprites, audio, interrupts, and so on. Then you can build a separate list
of things that must be done for each subsystem individually at each video
beam position.

When you have created all these intermediate lists of things to be done,
you must merge them together into a single instruction list to be executed
by the Copper once for each display frame. The alternative is to create
this all-inclusive list directly, without the intermediate steps.

For example, the  [bitplane pointers](hardware/3-basic-playfield-displaying-and-redisplaying-the-playfield.md)  used in playfield displays and the
 [sprite pointers](hardware/4-displaying-a-sprite-resetting-the-address-pointers.md)  must be rewritten during the [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  interval
so the data will be properly retrieved when the screen display starts
again. This can be done with a Copper instruction list that does the
following:


```c
    [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  until first line of the display
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  data to bitplane pointer 1
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  data to bitplane pointer 2
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  data to sprite pointer 1, and so on.
```
As another example, the  [sprite DMA channels](hardware/4-sprite-hardware-reusing-sprite-dma-channels.md)  that create movable objects
can be reused multiple times during the same display field. You can change
the size and shape of the reuses of a sprite; however, every multiple
reuse normally uses the same set of colors during a full display frame.
You can change sprite colors mid-screen with a Copper instruction list
that waits until the last line of the first use of the sprite processor
and changes the colors before the first line of the next use of the same
sprite processor:


```c
    [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for first line of display
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  firstcolor1 to COLOR17
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  firstcolor2 to COLOR18
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  firstcolor3 to COLOR19
    [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for last line +1 of sprite's first use
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  secondcolor1 to COLOR17
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  secondcolor2 to COLOR18
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  secondcolor3 to COLOR19, and so on.
```
As you create Copper instruction lists, note that the final list must be
in the same order as that in which the video beam creates the display. The
video beam traverses the screen from position (0,0) in the upper left hand
corner of the screen to the end of the display (226,262) NTSC (or
(226,312) PAL) in the lower right hand corner. The first 0 in (0,0)
represents the x position. The second 0 represents the y position. For
example, an instruction that does something at position (0,100) should
come after an instruction that affects the display at position (0,60).

Note that given the form of the  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  instruction, you can sometimes get
away with not sorting the list in strict video beam order.  The  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md) 
instruction causes the Copper to wait until the value in the beam counter
is equal to or greater than the value in the instruction.

This means, for example, if you have instructions following each other
like this:


```c
    [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for position (64,64)
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  data

    [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for position (60,60)
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  data
```
then the Copper will perform both moves, even though the instructions are
out of sequence.  The "greater than" specification prevents the Copper
from locking up if the beam has already passed the specified position.  A
side effect is that the second  [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  below will be performed:


```c
    [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for position (60,60)
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  data

    [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for position (60,60)
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  data
```
At the time of the second  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  in this sequence, the beam counters will
be greater than the position shown in the instructions. Therefore, the
second  [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  will also be performed.

Note also that the above sequence of instructions could just as easily be


```c
    [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for position (60,60)
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  data
    [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  data
```
because multiple  [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md) s can follow a single  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md) .

 [Complete Sample Copper List](hardware/2-putting-together-a-copper-list-complete-sample-copper-list.md) 

