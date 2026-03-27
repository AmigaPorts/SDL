/* Source: ADCD 2.1
 * Section: gadtools-library-drawbevelboxa
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-drawbevelboxa.md
 */

    DrawBevelBoxA(rport, left, top, width, height, taglist)
                  A0     D0    D1   D2     D3      A1

    VOID DrawBevelBoxA(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD, WORD, WORD,
        struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *taglist);

    DrawBevelBox(rport, left, top, width, height, firsttag, ...)

    VOID DrawBevelBox(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD, WORD, WORD,
        Tag, ...);
