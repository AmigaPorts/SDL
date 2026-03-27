# clicktab_gc/AllocClickTabNodeA




```c
    NAME
        AllocClickTabNodeA -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) a ClickTab node.

    SYNOPSIS
        struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * AllocClickTabNode(Tag, ...)
        node = AllocClickTabNode(Tag, ...)

        struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * AllocClickTabNodeA(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        node = AllocClickTabNodeA(taglist)

    FUNCTION
        Allocates a node that can be added to the Exec linked list of
        labels in the clicktab.  This is the only way to allocate a
        node for this list, you cannot allocate nodes yourself because
        the ClickTab class uses a private node structure.

    INPUTS
        columns - How many columns your ClickTab has.
        taglist - Attributes for the node, passed onto [SetClickTabNodeAttrsA()](../Includes_and_Autodocs_3._guide/node00D2.html).

    RESULT
        node - A node that can be added into the Exec list of labels for
            a ClickTab gadget.

    SEE ALSO
        [FreeClickTabNode()](../Includes_and_Autodocs_3._guide/node00D0.html), [SetClickTabNodeAttrsA()](../Includes_and_Autodocs_3._guide/node00D2.html)
```
