---
title: 23 / List Structure / List Header Structure Definition
manual: libraries
chapter: libraries
section: 23-list-structure-list-header-structure-definition
functions: []
libraries: []
---

# 23 / List Structure / List Header Structure Definition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As mentioned earlier, a list header maintains memory pointers to the first
and last nodes of the linked chain of nodes.  It also serves as a handle
for referencing the entire list.  The minimum list header ("mlh_") and the
full-featured list header ("lh_") are generally interchangeable.

The structure MinList defines a minimum list header.


```c
    struct MinList
    {
        struct MinNode *mlh_Head;
        struct MinNode *mlh_Tail;
        struct MinNode *mlh_TailPred;
    };
```
mlh_Head

    points to the first node in the list.
mlh_Tail

    is always NULL.
mlh_TailPred

    points to the last node in the list.
In a few limited cases a full-featured List structure will be required:


```c
    struct List
    {
        struct Node *lh_Head;
        struct Node *lh_Tail;
        struct Node *lh_TailPred;
        UBYTE        lh_Type;
        UBYTE        lh_Pad;
    };
```
lh_Type

```c
    defines the type of nodes within the list (see <exec/[nodes.h](autodocs-2.0/includes-exec-nodes-h.md)>).
```
lh_pad

    is a structure alignment byte.
One subtlety here must be explained further.  The list header is
constructed in an efficient, but confusing manner.  Think of the header as
a structure containing the head and tail nodes for the list.  The head and
tail nodes are placeholders, and never carry data.  The head and tail
portions of the header actually overlap in memory. lh_Head and lh_Tail
form the head node; lh_Tail and lh_TailPred form the tail node.  This
makes it easy to find the start or end of the list, and eliminates any
special cases for insertion or removal.



```c
           ___________                     ___________
          |           |                   |           |
          |  ln_Succ  |                   |  lh_Head  |
          |___________|___________        |___________|
          |           |           |       |           |
          | ln_Pred=0 | ln_Succ=0 |       | lh_Tail=0 |
          |___________|___________| ____\ |___________|
                      |           |     / |           |
                      |  ln_Pred  |       |lh_TailPred|
                      |___________|       |___________|


               Figure 23-2: List Header Overlap
```
The lh_Head and lh_Tail fields of the list header act like the [ln_Succ](libraries/23-list-structure-node-structure-definition.md) and
lh_Pred fields of a node.  The lh_Tail field is set permanently to NULL,
indicating that the head node is indeed the first on the list -- that is,
it has no predecessors.  See the figure above.

Likewise, the lh_Tail and lh_TailPred fields of the list header act like
the [ln_Succ](libraries/23-list-structure-node-structure-definition.md) and lh_Pred fields of a node. Here the NULL lh_Tail indicates
that the tail node is indeed the last on the list -- that is, it has no
successors.  See the figure above.

