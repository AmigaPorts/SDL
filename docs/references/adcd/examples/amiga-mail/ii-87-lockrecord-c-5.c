/* Source: ADCD 2.1
 * Section: ii-87-lockrecord-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-87-lockrecord-c.md
 */

    struct LockNode *lnode;
    LONG rargs[4];

    for (lnode = locklist->lh_Head; lnode->ln_Succ; lnode = lnode->ln_Succ)
    {
        rargs[0] = lnode->ln_Counter;
        rargs[1] = lnode->ln_Offset;
        rargs[2] = lnode->ln_Length;

        switch (lnode->ln_Mode)
        {
            case REC_EXCLUSIVE_IMMED:
                rargs[3] = (LONG)"REC_EXCLUSIVE_IMMED";
                break;
            case REC_EXCLUSIVE:
                rargs[3] = (LONG)"REC_EXCLUSIVE";
                break;
            case REC_SHARED_IMMED:
                rargs[3] = (LONG)"REC_SHARED_IMMED";
                break;
            case REC_SHARED:
                rargs[3] = (LONG)"REC_SHARED";
                break;
        }

        VFPrintf(Output(), "RecordLock #%ld: Offset %ld Length %ld Mode %s\n", rargs);
    }
    Flush(Output());
