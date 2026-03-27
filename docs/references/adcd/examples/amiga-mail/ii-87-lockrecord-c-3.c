/* Source: ADCD 2.1
 * Section: ii-87-lockrecord-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-87-lockrecord-c.md
 */

    struct RDArgs *readargs;
    LONG rargs[5];
    ULONG offset, length, timeout, mode;
    ULONG result;
    struct LockNode *lnode;

    offset = length = timeout = mode = 0;
    rargs[0] = rargs[1] = rargs[2] = rargs[3] = rargs[4] = 0;

    if (readargs = ReadArgs(LOCK_TEMPLATE, rargs, rdargs))
    {

        if (rargs[OFFSET_POS])
            offset = *((LONG *)rargs[OFFSET_POS]);
        if (rargs[LENGTH_POS])
            length = *((LONG *)rargs[LENGTH_POS]);
        if (rargs[TIMEOUT_POS])
            timeout = *((LONG *)rargs[TIMEOUT_POS]);

        /* Type of locking */
        if (rargs[EXCLUSIVE_POS])
        {
            if (rargs[IMMEDIATE_POS])
                mode = REC_EXCLUSIVE_IMMED;
            else
                mode = REC_EXCLUSIVE;
        }
        else
        {
            if (rargs[IMMEDIATE_POS])
                mode = REC_SHARED_IMMED;
            else
                mode = REC_SHARED;
        }

        rargs[0] = offset;
        rargs[1] = length;
        switch (mode)
        {
            case REC_EXCLUSIVE_IMMED:
                rargs[2] = (LONG)"REC_EXCLUSIVE_IMMED";
                break;
            case REC_EXCLUSIVE:
                rargs[2] = (LONG)"REC_EXCLUSIVE";
                break;
            case REC_SHARED_IMMED:
                rargs[2] = (LONG)"REC_SHARED_IMMED";
                break;
            case REC_SHARED:
                rargs[2] = (LONG)"REC_SHARED";
                break;
        }
        rargs[3] = timeout;


        /* Show what I'm going to do */
        VFPrintf(Output(),
            "LockRecord: Offset %ld, Length %ld, Mode %s, Timeout %ld...",
            rargs);
        Flush(Output());

        /* Lock the record. Parameters are not checked. It is f.e. possible to
         * specify an offset larger than the size of the file. Possible since
         * Record Locks are not related to the file itself, only the means for
         * you to do arbitration.
         *
         * Note that the timeout value is in ticks...
         */
        result = LockRecord(fh, offset, length, mode, timeout);

        if (result == DOSTRUE)
        {
            Write(Output(), "OK\n", 3);

            /* Add a node to track this record lock */
            if (lnode = AllocMem(sizeof(struct LockNode), MEMF_CLEAR))
            {
                lnode->ln_Counter = locklist->lh_Counter++;
                lnode->ln_Offset = offset;
                lnode->ln_Length = length;
                lnode->ln_Mode = mode;

                AddTail((struct List *)locklist, (struct Node *)lnode);
            }
            else
            {
                /* Not enough memory for node. You're on your own... */
                Write(Output(), "Not enough memory to track record lock.\n", 40);
            }
        }
        else
        {
            Write(Output(), "FAILED\n", 7);
            if (IoErr())
                PrintFault(IoErr(), NULL);
        }

        /* Release memory associated with readargs */
        FreeArgs(readargs);
    } else
        PrintFault(IoErr(), NULL);
