# speedbar_gc/AllocSpeedButtonNodeA




```c
    NAME
        AllocSpeedButtonNodeA -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) a SpeedBar node. (V40)

    SYNOPSIS
        struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * AllocSpeedButtonNode(UWORD, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        node = AllocSpeedButtonNode(number, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)

        struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * AllocSpeedButtonNodeA(UWORD, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        node = AllocSpeedButtonNodeA(number, taglist)

    FUNCTION
        Allocates a node that can be added to the Exec linked list of
        labels in the speedbar.  This is the only way to allocate a
        node for this list, you cannot allocate nodes yourself because
        the SpeedBar class uses a private node structure.

    INPUTS
        number - Places value in node->sbn_Node.ln_Pri, and is the
            numeric ID of the button within the bar. Note the current
            limitation, ln_Pri is a [BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48). This will be addressed, and
            *posibly* made obsolete and overridden by SBNA_ButtonID.

        taglist - Attributes for the node, passed onto
            [SetSpeedButtonNodeAttrsA()](../Includes_and_Autodocs_3._guide/node056C.html).

    RESULT
        node - A node that can be added into the Exec list of labels for
            a SpeedBar gadget.

    SEE ALSO
        [FreeSpeedButtonNode()](../Includes_and_Autodocs_3._guide/node056A.html), [SetSpeedButtonNodeAttrsA()](../Includes_and_Autodocs_3._guide/node056C.html)
```
