# 23 / List Structure / Header Initialization


List headers must be properly initialized before use.  It is not adequate
to initialize the entire header to zero.  The head and tail entries must
have specific values. The header must be initialized as follows:



```c
    1. Set the [lh_Head](../Libraries_Manual_guide/node02DB.html#line14) field to the address of [lh_Tail](../Libraries_Manual_guide/node02DB.html#line17).

    2. Clear the [lh_Tail](../Libraries_Manual_guide/node02DB.html#line17) field.

    3. Set the [lh_TailPred](../Libraries_Manual_guide/node02DB.html#line20) field to the address of [lh_Head](../Libraries_Manual_guide/node02DB.html#line14).

    4. Set [lh_Type](../Libraries_Manual_guide/node02DB.html#line34) to the same data type as the nodes to be kept the list.
       (Unless you are using a [MinList](../Libraries_Manual_guide/node02DB.html#line5)).


         Figure 23-3: Initializing a List Header Structure

                                             _________________
                                            |   ___________   |
                                            |  |           |__|
                                            |  |  lh_Head  |/_
                                            |  |___________|\ |
                                            |_\|           |  |
                                              /| lh_Tail=0 |  |
                                               |___________|  |
                                               |           |  |
                                               |lh_TailPred|__|
                                               |_ _ _ _ _ _|
                                               |     |     |
    /* C example - equivalent to NewList() */  |     |     |
    struct List list;                          |_ _ _|_ _ _|

    list.lh_Head          = (struct Node *) &list.lh_Tail;
    list.lh_Tail          = 0;
    list.lh_TailPred      = (struct Node*) &list.lh_Head;
    /* Now set lh_Type, if needed */

    ;Assembly example - equivalent to NEWLIST
          MOVE.L  A0,LH_HEAD(A0)  ;A0 points to the list header
          ADDQ.L  #4,LH_HEAD(A0)  ;Bump LH_HEAD(A0) to address of LH_TAIL
          CLR.L   LH_TAIL(A0)
          MOVE.L  A0,LH_TAILPRED(A0)
    ;Now set LH_TYPE, if needed.
```
The sequence of assembly instructions in the figure above is equivalent to
the macro NEWLIST, contained in the include file <exec/[lists.i](../Includes_and_Autodocs_2._guide/node0081.html#line44)>.  Since
the [MinList](../Libraries_Manual_guide/node02DB.html#line5) structure is the same as the [List](../Libraries_Manual_guide/node02DB.html#line23) structure except for the
type and pad fields, this sequence of assembly language code will work for
both structures.  The sequence performs its function without destroying
the pointer to the list header in A0 (which is why ADDQ.L is used).  This
function may also be accessed from C as a call to [NewList](../Includes_and_Autodocs_2._guide/node0161.html)(header), where
header is the address of a list header.

