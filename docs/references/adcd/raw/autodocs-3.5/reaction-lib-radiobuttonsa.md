# reaction.lib/RadioButtonsA



   NAME

       RadioButtonsA -- Make a linked list of radiobuttons
       RadioButtons -- varags stub for RadioButtonsA
   SYNOPSIS

```c
       list = RadioButtonsA( array )
       list = RadioButtons( label, ... )
       struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *RadioButtonsA( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) * )
       struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *RadioButtons( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), ... )
```
   FUNCTION

       Make a linked list of radiobutton nodes from the NULL terminated
       label array. The labels are not copied, so they must stay
       valid until the list is free'd.
   INPUTS

       array -- a NULL terminated array of string pointers.
   RESULTS

       list -- a linked list of radiobutton nodes
