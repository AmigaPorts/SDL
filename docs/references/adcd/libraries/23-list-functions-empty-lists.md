---
title: 23 / List Functions / Empty Lists
manual: libraries
chapter: libraries
section: 23-list-functions-empty-lists
functions: []
libraries: []
---

# 23 / List Functions / Empty Lists

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

It is often important to determine if a list is empty.  This can be done
in many ways, but only two are worth mentioning.  If either the
[lh_TailPred](libraries/23-list-structure-list-header-structure-definition.md) field is pointing to the list header or the [ln_Succ](libraries/23-list-structure-node-structure-definition.md) field of
the [lh_Head](libraries/23-list-structure-list-header-structure-definition.md) is NULL, then the list is empty.

In C, for example, these methods would be written as follows:


```c
    /* You can use this method...   */
    if (list->lh_TailPred == (struct Node *)list)
        printf("list is empty\n");

    /* Or you can use this method   */
    if (NULL == list->lh_Head->ln_Succ)
        printf("list is empty\n");
```
In assembly code, if A0 points to the list header, these methods would be
written as follows:


```c
    ; Use this method...
    CMP.L   LH_TAILPRED(A0),A0
    BEQ     list_is_empty

    ; Or use this method
    MOVE.L  LH_HEAD(A0),A1
    TST.L   LN_SUCC(A1)
    BEQ     list_is_empty
```
Because LH_HEAD and LN_SUCC are both zero offsets, the second case may be
simplified or optimized by your assembler.

