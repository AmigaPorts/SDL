/* Source: ADCD 2.1
 * Section: iv-3-lockpub-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-lockpub-c.md
 */

    struct List *publist;
    struct List *copy_publist;
    struct PubScreenNode *psnode;
    struct PubScreenNode *copy_psnode;

    /* fails silently if not V36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36)) {
        if (copy_publist = AllocMem(sizeof(struct List), MEMF_CLEAR)) {
            NewList(copy_publist);

            /* Lock the public screen list */
            publist = LockPubScreenList();

            /* and copy it */
            for (psnode = (struct PubScreenNode *)publist->lh_Head;
                     psnode->psn_Node.ln_Succ;
                     psnode = (struct PubScreenNode *)psnode->psn_Node.ln_Succ) {
                if (copy_psnode = AllocMem(sizeof(struct PubScreenNode), MEMF_CLEAR)) {
                    /* Copy the structure */
                    *copy_psnode = *psnode;

                    /* ln_Name points to the public screen name, make your own copy */
                    if (copy_psnode->psn_Node.ln_Name =
                            AllocMem(strlen(psnode->psn_Node.ln_Name) + 1, MEMF_CLEAR))
                        strcpy(copy_psnode->psn_Node.ln_Name, psnode->psn_Node.ln_Name);
                    else
                        printf("Not enough memory to copy screen name\n");

                    AddTail(copy_publist, (struct Node *)copy_psnode);
                } else {
                    printf("out of memory\n");
                    break;
                }
           }
           UnlockPubScreenList();

           psnode = (struct PubScreenNode *)copy_publist->lh_Head;
           while (copy_psnode = (struct PubScreenNode *)psnode->psn_Node.ln_Succ) {
                printf("%s\n", psnode->psn_Node.ln_Name);

                printf("psn_Screen       0x%lx\n", psnode->psn_Screen);
