---
title: 23 / List Functions / Scanning a List
manual: libraries
chapter: libraries
section: 23-list-functions-scanning-a-list
functions: []
libraries: []
---

# 23 / List Functions / Scanning a List

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Occasionally a program may need to scan a list to locate a particular
node, find a node that has a field with a particular value, or just print
the list.  Because lists are linked in both the forward and backward
directions, the list can be scanned from either the head or tail.

Here is a code fragment that uses a for loop to print the names of all
nodes in a list:


```c
    struct List *list;
    struct Node *node;

    for (node = list->lh_Head ; node->ln_Succ ; node = node->ln_Succ)
        printf("%lx -> %s\n",node,node->ln_Name);
```
A common mistake is to process the head or tail nodes.  Valid data nodes
have non-NULL successor and predecessor pointers.  The above loop exits
when [node->ln_Succ](libraries/23-list-structure-node-structure-definition.md) is NULL.  Another common mistake is to free a node from
within a loop, then reference the free memory to obtain the next node
pointer.  An extra temporary pointer solves this second problem.

In assembly code, it is more efficient to use a look-ahead cache pointer
when scanning a list.  In this example the list is scanned until the first
zero-priority node is reached:


```c
            MOVE.L  (A1),D1         ; first node
    scan:   MOVE.L  D1,A1
            MOVE.L  (A1),D1         ; lookahead to next
            BEQ.S   not_found       ; end of list...
            TST.B   LN_PRI(A1)
            BNE.S   scan
            ...                     ; found one

    not_found:

     [Exec List Example](libraries/lib-examples-buildlist-c.md) 
```
