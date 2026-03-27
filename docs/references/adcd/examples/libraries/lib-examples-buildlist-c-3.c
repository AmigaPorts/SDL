/* Source: ADCD 2.1
 * Section: lib-examples-buildlist-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-buildlist-c.md
 */

    struct NameNode *worknode;
    struct NameNode *nextnode;

    worknode = (struct NameNode *)(list->lh_Head); /* First node */
    while (nextnode = (struct NameNode *)(worknode->nn_Node.ln_Succ)) {
        FreeMem(worknode,sizeof(struct NameNode));
        worknode = nextnode;
    }
