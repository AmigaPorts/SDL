# chooser_gc/AllocChooserNodeA




```c
    NAME
        AllocChooserNodeA -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) a Chooser node.

    SYNOPSIS
        struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * AllocChooserNode(Tag, ...)
        node = AllocChooserNode(columns, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)

        struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * AllocChooserNodeA(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        node = AllocChooserNodeA(taglist)

    FUNCTION
        Allocates a node that can be added to the Exec linked list of
        labels in the chooser.  This is the only way to allocate a
        node for this list, you cannot allocate nodes yourself because
        the Chooser class uses a private node structure.

    INPUTS
        taglist - Attributes for the node, passed onto [SetChooserNodeAttrsA()](../Includes_and_Autodocs_3._guide/node00C6.html).

    RESULT
        node - A node that can be added into the Exec list of labels for
            a Chooser gadget.

    SEE ALSO
        [FreeChooserNode()](../Includes_and_Autodocs_3._guide/node00C4.html), [SetChooserNodeAttrsA()](../Includes_and_Autodocs_3._guide/node00C6.html)
```
