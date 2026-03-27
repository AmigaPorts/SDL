# 28 / Using Bobs / The VSprite Structure and Bobs


The root [VSprite](../Libraries_Manual_guide/node0381.html) structure is set up as described earlier for true
VSprites, with the following exceptions:


```c
             [Y, X](../Includes_and_Autodocs_2._guide/node00C3.html#line96)  Bob position is always in pixels that are the same
                   resolution as the display.

            [Flags](../Libraries_Manual_guide/node0397.html)  For Bobs, the [VSPRITE](../Libraries_Manual_guide/node0383.html#line6) flag must be cleared.  [SAVEBACK](../Libraries_Manual_guide/node0397.html#line5)
                   or [OVERLAY](../Libraries_Manual_guide/node0397.html#line34) can also be used.

    [Height, Width](../Libraries_Manual_guide/node039B.html)  Bob pixels are the size of the background pixels. The
                   Width of Bobs may be greater than one word.

            [Depth](../Libraries_Manual_guide/node039D.html#line10)  The Depth of a Bob may be up to as deep as the
                   playfield, provided that enough image data is provided.

        [ImageData](../Libraries_Manual_guide/node039C.html)  This is still a pointer to the image, but the data
                   there is organized differently.

        [SprColors](../Includes_and_Autodocs_2._guide/node00C3.html#line117)  This pointer should be set to NULL for Bobs.

            [VSBob](../Includes_and_Autodocs_2._guide/node00C3.html#line120)  This is a pointer to the [Bob](../Libraries_Manual_guide/node0398.html) structure set up as
                   described below.
```
