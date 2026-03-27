/* Source: ADCD 2.1
 * Section: ii-87-lockrecord-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-87-lockrecord-c.md
 */

    struct RDArgs *readargs;
    LONG rargs[2];
    ULONG offset, length;
    ULONG result;
    struct LockNode *lnode;

    offset = length = 0;
    rargs[0] = rargs[1] = 0;

    if (readargs = ReadArgs(LOCK_TEMPLATE, rargs, rdargs))
    {

        if (rargs[OFFSET_POS])
            offset = *((LONG *)rargs[OFFSET_POS]);
        if (rargs[LENGTH_POS])
            length = *((LONG *)rargs[LENGTH_POS]);

        rargs[0] = offset;
        rargs[1] = length;

        /* Show what I'm going to do */
        VFPrintf(Output(), "UnLockRecord: Offset %ld, Length %ld...", rargs);
        Flush(Output());

        /* Unlock indicated record with indicated offset and length.
         * If the same record (same offset/length) is locked multiple times,
         * only one, the first one in the list , will be unlocked.
         */
        result = UnLockRecord(fh, offset, length);

        if (result == DOSTRUE) {
            Write(Output(), "OK\n", 3);

            /* Remove node associated with this lock */
            if (lnode = FindRecordLock(offset, length))
            {
                Remove((struct Node *)lnode);
                FreeMem(lnode, sizeof(struct LockNode));
            }
        }
        else
        {
            Write(Output(), "FAILED\n", 7); /* Keep locknode */
            if (IoErr())
                PrintFault(IoErr(), NULL);
        }
        /* Release memory associated with readargs */
        FreeArgs(readargs);
    } else
        PrintFault(IoErr(), NULL);
