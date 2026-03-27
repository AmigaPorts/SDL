# listbrowser_gc/GetListBrowserNodeAttrsA




```c
    NAME
        GetListBrowserNodeAttrsA -- Get attributes about a ListBrowser node.

    SYNOPSIS
        VOID GetListBrowserNodeAttrs(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        GetListBrowserNodeAttrs(node, firsttag, ...)

        VOID GetListBrowserNodeAttrsA(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        GetListBrowserNodeAttrsA(node, taglist)

    FUNCTION
        The ListBrowser uses a private node structure and all attributes
        are hidden, and must therefore be accessed with this function.

    TAGS
        See [SetListBrowserNodeAttrsA()](../Includes_and_Autodocs_3._guide/node044B.html) for the list of supported tags.

    INPUTS
        node - The ListBrowser node to get the information on.
        taglist - A tag list of attributes to get.  ti_Tag is the attribute
            to get and ti_Data is a pointer to a location to copy the result
            to.  The exception is LBNA_Column, which is used to specify a
            column to get attributes on.

    SEE ALSO
        [SetListBrowserNodeAttrsA()](../Includes_and_Autodocs_3._guide/node044B.html)
```
