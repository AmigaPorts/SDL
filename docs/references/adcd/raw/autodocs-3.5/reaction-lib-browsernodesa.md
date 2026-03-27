# reaction.lib/BrowserNodesA



   NAME

       BrowserNodesA -- Make a linked list of listbrowser nodes
       BrowserNodes -- varags stub for BrowserNodesA
   SYNOPSIS

```c
       list = BrowserNodesA( array )
       list = BrowserNodes( label, ... )
       struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *BrowserNodesA( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) * )
       struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *BrowserNodes( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), ... )
```
   FUNCTION

       Make a linked list of single column listbrowser nodes from the
       NULL terminated label array. The labels are not copied, so they
       must stay valid until the list is free'd.
   INPUTS

       array -- a NULL terminated array of string pointers.
   RESULTS

       list -- a linked list of chooser nodes
