# radiobutton_gc/SetRadioButtonNodeAttrsA




```c
    NAME
        SetRadioButtonNodeAttrsA -- Set attributes of a RadioButton node. (V40)

    SYNOPSIS
        VOID SetRadioButtonNodeAttrs(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        SetRadioButtonNodeAttrs(node, firsttag, ...)

        VOID SetRadioButtonNodeAttrsA(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        SetRadioButtonNodeAttrsA(node, taglist)

    FUNCTION
        Changes attributes for a RadioButton node.  Since the RadioButton
        class uses a private node structure, this is the only way to change
        node attributes.

        You may NOT change node attributes when the node is in a list
        attached to a RadioButton gadget.  You must first detach the list
        with RADIOBUTTON_Labels, ~0 before you can change attributes, and
        then re-attach the list.

    TAGS
        RBNA_Label (STRPTR)

    INPUTS
        node - [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) whose attributes you are changing.
        taglist - [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) list of attributes to change.

    SEE ALSO
        [GetRadioButtonNodeAttrsA()](../Includes_and_Autodocs_3._guide/node051F.html)
```
