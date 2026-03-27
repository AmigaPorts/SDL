# intuition.library/PrintIText



NAME

```c
    PrintIText -- Print text described by the [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) argument.
```
SYNOPSIS

```c
    PrintIText( [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), IText, LeftOffset, TopOffset )
                A0        A1     D0          D1

    VOID PrintIText( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, struct [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) *, WORD, WORD );
```
FUNCTION

```c
    Prints the [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) into the specified [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).  Sets up the
    [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) as specified by the [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) values, then prints the text
    into the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) at the [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) x/y coordinates offset by the
    left/top arguments.  Note, though, that the [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) structure
    itself may contain further text position coordinates: those
    coordinates and the Left/TopOffsets are added to obtain the true
    position of the text to be rendered.

    This routine does window layer clipping as appropriate -- if you
    print text outside of your window, your characters will be
    clipped at the window's edge, providing you pass your window's
    (layered) [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).

    If the NextText field of the [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) argument is non-NULL,
    the next [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) is rendered as well, and so on until some
    NextText field is NULL.

    [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) with the ITextFont field NULL are displayed in the
    font of the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).  If the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) font is also NULL, the
    system default font, as set via the [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) tool, will be used.
```
INPUTS

```c
    [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) = the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) destination of the text
    IText = pointer to an instance of the structure [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572)
    LeftOffset = left offset of the [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) into the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    TopOffset = top offset of the [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) into the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
```
RESULT

    None
BUGS

SEE ALSO

