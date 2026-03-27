# 28 / Using Virtual Sprites / Specifying the Colors of a VSprite


The system software provides a great deal of versatility in the choice of
colors for Virtual Sprites.  Each VSprite has its own set of three colors,
pointed to by [SprColors](../Includes_and_Autodocs_2._guide/node00C3.html#line117), which the system jams into the display's Copper
list as needed.

[SprColors](../Includes_and_Autodocs_2._guide/node00C3.html#line117) points to the first of three 16-bit values. The first value
represents the color used for the VSprite bits that select color 1, the
second value is color 2, and the third value is color 3.  When the system
assigns a hardware sprite to carry the VSprite's image, it jams these
color values into the Copper list (the intermediate Copper list, not the
color table), so that the [View](../Libraries_Manual_guide/node00F1.html#line4)'s colors will be correct for this VSprite
at the time the VSprite is displayed.  It doesn't jam the original
palette's colors back after the VSprite is done.  If there is another
VSprite later, that VSprite's colors will get jammed; if there is not
another VSprite, the colors will remain the same until the next [ViewPort](../Libraries_Manual_guide/node00F1.html#line4)'s
colors get loaded.

If the [SprColors](../Includes_and_Autodocs_2._guide/node00C3.html#line117) pointer is set to NULL, that VSprite does not generate a
color-change instruction stream for the Copper. Instead, the VSprite
appears drawn in whatever color set that the hardware sprite happens to
have in it already.

Since the registers are initially loaded with the colors from the
[ViewPort](../Libraries_Manual_guide/node00F1.html#line4)'s [ColorMap](../Libraries_Manual_guide/node00F1.html#line4), if all VSprites have NULL [SprColors](../Includes_and_Autodocs_2._guide/node00C3.html#line117), they will appear
in the ViewPort's colors.

To continue our example, a set of colors can be declared and the VSprite
colors set with the following statements:


```c
    WORD mySpriteColors[] = { 0x0000,
                              0x00f0,
                              0x0f00 };  /* Declare colors statically  */

    myVSprite.SprColors = mySpriteColors;  /* Assign colors to VSprite */
```
