/* Source: ADCD 2.1
 * Section: intuition-library-setgadgetattrsa
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-setgadgetattrsa.md
 */

    result = SetGadgetAttrsA( [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215), [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145), TagList )
    D0                        A0      A1      A2         A3

    ULONG SetGadgetAttrsA( struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
            struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) * );

    result = SetGadgetAttrs( [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215), [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145), Tag1, ...)

    ULONG SetGadgetAttrs( struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
            struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) *, ULONG, ... );
