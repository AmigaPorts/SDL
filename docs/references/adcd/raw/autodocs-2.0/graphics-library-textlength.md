# graphics.library/TextLength



NAME

    TextLength -- Determine raster length of text data.
SYNOPSIS

```c
    length = TextLength(rp, string, count)
    D0                  A1  A0      D0:16

    WORD TextLength(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, STRPTR, WORD);
```
FUNCTION

```c
    This graphics function determines the length that text data
    would occupy if output to the specified [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) with the
    current attributes.  The length is specified as the number of
    raster dots: to determine what the current position would be
    after a [Write()](../Includes_and_Autodocs_2._guide/node0310.html) using this string, add the length to cp_x
    (cp_y is unchanged by [Write()](../Includes_and_Autodocs_2._guide/node0310.html)).  Use the newer [TextExtent()](../Includes_and_Autodocs_2._guide/node0483.html) to
    get more information.
```
INPUTS

```c
    rp     - a pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) which describes where the
             text attributes reside.
    string - the address of string to determine the length of
    count  - the string length.  If zero, there are no characters
             in the string.
```
RESULTS

    length - the number of pixels in x this text would occupy, not
             including any negative kerning that may take place at
             the beginning of the text string, nor taking into
             account the effects of any clipping that may take
             place.
NOTES

    Prior to V36, the result length occupied only the low word of
    d0 and was not sign extended into the high word.
BUGS

    A length that would overflow single word arithmatic is not
    calculated correctly.
SEE ALSO

```c
    [TextExtent()](../Includes_and_Autodocs_2._guide/node0483.html)  [Text()](../Includes_and_Autodocs_2._guide/node0482.html)  [TextFit()](../Includes_and_Autodocs_2._guide/node0484.html)
    [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
