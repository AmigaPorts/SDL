# graphics.library/AskFont



NAME

    AskFont -- get the text attributes of the current font
SYNOPSIS

```c
    AskFont(rp, textAttr)
            A1  A0

    void AskFont(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, struct [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) *);
```
FUNCTION

```c
    This function fills the text attributes structure with the
    attributes of the current font in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
INPUTS

```c
    rp       - the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) from which the text attributes are
               extracted
    textAttr - the [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) structure to be filled.  Note that
               there is no support for a [TTextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line73).
```
RESULT

    The textAttr structure is filled with the RastPort's text
    attributes.
BUGS

SEE ALSO

```c
    [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)
```
