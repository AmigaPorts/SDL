# graphics.library/TextExtent



NAME

```c
    [TextExtent](../Includes_and_Autodocs_2._guide/node00A8.html#line165) -- Determine raster extent of text data. (V36)
```
SYNOPSIS

```c
    TextExtent(rp, string, count, textExtent)
               A1  A0      D0:16  A2

    void TextExtent(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, STRPTR, WORD,
         struct [TextExtent](../Includes_and_Autodocs_2._guide/node00A8.html#line165) *);
```
FUNCTION

```c
    This function determines a more complete metric of the space
    that a text string would render into than the [TextLength()](../Includes_and_Autodocs_2._guide/node0485.html)
    function.
```
INPUTS

```c
    rp     - a pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) which describes where the
             text attributes reside.
    string - the address of the string to determine the length of.
    count  - the number of characters in the string.
            If zero, there are no characters in the string.
    textExtent - a structure to hold the result.
```
RESULTS

```c
    textExtent is filled in as follows:
        te_Width  - same as [TextLength()](../Includes_and_Autodocs_2._guide/node0485.html) result: the rp_cp_x
                    advance that rendering this text would cause.
        te_Height - same as tf_YSize.  The height of the
                    font.
        te_Extent.MinX - the offset to the left side of the
                    rectangle this would render into.  Often zero.
        te_Extent.MinY - same as -tf_Baseline.  The offset
                    from the baseline to the top of the rectangle
                    this would render into.
        te_Extent.MaxX - the offset of the left side of the
                    rectangle this would render into.  Often the
                    same as te_Width-1.
        te_Extent.MaxY - same as tf_YSize-tf_Baseline-1.
                    The offset from the baseline to the bottom of
                    the rectanangle this would render into.
```
SEE ALSO

```c
    [TextLength()](../Includes_and_Autodocs_2._guide/node0485.html)  [Text()](../Includes_and_Autodocs_2._guide/node0482.html)  [TextFit()](../Includes_and_Autodocs_2._guide/node0484.html)
    [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
