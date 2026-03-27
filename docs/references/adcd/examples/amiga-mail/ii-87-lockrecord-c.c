/* Source: ADCD 2.1
 * Section: ii-87-lockrecord-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-87-lockrecord-c.md
 */

    BPTR fh;
    struct RDArgs *rdargs;
    struct CSource *csource;
    UBYTE *cmdbuffer;
    struct LockNode *lnode, *nnode;
    LONG error = RETURN_OK;

    SysBase = (*((struct Library **) 4));

    /* Fails silently if < 37 */
    if (DOSBase = (struct DosLibrary *)OpenLibrary("dos.library", 37))
    {
        UtilityBase = DOSBase->dl_UtilityBase;

        if (locklist = AllocMem(sizeof(struct LockList), MEMF_CLEAR))
        {
            NewList((struct List *)locklist);

            /* Allocate RDArgs structure to parse command lines */
            if (rdargs = AllocDosObject(DOS_RDARGS, TAG_END))
            {
                csource = &rdargs->RDA_Source;

                /* Get buffer to read command lines in */
                if (csource->CS_Buffer = AllocMem(512, MEMF_CLEAR))
                {
                    csource->CS_Length = 512;
                    csource->CS_CurChr = 0;

                    /* Buffer to isolate command keyword */
                    if (cmdbuffer = AllocMem(80, MEMF_CLEAR))
                    {

                        /* Open a testfile, create it if necessary */
                        if (fh = Open(TESTFILE, MODE_READWRITE))
                        {

                            /* Process command lines */
                            GetCommandLine(fh, rdargs, cmdbuffer);

                            /* Try to get rid of outstanding record locks */
                            lnode = locklist->lh_Head;
                            while (nnode = lnode->ln_Succ)
                            {

                                /* Try to unlock pending locks */
                                if ((UnLockRecord(fh,
                                                  lnode->ln_Offset,
                                                  lnode->ln_Length)) == DOSFALSE)
                                {
                   Printf("Error unlocking record %ld with offset %ld length %ld\n",
                                        lnode->ln_Counter,
                                        lnode->ln_Offset,
                                        lnode->ln_Length);
                                    if (IoErr())
                                        PrintFault(IoErr(), NULL);
                                }
                                /* Remove node no matter what */
                                FreeMem(lnode, sizeof(struct LockNode));
                                lnode = nnode;
                            };

                            Close(fh);
                        }
                        FreeMem(cmdbuffer, 80);
                    } else
                        SetIoErr(ERROR_NO_FREE_STORE);

                    FreeMem(csource->CS_Buffer, 512);
                } else
                    SetIoErr(ERROR_NO_FREE_STORE);

                FreeDosObject(DOS_RDARGS, rdargs);
            } else
                SetIoErr(ERROR_NO_FREE_STORE);

            FreeMem(locklist, sizeof(struct LockList));
        } else
            SetIoErr(ERROR_NO_FREE_STORE);


        error = IoErr();
        if (error)
        {
            PrintFault(IoErr(), NULL);
            error = RETURN_FAIL;
        }

        CloseLibrary((struct Library *)DOSBase);
    }
    return(error);
