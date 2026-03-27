# 2 Coprocessor Hardware / Putting Together a Copper Instruction List


The Copper instruction list contains all the register resetting done
during the  [vertical blanking](../Hardware_Manual_guide/node0169.html)  interval and the register modifications
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

For example, the  [bitplane pointers](../Hardware_Manual_guide/node0075.html)  used in playfield displays and the
 [sprite pointers](../Hardware_Manual_guide/node00C0.html)  must be rewritten during the [vertical blanking](../Hardware_Manual_guide/node0169.html)  interval
so the data will be properly retrieved when the screen display starts
again. This can be done with a Copper instruction list that does the
following:


```c
    [WAIT](../Hardware_Manual_guide/node004B.html)  until first line of the display
    [MOVE](../Hardware_Manual_guide/node004A.html)  data to bitplane pointer 1
    [MOVE](../Hardware_Manual_guide/node004A.html)  data to bitplane pointer 2
    [MOVE](../Hardware_Manual_guide/node004A.html)  data to sprite pointer 1, and so on.
```
As another example, the  [sprite DMA channels](../Hardware_Manual_guide/node00C4.html)  that create movable objects
can be reused multiple times during the same display field. You can change
the size and shape of the reuses of a sprite; however, every multiple
reuse normally uses the same set of colors during a full display frame.
You can change sprite colors mid-screen with a Copper instruction list
that waits until the last line of the first use of the sprite processor
and changes the colors before the first line of the next use of the same
sprite processor:


```c
    [WAIT](../Hardware_Manual_guide/node004B.html)  for first line of display
    [MOVE](../Hardware_Manual_guide/node004A.html)  firstcolor1 to COLOR17
    [MOVE](../Hardware_Manual_guide/node004A.html)  firstcolor2 to COLOR18
    [MOVE](../Hardware_Manual_guide/node004A.html)  firstcolor3 to COLOR19
    [WAIT](../Hardware_Manual_guide/node004B.html)  for last line +1 of sprite's first use
    [MOVE](../Hardware_Manual_guide/node004A.html)  secondcolor1 to COLOR17
    [MOVE](../Hardware_Manual_guide/node004A.html)  secondcolor2 to COLOR18
    [MOVE](../Hardware_Manual_guide/node004A.html)  secondcolor3 to COLOR19, and so on.
```
As you create Copper instruction lists, note that the final list must be
in the same order as that in which the video beam creates the display. The
video beam traverses the screen from position (0,0) in the upper left hand
corner of the screen to the end of the display (226,262) NTSC (or
(226,312) PAL) in the lower right hand corner. The first 0 in (0,0)
represents the x position. The second 0 represents the y position. For
example, an instruction that does something at position (0,100) should
come after an instruction that affects the display at position (0,60).

Note that given the form of the  [WAIT](../Hardware_Manual_guide/node004B.html)  instruction, you can sometimes get
away with not sorting the list in strict video beam order.  The  [WAIT](../Hardware_Manual_guide/node004B.html) 
instruction causes the Copper to wait until the value in the beam counter
is equal to or greater than the value in the instruction.

This means, for example, if you have instructions following each other
like this:


```c
    [WAIT](../Hardware_Manual_guide/node004B.html)  for position (64,64)
    [MOVE](../Hardware_Manual_guide/node004A.html)  data

    [WAIT](../Hardware_Manual_guide/node004B.html)  for position (60,60)
    [MOVE](../Hardware_Manual_guide/node004A.html)  data
```
then the Copper will perform both moves, even though the instructions are
out of sequence.  The "greater than" specification prevents the Copper
from locking up if the beam has already passed the specified position.  A
side effect is that the second  [MOVE](../Hardware_Manual_guide/node004A.html)  below will be performed:


```c
    [WAIT](../Hardware_Manual_guide/node004B.html)  for position (60,60)
    [MOVE](../Hardware_Manual_guide/node004A.html)  data

    [WAIT](../Hardware_Manual_guide/node004B.html)  for position (60,60)
    [MOVE](../Hardware_Manual_guide/node004A.html)  data
```
At the time of the second  [WAIT](../Hardware_Manual_guide/node004B.html)  in this sequence, the beam counters will
be greater than the position shown in the instructions. Therefore, the
second  [MOVE](../Hardware_Manual_guide/node004A.html)  will also be performed.

Note also that the above sequence of instructions could just as easily be


```c
    [WAIT](../Hardware_Manual_guide/node004B.html)  for position (60,60)
    [MOVE](../Hardware_Manual_guide/node004A.html)  data
    [MOVE](../Hardware_Manual_guide/node004A.html)  data
```
because multiple  [MOVE](../Hardware_Manual_guide/node004A.html) s can follow a single  [WAIT](../Hardware_Manual_guide/node004B.html) .

 [Complete Sample Copper List](../Hardware_Manual_guide/node0054.html) 

