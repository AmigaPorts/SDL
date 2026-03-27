---
title: 23 / List Structure / Header Initialization
manual: libraries
chapter: libraries
section: 23-list-structure-header-initialization
functions: []
libraries: []
---

# 23 / List Structure / Header Initialization

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

List headers must be properly initialized before use.  It is not adequate
to initialize the entire header to zero.  The head and tail entries must
have specific values. The header must be initialized as follows:



```c
    1. Set the [lh_Head](libraries/23-list-structure-list-header-structure-definition.md) field to the address of [lh_Tail](libraries/23-list-structure-list-header-structure-definition.md).

    2. Clear the [lh_Tail](libraries/23-list-structure-list-header-structure-definition.md) field.

    3. Set the [lh_TailPred](libraries/23-list-structure-list-header-structure-definition.md) field to the address of [lh_Head](libraries/23-list-structure-list-header-structure-definition.md).

    4. Set [lh_Type](libraries/23-list-structure-list-header-structure-definition.md) to the same data type as the nodes to be kept the list.
       (Unless you are using a [MinList](libraries/23-list-structure-list-header-structure-definition.md)).


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
the macro NEWLIST, contained in the include file <exec/[lists.i](autodocs-2.0/includes-exec-lists-i.md)>.  Since
the [MinList](libraries/23-list-structure-list-header-structure-definition.md) structure is the same as the [List](libraries/23-list-structure-list-header-structure-definition.md) structure except for the
type and pad fields, this sequence of assembly language code will work for
both structures.  The sequence performs its function without destroying
the pointer to the list header in A0 (which is why ADDQ.L is used).  This
function may also be accessed from C as a call to [NewList](autodocs-2.0/amiga-lib-newlist.md)(header), where
header is the address of a list header.

