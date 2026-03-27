/* Source: ADCD 2.1
 * Section: iii-1-ispy-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-1-ispy-c.md
 */

    struct JumpTable *jumptable;
    ULONG          *addressptr;
    UWORD          *jmpinstr;
    UBYTE          *jtname;
    UCOUNT          i, j;

    /* Not really necessary to forbid again, just to indicate that I don't
     * want another task to create the semaphore while I'm trying to do the
     * same. Here GetJumpTable() is only called from InstallWedge(), so it
     * will just bump the forbid count.
     */
    Forbid();

    if (!(jumptable = (struct JumpTable *) FindSemaphore(name)))
    {
        if (jumptable = AllocMem(sizeof(struct JumpTable), MEMF_PUBLIC | MEMF_CLEAR))
        {
            if (jtname = AllocMem(32, MEMF_PUBLIC | MEMF_CLEAR))
            {

                for (i = 0, j = 0; i < NUMBEROFFUNCTIONS * 6; i += 6, j++)
                {
                    jmpinstr = (UWORD *) ((UBYTE *) jumptable->jt_Function + i);
                    *jmpinstr = 0x4EF9;

                    addressptr = (ULONG *) ((UBYTE *) jumptable->jt_Function + i + 2);
                    *addressptr = (ULONG) SetFunction(
                        (struct Library *) (*((ULONG *) LVOArray[j].lt_LibBase)),
                        LVOArray[j].lt_LVO,
                        (VOID *) ((UBYTE *) jumptable->jt_Function + i));
                }

                jumptable->jt_Semaphore.ss_Link.ln_Pri = 0;

                strcpy(jtname, name);
                jumptable->jt_Semaphore.ss_Link.ln_Name = jtname;
                AddSemaphore((struct SignalSemaphore *) jumptable);
                /* In 1.2/1.3 AddSemaphore() didn't work properly.
                ** Under 1.2/1.3, change it to:
                ** InitSemaphore(jumptable);
                ** Forbid();
                ** Enqueue(&SysBase->SemaphoreList, jumptable);
                ** Permit();
                */
            }
            else
            {
                FreeMem(jumptable, sizeof(struct JumpTable));
                jumptable = NULL;
            }
        }
    }

    Permit();

    /* If succeeded, you now have a jumptable which entries point to the original
     * library functions. If another task SetFunction()'ed one or more of those
     * already, that task can never go away anymore.
     */
    return (jumptable);
