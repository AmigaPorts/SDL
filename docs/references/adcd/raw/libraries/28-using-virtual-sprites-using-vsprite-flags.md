# 28 / Using Virtual Sprites / Using VSprite Flags


The [Flags](../Includes_and_Autodocs_2._guide/node00C3.html#line92) member of the [VSprite](../Libraries_Manual_guide/node0381.html) structure is both read and written by the
system.  Some bits are used by the application to inform the system;
others are used by the system to indicate things to the application.

The only [Flags](../Includes_and_Autodocs_2._guide/node00C3.html#line92) bits that are used by true VSprites are:

[VSPRITE](../Includes_and_Autodocs_2._guide/node00C3.html#line19)

    This may be set to indicate to the system that it should treat the
    structure as a true VSprite, not part of a Bob.  This affects the
    interpretation of the data layout and the use of various system
    variables.
[VSOVERFLOW](../Includes_and_Autodocs_2._guide/node00C3.html#line25)

    The system sets this bit in the true VSprites that it is unable to
    display.  This happens when there are too many in the same scan line,
    and the system has run out of Simple Sprites to assign.  It indicates
    that this VSprite has not been displayed.  If no sprites are
    reserved, this means that more than eight sprites touch one scan
    line.  This bit will not be set for Bobs and should not be changed by
    the application.
[GELGONE](../Includes_and_Autodocs_2._guide/node00C3.html#line25)

```c
    If the system has set GELGONE bit in the [Flags](../Includes_and_Autodocs_2._guide/node00C3.html#line92) member, then the GEL
    associated with this VSprite is not on the display at all, it is
    entirely outside the GEL boundaries.  This area is defined by the
    [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) members [topmost, bottommost, leftmost and rightmost](../Libraries_Manual_guide/node03B3.html) (see
    <graphics/[rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html#line39)>). On the basis of that information, the
    application may decide that the object need no longer be part of the
    GEL list and may decide to remove it to speed up the consideration of
    other objects. Use [RemVSprite()](../Libraries_Manual_guide/node0389.html) (or [RemBob()](../Libraries_Manual_guide/node03A6.html), if it's a Bob) to do
    this. This bit should not be changed by the application.
```
The [VSprite.Flags](../Includes_and_Autodocs_2._guide/node00C3.html#line92) value should be initialized like this for a VSprite
GEL:


```c
    myVSprite.Flags = VSPRITE;
```
