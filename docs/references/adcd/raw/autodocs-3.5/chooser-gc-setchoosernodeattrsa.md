# chooser_gc/SetChooserNodeAttrsA




```c
    NAME
        SetChooserNodeAttrsA -- Set attributes of a Chooser node.

    SYNOPSIS
        VOID SetChooserNodeAttrs(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        SetChooserNodeAttrs(node, firsttag, ...)

        VOID SetChooserNodeAttrsA(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        SetChooserNodeAttrsA(node, taglist)

    FUNCTION
        Changes attributes for a Chooser node.  Since the Chooser
        class uses a private node structure, this is the only way to change
        node attributes.

        You may NOT change node attributes when the node is in a list
        attached to a Chooser gadget.  You must first detach the list
        with CHOOSER_Labels, ~0 before you can change attributes, and
        then re-attach the list.

    TAGS
        CNA_Text (STRPTR)
        [Text](../Includes_and_Autodocs_3._guide/node0332.html) string to appear as a line in the Chooser menu. This tag
        must be supplied for the node.

        CNA_Image (struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) *)
        [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) to be placed to the left of the CNA_Text in the Chooser menu.

        CNA_SelImage (struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) *)
        Selected state [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) to be placed to the left of the CNA_Text in
        the Chooser menu.

        CNA_ReadOnly (BOOL) (V41.4)
        Item will not be highlight rendered when selected.

        CNA_Disabled (BOOL) (V41.5)
        Item can not be selected. No GADGETUP message is generated.

        CNA_Separator (BOOL) (V41.7)
        Separator (~~~~) Bar Item can not be selected. Simular to the
        separator bars in Intuition menus. No GADGETUP message is generated.

    INPUTS
        node - [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) whose attributes you are changing.
        taglist - [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) list of attributes to change.

    SEE ALSO
        [GetChooserNodeAttrsA()](../Includes_and_Autodocs_3._guide/node00C5.html)
```
