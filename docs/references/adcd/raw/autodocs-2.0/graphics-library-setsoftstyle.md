# graphics.library/SetSoftStyle



NAME

    SetSoftStyle -- Set the soft style of the current font.
SYNOPSIS

```c
    newStyle = SetSoftStyle(rp, style, enable)
    D0                      A1  D0     D1

    ULONG SetSoftStyle(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, ULONG, ULONG);
```
FUNCTION

    This function alters the soft style of the current font.  Only
    those bits that are also set in enable are affected.  The
    resulting style is returned, since some style request changes
    will not be honored when the implicit style of the font
    precludes changing them.
INPUTS

```c
    rp     - the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) from which the font and style
             are extracted.
    style  - the new font style to set, subject to enable.
    enable - those bits in style to be changed.  Any set bits here
             that would not be set as a result of [AskSoftStyle](../Includes_and_Autodocs_2._guide/node041C.html) will
             be ignored, and the newStyle result will not be as
             expected.
```
RESULTS

    newStyle - the resulting style, both as a result of previous
               soft style selection, the effect of this function,
               and the style inherent in the set font.
BUGS

SEE ALSO

```c
    [AskSoftStyle()](../Includes_and_Autodocs_2._guide/node041C.html)  [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)
```
