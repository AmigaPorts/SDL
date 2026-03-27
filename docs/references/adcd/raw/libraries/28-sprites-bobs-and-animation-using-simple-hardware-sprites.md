# 28 Sprites, Bobs and Animation / Using Simple (Hardware) Sprites


Simple Sprites can be used to create animations, so even though are not
really part of the GELs system, they are desribed here as a possible
alternative to using VSprites.  For more information on the sprite
hardware, including information on attached sprites, see the Amiga
[Hardware](../Hardware_Manual_guide/node00AE.html) Reference Manual.

The SimpleSprite structure is found in <graphics/[sprite.h](../Includes_and_Autodocs_2._guide/node00C5.html#line20)>. It has fields
that indicate the height and position of the Simple Sprite and a number
that indicates which of the 8 hardware sprites to use.

Simple Sprites are always 16 bits wide, which is why there is no width
member in the [SimpleSprite](../Includes_and_Autodocs_2._guide/node00C5.html#line20) structure.  Currently, sprites always appear as
low-resolution pixels, and their position is specified in the same way.
If the sprite is being moved across a high-resolution display in single
pixel increments, it will appear to move two high-resolution pixels for
each increment.  In low-resolution mode, a single Lores pixel movement
will be seen.  Similarly, in an interlaced display, the y direction
motions are in two-line increments. The same sprite image data is placed
into both even and odd fields of the interlaced display, so the sprite
will appear to be the same size in any display mode.

The upper left corner of the [ViewPort](../Libraries_Manual_guide/node00F1.html#line4) area has coordinates (0,0). Unlike
VSprites, the motion of a Simple Sprite can be relative to this position.
(That is, if you create a Simple Sprite relative to your ViewPort and move
the ViewPort around, the Simple Sprite can move as well, but its movement
is relative to the origin of the ViewPort.)

The Sprite pairs 0/1, 2/3, 4/5, and 6/7 share color registers.  See
"[VSprite Advanced Topics](../Libraries_Manual_guide/node0391.html)" later in this chapter, for precautions to take
if Simple Sprites and VSprites are used at the same time.

The following figure shows which color registers are used by Simple
Sprites.



                    00  Unused
                    01  Unused
                          ·
                          ·
                          ·     _
                    16  Unused   |
                    17  Color 1  |
                    18  Color 2  |-- Sprites 0 and 1
                    19  Color 3 _|
                    20  Unused   |
                    21  Color 1  |
                    22  Color 2  |-- Sprites 2 and 3
                    23  Color 3 _|
                    24  Unused   |
                    25  Color 1  |
                    26  Color 2  |-- Sprites 4 and 5
                    27  Color 3 _|
                    28  Unused   |
                    29  Color 1  |
                    30  Color 2  |-- Sprites 6 and 7
                    31  Color 3 _|


                 Figure 28-2: Sprite Color Registers
Sprites do not have exclusive use of the color registers. If the [ViewPort](../Libraries_Manual_guide/node00F1.html#line4)
is 5 bitplanes deep, all 32 of the system color registers will still be
used by the playfield display hardware.


```c
    Note:
    -----
    Color zero for all Sprites is always a "transparent" color, and the
    colors in registers 16, 20, 24, and 28 are not used by sprites. These
    colors will be seen only if they are rendered into a playfield. For
    further information, see the Amiga [Hardware](../Hardware_Manual_guide/node00B7.html) Reference Manual.
```
If there are two [ViewPort](../Libraries_Manual_guide/node00F1.html#line4)s with different color sets on the same display,
a sprite will switch colors when it is moved across their boundary.  For
example, Sprite 0 and 1 will appear in colors 17-19 of whatever ViewPort
they happen to be over.  This is because the system jams all the
ViewPort's colors into the display hardware at the top of each ViewPort.

 [Simple Sprite Functions](../Libraries_Manual_guide/node037A.html) 

