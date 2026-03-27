/* Source: ADCD 2.1
 * Section: ii-87-lockrecord-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-87-lockrecord-c.md
 */

    struct LockNode *lnode;

    for (lnode = locklist->lh_Head; lnode->ln_Succ; lnode = lnode->ln_Succ)
    {
        if ((lnode->ln_Offset == offset) && lnode->ln_Length == length)
            return(lnode);
    }
    return(NULL);
