# radiobutton_gc/AllocRadioButtonNodeA




```c
    NAME
        AllocRadioButtonNodeA -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) a RadioButton node. (V40)

    SYNOPSIS
        struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * AllocRadioButtonNode(UWORD, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        node = AllocRadioButtonNode(columns, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)

        struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * AllocRadioButtonNodeA(UWORD, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        node = AllocRadioButtonNodeA(taglist)

    FUNCTION
        Allocates a node that can be added to the Exec linked list of
        labels in the radiobutton.  This is the only way to allocate a
        node for this list, you cannot allocate nodes yourself because
        the RadioButton class uses a private node structure.

    INPUTS
        taglist - Attributes for the node, passed onto
            [SetRadioButtonNodeAttrsA()](../Includes_and_Autodocs_3._guide/node0520.html).

    RESULT
        node - A node that can be added into the Exec list of labels for
            a RadioButton gadget.

    SEE ALSO
        [FreeRadioButtonNode()](../Includes_and_Autodocs_3._guide/node051E.html), [SetRadioButtonNodeAttrsA()](../Includes_and_Autodocs_3._guide/node0520.html)
```
