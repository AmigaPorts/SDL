# 23 / List Functions / Empty Lists


It is often important to determine if a list is empty.  This can be done
in many ways, but only two are worth mentioning.  If either the
[lh_TailPred](../Libraries_Manual_guide/node02DB.html#line20) field is pointing to the list header or the [ln_Succ](../Libraries_Manual_guide/node02D9.html#line13) field of
the [lh_Head](../Libraries_Manual_guide/node02DB.html#line14) is NULL, then the list is empty.

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

