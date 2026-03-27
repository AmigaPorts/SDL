/* Source: ADCD 2.1
 * Section: gadtools-library-getvisualinfoa
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-getvisualinfoa.md
 */

    vi = GetVisualInfoA(screen, taglist)
    D0                  A0      A1

    APTR vi = GetVisualInfoA(struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    vi = GetVisualInfo(screen, firsttag, ...)

    APTR vi = GetVisualInfo(struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) *, Tag, ...);
