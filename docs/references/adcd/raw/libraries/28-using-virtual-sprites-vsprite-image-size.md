# 28 / Using Virtual Sprites / VSprite Image Size


A true VSprite is always one word (16 pixels) wide and may be any number
of lines high.  It can be made to appear thinner by making some pixels
transparent.  Like Simple Sprites, VSprite pixels are always the size of a
pixel in low-resolution mode (320x200); regardless of the resolution the
display is set to.  To specify how many lines make up the VSprite image,
the [VSprite](../Libraries_Manual_guide/node0381.html) structure member, [Height](../Includes_and_Autodocs_2._guide/node00C3.html#line102), is used. VSprites always have a
[Depth](../Includes_and_Autodocs_2._guide/node00C3.html#line102) of two, allowing for three colors.  The values may be set like this:


```c
    myVSprite.Width  = 1;      /* ALWAYS 1 for true VSprites. */
    myVSprite.Height = 5;      /* The example height. */
    myVSprite.Depth  = 2;      /* ALWAYS 2 for true VSprites. */
```
