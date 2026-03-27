/* Source: ADCD 2.1
 * Section: graphics-library-textfit
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-textfit.md
 */

    chars = TextFit(rastport, string, strLen, textExtent,
    D0              A1        A0      D0      A2
            constrainingExtent, strDirection,
            A3                  D1
            constrainingBitWidth, constrainingBitHeight)
            D2                    D3

    ULONG TextFit(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, STRPTR, UWORD,
        struct [TextExtent](../Includes_and_Autodocs_2._guide/node00A8.html#line165) *, struct [TextExtent](../Includes_and_Autodocs_2._guide/node00A8.html#line165) *, WORD, UWORD, UWORD);
