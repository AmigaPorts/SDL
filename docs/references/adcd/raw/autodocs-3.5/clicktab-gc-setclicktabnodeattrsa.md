# clicktab_gc/SetClickTabNodeAttrsA




```c
    NAME
        SetClickTabNodeAttrsA -- Set attributes of a ClickTab node.

    SYNOPSIS
        VOID SetClickTabNodeAttrs(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        SetClickTabNodeAttrs(node, firsttag, ...)

        VOID SetClickTabNodeAttrsA(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        SetClickTabNodeAttrsA(node, taglist)

    FUNCTION
        Changes attributes for a ClickTab node.  Since the ClickTab
        class uses a private node structure, this is the only way to change
        node attributes.

        You may NOT change node attributes when the node is in a list
        attached to a ClickTab gadget.  You must first detach the list
        with CLICKTAB_Labels, ~0 before you can change attributes, and
        then re-attach the list, and re-render the gadget to reflect
        any changes. This should include re-domaining the gadget.
        If used in a layout group, turn off domain caching for the
        clicktab object if you intend to dynamically alter the tabs
        and refresh the layout group with [RethinkLayout()](../Includes_and_Autodocs_3._guide/node043D.html).

    TAGS
        TNA_Text (STRPTR)

            [Text](../Includes_and_Autodocs_3._guide/node0332.html) string to appear as a line in the ClickTab menu node.

        TNA_Number (WORD)

            ID Number assigned to a ClickTab menu node

        TNA_TextPen (WORD)

            Specifies pen number to use for the label.

            Defaults to pens[TEXTPEN].

    INPUTS
        node - [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) whose attributes you are changing.
        taglist - [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) list of attributes to change.

    SEE ALSO
        [GetClickTabNodeAttrsA()](../Includes_and_Autodocs_3._guide/node00D1.html)
```
