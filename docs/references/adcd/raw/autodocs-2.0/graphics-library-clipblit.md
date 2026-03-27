# graphics.library/ClipBlit



NAME

```c
    ClipBlit  --  Calls [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html) after accounting for windows
```
SYNOPSIS

```c
    ClipBlit(Src, SrcX, SrcY, Dest, DestX, DestY, XSize, YSize, Minterm)
             A0   D0    D1    A1    D2     D3     D4     D5     D6

    void ClipBlit
         (struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD,
          WORD, WORD, UBYTE);
```
FUNCTION

```c
    Performs the same function as [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html), except that it
    takes into account the Layers and ClipRects of the layer library,
    all of which are (and should be) transparent to you.  So, whereas
    [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html) requires pointers to BitMaps, ClipBlit requires pointers to
    the RastPorts that contain the Bitmaps, Layers, etcetera.

    If you are going to blit blocks of data around via the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) of your
    Intuition [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), you must call this routine (rather than [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html)).

    Either the Src [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), the Dest [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), both, or neither, can have
    Layers. This routine takes care of all cases.

    See [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html) for a thorough explanation.
```
INPUTS

```c
    Src          = pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) of the source for your blit
    SrcX, SrcY   = the topleft offset into Src for your data
    Dest         = pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to receive the blitted data
    DestX, DestY = the topleft offset into the destination [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    XSize        = the width of the blit
    YSize        = the height of the blit
    Minterm      = the boolean blitter function, where SRCB is
                   associated with the Src [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) and SRCC goes to the
                   Dest [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
```
RESULT

BUGS

SEE ALSO

```c
    BltBitMap();
```
