/* Source: ADCD 2.1
 * Section: gadtools-library-layoutmenusa
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-layoutmenusa.md
 */

    success = LayoutMenusA(menu, vi, taglist)
    D0                     A0    A1  A2

    BOOL LayoutMenusA(struct [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) *, APTR, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    success = LayoutMenus(menu, vi, firsttag, ...)

    BOOL LayoutMenus(struct [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) *, APTR, Tag, ...);
