/* Source: ADCD 2.1
 * Section: listbrowser-gc-alloclistbrowsernodea
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/listbrowser-gc-alloclistbrowsernodea.md
 */

    NAME
        AllocListBrowserNodeA -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) a ListBrowser node.

    SYNOPSIS
        struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * AllocListBrowserNode(UWORD, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        node = AllocListBrowserNode(columns, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)

        struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * AllocListBrowserNodeA(UWORD, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        node = AllocListBrowserNodeA(columns, taglist)

    FUNCTION
        Allocates a node that can be added to the Exec linked list of
        labels in the listbrowser.  This is the only way to allocate a
        node for this list, you cannot allocate nodes yourself because
        the ListBrowser class uses a private node structure.

    TAGS
        See [SetListBrowserNodeAttrsA()](../Includes_and_Autodocs_3._guide/node044B.html) for the list of supported tags.  In
        addition, AllocListBrowserNodeA() supports the following additional
        tags:

        LBNA_NodeSize (ULONG) (V41)
        The size in bytes of the public portion of the node structure that
        should be allocated.  Usually the default (sizeof(struct Node)) will
        suffice, unless you wish to have a custom node structure embedded
        within the ListBrowser node, in which case you'd provide the size
        of that structure.  Then the node returned can be treated as an
        instance of your custom node structure.

        Defaults to sizeof(struct Node).

    INPUTS
        columns - How many columns your ListBrowser has.
        taglist - Attributes for the node, passed onto
            [SetListBrowserNodeAttrsA()](../Includes_and_Autodocs_3._guide/node044B.html).

    RESULT
        node - A node that can be added into the Exec list of labels for
            a ListBrowser gadget.

    SEE ALSO
        [FreeListBrowserNode()](../Includes_and_Autodocs_3._guide/node0446.html), [SetListBrowserNodeAttrsA()](../Includes_and_Autodocs_3._guide/node044B.html)
