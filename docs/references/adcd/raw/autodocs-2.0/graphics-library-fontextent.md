# graphics.library/FontExtent



NAME

```c
    FontExtent -- get the font attributes of the current font (V36)
```
SYNOPSIS

```c
    FontExtent(font, fontExtent)
               A0    A1

    void FontExtent(struct [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) *, struct [TextExtent](../Includes_and_Autodocs_2._guide/node00A8.html#line165) *);
```
FUNCTION

```c
    This function fills the text extent structure with a bounding
    (i.e. maximum) extent for the characters in the specified font.
```
INPUTS

```c
    font       - the [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) from which the font metrics are extracted.
    fontExtent - the [TextExtent](../Includes_and_Autodocs_2._guide/node00A8.html#line165) structure to be filled.
```
RESULT

    fontExtent is filled.
NOTES

```c
    The [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90), not the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), is specified -- unlike
    [TextExtent()](../Includes_and_Autodocs_2._guide/node0483.html), effect of algorithmic enhancements is not
    included, nor does te_Width include any effect of
    rp_TxSpacing.  The returned te_Width will be negative only
    when FPF_REVPATH is set in the tf_Flags of the font -- the
    effect of left-moving characters is ignored for the width of
    a normal font, and the effect of right-moving characters is
    ignored if a REVPATH font.  These characters will, however,
    be reflected in the bounding extent.
```
SEE ALSO

```c
    [TextExtent()](../Includes_and_Autodocs_2._guide/node0483.html)  [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)
```
