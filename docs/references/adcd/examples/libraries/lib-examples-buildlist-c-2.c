/* Source: ADCD 2.1
 * Section: lib-examples-buildlist-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-buildlist-c.md
 */

    struct NameNode *namenode;

    if (!( namenode = AllocMem(sizeof(struct NameNode),MEMF_CLEAR) ))
        printf("Out of memory\n");
    else {
        strcpy(namenode->nn_Data,name);
        namenode->nn_Node.ln_Name = namenode->nn_Data;
        namenode->nn_Node.ln_Type = NAMENODE_ID;
        namenode->nn_Node.ln_Pri  = 0;
        AddHead((struct List *)list,(struct Node *)namenode);
    }
