# 29 / The Text Function / Setting the Text Drawing Attributes


In addition to [SetFont()](../Libraries_Manual_guide/node03D6.html), there are three rastport control functions that
set attributes for text rendering:


```c
    void SetAPen( struct RastPort *rp, ULONG pen );
    void SetBPen( struct RastPort *rp, ULONG pen );
    void SetDrMd( struct RastPort *rp, ULONG drawMode );
```
The color of the text depends upon the rastport's current drawing mode and
pen colors.  You set the draw mode with the [SetDrMd()](../Includes_and_Autodocs_2._guide/node0478.html) function passing it
a pointer to a rastport and a drawing mode: [JAM1](../Libraries_Manual_guide/node0351.html#line2), [JAM2](../Libraries_Manual_guide/node0351.html#line8), [COMPLEMENT](../Libraries_Manual_guide/node0351.html#line17) or
[INVERSEID](../Libraries_Manual_guide/node0351.html#line24).

If the drawing mode is [JAM1](../Libraries_Manual_guide/node0351.html#line2), the text will be rendered in the
[RastPort.FgPen](../Libraries_Manual_guide/node0350.html#line3) color.  Wherever there is a set bit in the character's
bitmap image, [Text()](../Libraries_Manual_guide/node03D5.html) will set the corresponding bit in the rastport to the
FgPen color.  This is known as overstrike mode.  You set the FgPen color
with the [SetAPen()](../Libraries_Manual_guide/node0350.html#line36) function by passing it a pointer to the rastport and a
color number.

If the drawing mode is set to [JAM2](../Libraries_Manual_guide/node0351.html#line8), [Text()](../Libraries_Manual_guide/node03D5.html) will place the [FgPen](../Libraries_Manual_guide/node0350.html#line3) color as
in the [JAM1](../Libraries_Manual_guide/node0351.html#line2) mode, but it will also set the bits in the rastport to the
[RastPort.BgPen](../Libraries_Manual_guide/node0350.html#line6) color wherever there is a corresponding cleared bit in the
character's bitmap image.  Basically, this prints the character themselves
in the FgPen color and fills in the surrounding parts of the character
image with the BgPen color.   You set the BgPen color with the [SetBPen()](../Includes_and_Autodocs_2._guide/node0476.html)
function by passing it a pointer to the rastport and a color number.

If the drawing mode is [COMPLEMENT](../Libraries_Manual_guide/node0351.html#line17), for every bit set in the character's
bitmap image, the corresponding bits in the rastport (in all of the
rastport's bitplanes) will have their state reversed.  cleared bits in the
character's bitmap image have no effect on the destination rastport.  As
with the other drawing modes, the write mask can be used to protect
certain bitplanes from being modified (see the "[graphics primitives](../Libraries_Manual_guide/node034F.html)"
chapter for more details).

The [JAM1](../Libraries_Manual_guide/node0351.html#line2), [JAM2](../Libraries_Manual_guide/node0351.html#line8), and [COMPLEMENT](../Libraries_Manual_guide/node0351.html#line17) drawing modes are mutually exclusive of
each other but each can be modified by the [INVERSVID](../Libraries_Manual_guide/node0351.html#line24) drawing mode.  If you
combine any of the drawing modes with INVERSVID, the Amiga will reverse
the state of all the bits in the source drawing area before writing
anything into the rastport.

The idea of using a [RastPort](../Libraries_Manual_guide/node034A.html) structure to hold all the rendering
attributes is convenient if the rastport's drawing attributes aren't going
to change much.  This is not the case where several processes need to
render into a rastport using very different drawing attributes.  An easy
way around this problem is to clone the RastPort.  By making an exact
duplicate of a RastPort, you can change the various rendering parameters
of your RastPort without effecting other programs that render into the
RastPort you cloned.  Because a RastPort only contains a pointer to the
rendering area (the bitmap), the original RastPort and the cloned RastPort
both render into the bitmap, but they can use different drawing parameters
(font, drawing mode, colors, etc.).

