/* Source: ADCD 2.1
 * Section: ii-49-listdir-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-listdir-c.md
 */

    /* Fail silently if < 37 */
    if (DOSBase = (struct DosLibrary *) OpenLibrary("dos.library", 37))
    {

        if (readargs = ReadArgs("DIRECTORY/A", rargs, NULL))
        {

            source = (UBYTE *) rargs[0];

            if (buffer = AllocMem(BUFFERSIZE, MEMF_CLEAR))
            {

                if (sourcelock = Lock(source, SHARED_LOCK))
                {
                    if (excontrol = AllocDosObject(DOS_EXALLCONTROL, NULL))
                    {
                        excontrol->eac_LastKey = 0;

                        do
                        {

                            exmore = ExAll(sourcelock,
                                           buffer,
                                           BUFFERSIZE,
                                           ED_NAME,
                                           excontrol);
                            error = IoErr();
                            if ((exmore == NULL &&
                                (error != ERROR_NO_MORE_ENTRIES)))
                                break;

                            if (excontrol->eac_Entries == 0)
                                continue;

                            ead = buffer;
                            do
                            {

                                /* Check for CTRL-C */
                                if (SetSignal(0L, SIGBREAKF_CTRL_C) &
                                        SIGBREAKF_CTRL_C)
                                {
                                    error = ERROR_BREAK;
                                    exmore = FALSE;
                                    break;
                                }

                                rargs[0] = (LONG) ead->ed_Name;
                                VFPrintf(Output(), "%s\n", rargs);

                                ead = ead->ed_Next;
                            } while (ead);
                        } while (exmore);

                        if (error != ERROR_NO_MORE_ENTRIES)
                            PrintFault(error, NULL);

                        FreeDosObject(DOS_EXALLCONTROL, excontrol);
                    }
                    else
                        PrintFault(ERROR_NO_FREE_STORE, NULL);

                    UnLock(sourcelock);
                }
                else
                    PrintFault(IoErr(), source);

                FreeMem(buffer, BUFFERSIZE);
            }
            else
                PrintFault(ERROR_NO_FREE_STORE, NULL);
            FreeArgs(readargs);

        }
        else
            PrintFault(IoErr(), NULL);
        CloseLibrary((struct Library *) DOSBase);
    }
