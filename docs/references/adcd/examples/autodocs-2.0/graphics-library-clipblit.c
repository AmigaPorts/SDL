/* Source: ADCD 2.1
 * Section: graphics-library-clipblit
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-clipblit.md
 */

    ClipBlit(Src, SrcX, SrcY, Dest, DestX, DestY, XSize, YSize, Minterm)
             A0   D0    D1    A1    D2     D3     D4     D5     D6

    void ClipBlit
         (struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD,
          WORD, WORD, UBYTE);
