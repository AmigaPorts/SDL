# graphics.library/OpenFont



NAME

    OpenFont -- Get a pointer to a system font.
SYNOPSIS

```c
    font = OpenFont(textAttr)
    D0              A0

    struct [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) *OpenFont(struct [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) *);
```
FUNCTION

```c
    This function searches the system font space for the graphics
    text font that best matches the attributes specified.  The
    pointer to the font returned can be used in subsequent
    [SetFont](../Includes_and_Autodocs_2._guide/node0479.html) and [CloseFont](../Includes_and_Autodocs_2._guide/node042E.html) calls.  It is important to match this
    call with a corresponding [CloseFont](../Includes_and_Autodocs_2._guide/node042E.html) call for effective
    management of ram fonts.
```
INPUTS

```c
    textAttr - a [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) or [TTextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line73) structure that describes the
               text font attributes desired.
```
RESULT

    font is zero if the desired font cannot be found.  If the named
    font is found, but the size and style specified are not
    available, a font with the nearest attributes is returned.
SEE ALSO

```c
    [CloseFont()](../Includes_and_Autodocs_2._guide/node042E.html)  [SetFont()](../Includes_and_Autodocs_2._guide/node0479.html)
    [diskfont.library/OpenDiskFont](../Includes_and_Autodocs_2._guide/node01F7.html)  [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)
```
