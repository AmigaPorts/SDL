/* Source: ADCD 2.1
 * Section: gadtools-library-creategadgeta
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-creategadgeta.md
 */

    gad = CreateGadgetA(kind, previous, newgad, taglist)
    D0                  D0    A0        A1      A2

    struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *CreateGadgetA(ULONG, struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *,
        struct [NewGadget](../Includes_and_Autodocs_2._guide/node0106.html#line93) *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    gad = CreateGadget(kind, previous, newgad, firsttag, ...)

    struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *CreateGadget(ULONG, struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *,
        struct [NewGadget](../Includes_and_Autodocs_2._guide/node0106.html#line93) *, Tag, ...);
