/* Source: ADCD 2.1
 * Section: graphics-library-bltmaskbitmaprastport
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-bltmaskbitmaprastport.md
 */

    BltMaskBitMapRastPort
        (srcbm, srcx, srcy, destrp, destX, destY, sizeX, sizeY,
         A0     D0    D1    A1      D2     D3     D4     D5
         minterm, bltmask)
         D6       A2

    void BltMaskBitMapRastPort
         (struct [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) *, WORD, WORD, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD,
          WORD, WORD, UBYTE, APTR);
