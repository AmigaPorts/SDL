# 28 / Using Bobs / Specifying the Colors of a Bob


Typically a five-bitplane, low-resolution mode display allows playfield
pixels (and therefore, Bob pixels) to be selected from any of 32 active
colors out of a system palette of 4,096 different color choices. Bob
colors are limited to the colors used in the background playfield.

The system ignores the sprColors member of the [VSprite](../Libraries_Manual_guide/node0381.html) structure when the
VSprite structure is the root of a Bob. Instead, the Bob's colors are
determined by the combination of the [Depth](../Includes_and_Autodocs_2._guide/node00C3.html#line102) of the Bob image and its
[PlanePick](../Libraries_Manual_guide/node03A0.html), [PlaneOnOff](../Libraries_Manual_guide/node03A1.html) and [ImageShadow](../Libraries_Manual_guide/node039F.html) members.

Use the [Depth](../Includes_and_Autodocs_2._guide/node00C3.html#line102) member in the [VSprite](../Libraries_Manual_guide/node0381.html) structure to indicate how many planes
of image data is provided to define the Bob. This also defines how many
colors the Bob will have. The combination of bits in corresponding Y,X
positions in each bitplane determines the color of the pixel at that
position.

For example, if a [Depth](../Includes_and_Autodocs_2._guide/node00C3.html#line102) of one plane is specified, then the bits of that
image allow only two colors to be selected:  one color for each bit that
is a 0, a second color for each bit that is a 1.  Likewise, if there are 5
planes of image data, all 32 colors can be used in the Bob.  The Bob Depth
must not exceed the background depth.  Specify Depth using a statement
such as the following:


```c
    myVSprite.Depth = 5;   /* Allow a 32 color, 5-bitplane image. */
```
