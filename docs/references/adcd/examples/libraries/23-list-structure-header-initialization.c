/* Source: ADCD 2.1
 * Section: 23-list-structure-header-initialization
 * Library: libraries
 * ADCD reference: libraries/23-list-structure-header-initialization.md
 */

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
