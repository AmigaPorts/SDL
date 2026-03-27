# reaction.lib/ClickTabsA



   NAME

       ClickTabsA -- Make a linked list of clicktab nodes
       ClickTabs -- varags stub for ClickTabsA
   SYNOPSIS

```c
       list = ClickTabsA( array )
       list = ClickTabs( label, ... )
       struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *ClickTabsA( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) * )
       struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *ClickTabs( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), ... )
```
   FUNCTION

       Make a linked list of clicktab nodes from the NULL terminated
       label array. The labels are not copied, so they must stay
       valid until the list is free'd.
   INPUTS

       array -- a NULL terminated array of string pointers.
   RESULTS

       list -- a linked list of clicktab nodes
