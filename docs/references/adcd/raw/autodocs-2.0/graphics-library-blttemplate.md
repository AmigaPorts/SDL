# graphics.library/BltTemplate



NAME

```c
    BltTemplate -- Cookie cut a shape in a rectangle to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
SYNOPSIS

```c
    BltTemplate(SrcTemplate, SrcX, SrcMod, rp,
                A0           D0:16  D1:16  A1
        DstX,  DstY, SizeX, SizeY)
        D2:16  D3:16 D4:16  D5:16

    void BltTemplate(UWORD *, WORD, WORD, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *,
         WORD, WORD, WORD, WORD);
```
FUNCTION

```c
    This function draws the image in the template into the
    [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) in the current color and drawing mode at the
    specified position.  The template is assumed not to overlap
    the destination.
    If the template falls outside the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) boundary, it is
    truncated to that boundary.

    Note: the SrcTemplate pointer should point to the "nearest" word
       (rounded down) of the template mask. Fine alignment of the mask
       is acheived by setting the SrcX bit offseet within the range
       of 0 to 15 decimal.
```
INPUTS

```c
    SrcTemplate  - pointer to the first (nearest) word of the template
                   mask.
    SrcX         - x bit offset into the template mask (range 0..15).
    SrcMod       - number of bytes per row in template mask.
    rp           - pointer to destination [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
    DstX, DstY   - x and y coordinates of the upper left
                   corner of the destination for the blit.
    SizeX, SizeY - size of the rectangle to be used as the
                   template.
```
NOTES

    o   This function may use the blitter.
SEE ALSO

```c
    [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
