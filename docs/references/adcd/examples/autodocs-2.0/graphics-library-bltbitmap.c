/* Source: ADCD 2.1
 * Section: graphics-library-bltbitmap
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-bltbitmap.md
 */

    planecnt = BltBitMap(SrcBitMap, SrcX, SrcY, DstBitMap,
    D0                   A0         D0:16 D1:16 A1
        DstX, DstY, SizeX, SizeY, Minterm, Mask [, TempA])
        D2:16 D3:16 D4:16  D5:16  D6:8     D7:8   [A2]

    ULONG BltBitMap(struct [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) *, WORD, WORD, struct [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) *,
        WORD, WORD, WORD, WORD, UBYTE, UBYTE, UWORD *);
