# 28 / Advanced Topics / How VSprite and Playfield Colors Interact


At the start of each display, the system loads the colors from the
[ViewPort](../Libraries_Manual_guide/node00F1.html#line4)'s color table into the display's hardware registers, so whatever
is rendered into the [BitMap](../Libraries_Manual_guide/node00F1.html#line4) is displayed correctly. But if the VSprite
system is used, and the colors are specified (via [SprColors](../Libraries_Manual_guide/node0388.html)) for each
VSprite, the SprColors will be loaded by the system into the display
hardware, as needed. The system does this by generating Copper
instructions that will jam the colors into the hardware at specific
moments in the display cycle.  Any BitMap rendering, including Bobs, which
share colors with VSprites, may change colors constantly as the video
display beam progresses down the screen.

This color changing can be avoided by taking one of the following
precautions:

  * Use a four bitplane playfield, which only allows the lower 16 colors

```c
    to be rendered into the [BitMap](../Libraries_Manual_guide/node00F1.html#line4) (and allows Hires display mode).
```
  * If a 32-color playfield display is being used, avoid rendering in

    colors 17-19, 21-23, 25-27, and 29-32, which are the colors affected
    by the VSprite system.
  * Specify the VSprite [SprColors](../Libraries_Manual_guide/node0388.html) pointer as a value of NULL to avoid

```c
    changing the contents of any of the hardware sprite color registers.
    This may cause the VSprites to change colors depending on their
    positions relative to each other, as described in the
    [previous section](../Libraries_Manual_guide/node0393.html).
```
