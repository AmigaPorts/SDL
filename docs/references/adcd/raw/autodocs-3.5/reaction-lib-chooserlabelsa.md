# reaction.lib/ChooserLabelsA



   NAME

       ChooserLabelsA -- Make a linked list of chooser labels
       ChooserLabels -- varags stub for ChooserLabelsA
   SYNOPSIS

```c
       list = ChooserLabelsA( array )
       list = ChooserLabels( label, ... )
       struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *ChooserLabelsA( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) * )
       struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *ChooserLabels( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), ... )
```
   FUNCTION

       Make a linked list of chooser nodes from the NULL terminated
       label array. The labels are not copied, so they must stay
       valid until the list is free'd.
   INPUTS

       array -- a NULL terminated array of string pointers.
   RESULTS

       list -- a linked list of chooser nodes
