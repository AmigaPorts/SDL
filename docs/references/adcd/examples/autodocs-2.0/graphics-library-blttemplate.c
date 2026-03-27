/* Source: ADCD 2.1
 * Section: graphics-library-blttemplate
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-blttemplate.md
 */

    BltTemplate(SrcTemplate, SrcX, SrcMod, rp,
                A0           D0:16  D1:16  A1
        DstX,  DstY, SizeX, SizeY)
        D2:16  D3:16 D4:16  D5:16

    void BltTemplate(UWORD *, WORD, WORD, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *,
         WORD, WORD, WORD, WORD);
