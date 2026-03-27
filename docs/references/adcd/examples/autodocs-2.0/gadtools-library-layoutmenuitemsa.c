/* Source: ADCD 2.1
 * Section: gadtools-library-layoutmenuitemsa
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-layoutmenuitemsa.md
 */

    success = LayoutMenuItemsA(menuitem, vi, taglist)
    D0                         A0        A1  A2

    BOOL LayoutMenuItemsA(struct [MenuItem](../Includes_and_Autodocs_2._guide/node00D4.html#line89) *, APTR, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    success = LayoutMenuItems(menuitem, vi, firsttag, ...)

    BOOL LayoutMenuItemsA(struct [MenuItem](../Includes_and_Autodocs_2._guide/node00D4.html#line89) *, APTR, Tag, ...);
