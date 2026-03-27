# radiobutton_gc/GetRadioButtonNodeAttrsA




```c
    NAME
        GetRadioButtonNodeAttrsA -- Get attributes about a RadioButton node. (V40)

    SYNOPSIS
        VOID GetRadioButtonNodeAttrs(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        GetRadioButtonNodeAttrs(node, firsttag, ...)

        VOID GetRadioButtonNodeAttrsA(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        GetRadioButtonNodeAttrsA(node, taglist)

    FUNCTION
        The RadioButton uses a private node structure and all attributes
        are hidden, and must therefore be accessed with this function.

    INPUTS
        node - The RadioButton node to get the information on.
        taglist - A tag list of attributes to get.  ti_Tag is the attribute
        to get and ti_Data is a pointer to a location to copy the result
        to.

    SEE ALSO
        [SetRadioButtonNodeAttrsA()](../Includes_and_Autodocs_3._guide/node0520.html)
```
