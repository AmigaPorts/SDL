/* Source: ADCD 2.1
 * Section: gadtools-library-gt-setgadgetattrsa
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-gt-setgadgetattrsa.md
 */

    GT_SetGadgetAttrsA(gad, win, req, taglist)
                       A0   A1   A2   A3

    VOID GT_SetGadgetAttrsA(struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
        struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    GT_SetGadgetAttrs(gad, win, req, firsttag, ...)

    VOID GT_SetGadgetAttrs(struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
        struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) *, Tag, ...);
