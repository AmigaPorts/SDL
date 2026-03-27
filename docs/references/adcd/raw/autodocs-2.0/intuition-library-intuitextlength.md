# intuition.library/IntuiTextLength



NAME

```c
    IntuiTextLength -- Return the length (pixel-width) of an [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572).
```
SYNOPSIS

```c
    Length = IntuiTextLength( IText )
    D0                        A0

    LONG IntuiTextLength( struct [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) * );
```
FUNCTION

```c
    This routine accepts a pointer to an instance of an [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572)
    structure, and returns the length (the pixel-width) of the string
    which that instance of the structure represents.

    NOTE: if the Font pointer of your [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) structure is set to NULL,
    you'll get the pixel-width of your text in terms of the current system
    default font.  You may wish to be sure that the field IText->ITextFont
    for 'default font' text is equal to the Font field of the screen it is
    being measured for.
```
INPUTS

```c
    IText = pointer to an instance of an [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) structure
```
RESULT

```c
    Returns the pixel-width of the text specified by the [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) data
```
BUGS

```c
    Would do better to take a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) as argument, so that a NULL in
    the Font pointer would lead automatically to the font for the
    intended target [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), rather than the system default font.
```
SEE ALSO

```c
    [OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html)
```
