/* Source: ADCD 2.1
 * Section: lib-examples-buildlist-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-buildlist-c.md
 */

    if (list->lh_TailPred == (struct Node *)list)
        printf("List is empty.\n");
    else {
        for (node = list->lh_Head ; node->ln_Succ ; node = node->ln_Succ)
            printf("%lx -> %s\n",node,node->ln_Name);
    }
