# clicktab_gc/GetClickTabNodeAttrsA




```c
    NAME
        GetClickTabNodeAttrsA -- Get attributes about a ClickTab node.

    SYNOPSIS
        VOID GetClickTabNodeAttrs(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        GetClickTabNodeAttrs(node, firsttag, ...)

        VOID GetClickTabNodeAttrsA(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        GetClickTabNodeAttrsA(node, taglist)

    FUNCTION
        The ClickTab uses a private node structure and all attributes
        are hidden, and must therefore be accessed with this function.

    INPUTS
        node - The ClickTab node to get the information on.
        taglist - A tag list of attributes to get.  ti_Tag is the attribute
            to get and ti_Data is a pointer to a location to copy the result
            to.  The exception is LBNA_Column, which is used to specify a
            column to get attributes on.

    SEE ALSO
        [SetClickTabNodeAttrsA()](../Includes_and_Autodocs_3._guide/node00D2.html)
```
