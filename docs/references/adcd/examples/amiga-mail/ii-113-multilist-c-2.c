/* Source: ADCD 2.1
 * Section: ii-113-multilist-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-113-multilist-c.md
 */

    struct ExAllControl  *myeac;
    struct ExAllData     *myead;
    APTR                 buffer;
    BOOL                 done;
    struct FileInfoBlock *myfib;

    if (myfib = AllocDosObject(DOS_FIB, NULL))
    {
        if (Examine(lock, myfib) == DOSTRUE)
        {
            if (myfib->fib_DirEntryType > 0)
            {
                if (buffer = AllocVec(BUFSIZE, MEMF_PUBLIC))
                {
                    if (myeac = AllocDosObject(DOS_EXALLCONTROL, NULL))
                    {
                        myeac->eac_LastKey = 0;

                        do
                        {
                            done = ExAll(lock, buffer, BUFSIZE, ED_NAME, myeac);
                            myead = buffer;
                            while (myead)
                            {
                                printf("%s\n", myead->ed_Name);
                                myead = myead->ed_Next;
                            }
                        } while (done != 0);
                        FreeDosObject(DOS_EXALLCONTROL, myeac);
                    }
                    FreeVec(buffer);
                }
            }
            else printf("%s\n", myfib->fib_FileName);
        }
        FreeDosObject(DOS_FIB, myfib);
    }
    return TRUE;
