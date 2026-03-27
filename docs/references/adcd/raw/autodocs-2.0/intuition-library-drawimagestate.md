# intuition.library/DrawImageState



NAME

```c
    DrawImageState -- Draw an (extended) Intuition [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) with
            special visual state. (V36)
```
SYNOPSIS

```c
    DrawImageState( RPort, [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621), LeftOffset, TopOffset, State, [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) )
                    A0     A1     D0          D1         D2     A2

    VOID DrawImageState( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, struct [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) *,
            WORD, WORD, ULONG, struct [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) * );
```
FUNCTION

```c
    This function draws an Intuition [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) structure in a variety of
    "visual states," which are defined by constants in
    [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html).  These include:
    IDS_NORMAL              - like [DrawImage()](../Includes_and_Autodocs_2._guide/node0210.html)
    IDS_SELECTED            - represents the "selected state" of a [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215)
    IDS_DISABLED            - the "ghosted state" of a gadget
    IDS_BUSY                - for future functionality
    IDS_INDETERMINATE       - for future functionality
    IDS_INACTIVENORMAL      - for gadgets in window border
    IDS_INACTIVESELECTED    - for gadgets in window border
    IDS_INACTIVEDISABLED    - for gadgets in window border

    Only IDS_NORMAL will make sense for traditional [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) structures,
    this function is more useful when applied to new custom images
    or "object-oriented image classes."

    Each class of custom images is responsible for documenting which
    visual states it supports, and you typically want to use images
    which support the appropriate states with your custom gadgets.

    The [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) parameter provides information invaluable to
    "rendered" images, such as pen color and resolution.  Each
    image class must document whether this parameter is required.
```
INPUTS

```c
    RPort   - [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) for rendering
    [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621)   - pointer to a (preferably custom) image
    LeftOffset,RightOffset - positional offsets in pixels
    State   - visual state selected from above
    [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) - pointer to packed of pen selections and resolution.
```
RESULT

    None.
EXAMPLE

    Provided separately in the DevCon '90 disk set.
NOTES


BUGS


SEE ALSO

```c
    [DrawImage()](../Includes_and_Autodocs_2._guide/node0210.html), [GetScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0220.html), [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html)
```
