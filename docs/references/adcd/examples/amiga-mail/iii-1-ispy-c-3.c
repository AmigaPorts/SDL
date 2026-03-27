/* Source: ADCD 2.1
 * Section: iii-1-ispy-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-1-ispy-c.md
 */

    struct JumpTable *jumptable;
    ULONG          *addressptr;
    UCOUNT          i, j;

    Forbid();

    if (jumptable = GetJumpTable(JTName))
    {
        D(zprintf("jumptable @ 0x%lx\n", jumptable));

        /* Check if this task owns this jumptable */
        if (jumptable->jt_Owner == FindTask(0))
        {

            /* Get the semaphore exclusively.
             * Depending on what got SetFunction()'ed this could take some time.
             * Also note that shared locks are used to indicate the code is
             * being executed and that shared locks can jump ahead of queue'ed
             * exclusive locks, adding to the waittime.
             */
            ObtainSemaphore((struct SignalSemaphore *) jumptable);

            Disable();

            /* Restore old pointers in jumptable */

            for (i = 2, j = 0; i < NUMBEROFFUNCTIONS * 6; i += 6, j++)
            {
                addressptr = (ULONG *) ((UBYTE *) jumptable->jt_Function + i);
                *addressptr = (*((ULONG *) LVOArray[j].lt_oldFunction));
                D(zprintf("setting table to oldFunction: 0x%lx\n", *addressptr));
            }

            Enable();

            jumptable->jt_Owner = NULL;
            ReleaseSemaphore((struct SignalSemaphore *) jumptable);
        }
    }

    Permit();

    return (TRUE);
