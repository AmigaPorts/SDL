# 28 / VSprite Advanced Topics / How VSprites Are Assigned


Although VSprites are managed for you by the GELs system there are some
underlying limitations which could cause the system to run out of VSprites.

As the system goes through the GEL list during [DrawGList()](../Libraries_Manual_guide/node038C.html), whenever it
finds a true VSprite, it goes through the following procedure. If there is
a Simple Sprite available (after the reserved sprites and preceding
VSprites are accounted for), Copper instructions are added that will load
the sprite hardware with this VSprite's data at the right point on the
screen. It may need to add a Copper instruction sequence to load the
display's colors associated with the sprite as well.

 There are only 8 real sprite DMA channels.  The system will run out of
hardware sprites if it is asked to display more than eight VSprites on one
scan line.  This limit goes down to four when the VSprites have different
[SprColor](../Libraries_Manual_guide/node0388.html) pointers. During the time that there is a conflict, the VSprites
that could not be put into Simple Sprites will disappear.  They will
reappear when (as the VSprites are moved about the screen) circumstances
permit.

These problems can be alleviated by taking some precautions:

  * Minimize the number of VSprites to appear on a single horizontal line.

  * If colors for some Virtual Sprites are the same, make sure that the

```c
    pointer for each of the [VSprite](../Libraries_Manual_guide/node0381.html) structures for these Virtual Sprites
    points to the same memory location, rather than to a duplicate set of
    colors elsewhere in memory. The system will know to map these into
    Sprite pairs.
```
If a VSprite's [SprColors](../Libraries_Manual_guide/node0388.html) are set to NULL, the VSprite will appear in the
[ViewPort](../Libraries_Manual_guide/node00F1.html#line4)'s [ColorMap](../Libraries_Manual_guide/node00F1.html#line4) colors.  The system will display the VSprite in any
one of a set of four different possible color groupings as indicated in
the [Simple Sprite section](../Libraries_Manual_guide/node0379.html#line31) above.

If [SprColors](../Libraries_Manual_guide/node0388.html) points to a color set, the system will jam SprColors into the
display hardware (via the Copper list), effectively overriding those
[ColorMap](../Libraries_Manual_guide/node00F1.html#line4) registers.  The values in the ColorMap are not overwritten, but
anything in the background display that used to appear in the ColorMap
colors will appear in SprColors colors.

