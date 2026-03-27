# 27 / / Forming a Basic Display / Creating the Display Instructions


Now that you have initialized the system data structures, you can request
that the system prepare a set of display instructions for the Copper using
these structures as input data. During the one or more blank vertical
lines that precede each [ViewPort](../Libraries_Manual_guide/node032B.html#line59), the Copper is busy changing the
characteristics of the display hardware to match the characteristics you
expect for this ViewPort. This may include a change in display resolution,
a change in the colors to be used, or other user-defined modifications to
system registers.

Here is the code that creates the display instructions:


```c
    /*  Construct preliminary Copper instruction list.  */
    MakeVPort( &view, &viewPort );
```
In this line of code, &view is the address of the [View](../Libraries_Manual_guide/node032B.html#line51) structure and
&viewPort is the address of the first [ViewPort](../Libraries_Manual_guide/node032B.html#line59) structure. Using these
structures, the system has enough information to build the instruction
stream that defines your display.

[MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html) creates a special set of instructions that controls the
appearance of the display. If you are using animation, the graphics
animation routines create a special set of instructions to control the
hardware sprites and the system color registers. In addition, the advanced
user can create special instructions (called user Copper instructions) to
change system operations based on the position of the video beam on the
screen.

All of these special instructions must be merged together before the
system can use them to produce the display you have designed. This is done
by the system routine [MrgCop()](../Includes_and_Autodocs_2._guide/node045F.html) (which stands for "Merge Coprocessor
Instructions").  Here is a typical call:


```c
    /* Merge preliminary lists into a real Copper list in the view
       structure.                                                  */
    MrgCop( &view );
```
