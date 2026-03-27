# speedbar_gc/GetSpeedButtonNodeAttrsA




```c
    NAME
        GetSpeedButtonNodeAttrsA -- Get attributes about a SpeedBar node. (V40)

    SYNOPSIS
        VOID GetSpeedButtonNodeAttrs(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        GetSpeedButtonNodeAttrs(node, firsttag, ...)

        VOID GetSpeedButtonNodeAttrsA(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        GetSpeedButtonNodeAttrsA(node, taglist)

    FUNCTION
        The SpeedBar uses a private node structure and all attributes
        are hidden, and must therefore be accessed with this function.

    INPUTS
        node - The SpeedBar node to get the information on.
        taglist - A tag list of attributes to get.  ti_Tag is the attribute
            to get and ti_Data is a pointer to a location to copy the result
            to.

    SEE ALSO
        [SetSpeedButtonNodeAttrsA()](../Includes_and_Autodocs_3._guide/node056C.html)
```
