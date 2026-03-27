/* Source: ADCD 2.1
 * Section: ii-49-listdir2-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-listdir2-c.md
 */

    /* Fail silently if < 37 */
    if (DOSBase = (struct DosLibrary *) OpenLibrary("dos.library", 37))
    {
        UtilityBase = DOSBase->dl_UtilityBase;

        rargs[1] = 0L;
        rargs[2] = 0L;
        if (readargs = ReadArgs("PATTERN/A,DIRS/S,FILES/S", rargs, NULL))
        {

            pattern = (UBYTE *) rargs[0];

            /*
             * If DIRS or files not specified or both, accept
             * both files and directories
             */
            if (rargs[1] == rargs[2])
                type = 0;
            else
            {
                /* Accept only directories */
                if (rargs[1])
                    type = 1;
                /* Accept only files */
                else
                    type = -1;
            }

            parselength = StrLen(pattern) * 3;
            if (parsebuffer = AllocMem(parselength, MEMF_CLEAR))
            {

                /* Make pattern uppercase for possible character classes */
                i = 0;
                while (pattern[i])
                    pattern[i] = ToUpper(pattern[i++]);

                if ((ParsePatternNoCase(pattern, parsebuffer, parselength)) != -1)
                {

                    if (buffer = AllocMem(BUFFERSIZE, MEMF_CLEAR))
                    {

                        sourcelock =
                                ((struct Process *) FindTask(NULL))->pr_CurrentDir;

                        if (excontrol = AllocDosObject(DOS_EXALLCONTROL, NULL))
                        {

                            exallhook.h_Entry = (ULONG (*)())ExAllHook;
                            exallhook.h_Data = (VOID *) type;

                            excontrol->eac_MatchString = parsebuffer;
                            excontrol->eac_MatchFunc = &exallhook;

                            do
                            {

                                exmore = ExAll(sourcelock,
                                               buffer,
                                               BUFFERSIZE,
                                               ED_TYPE,
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

                        FreeMem(buffer, BUFFERSIZE);
                    }
                    else
                        PrintFault(ERROR_NO_FREE_STORE, NULL);
                }
                else
                    PrintFault(ERROR_BAD_TEMPLATE, NULL);
                FreeMem(parsebuffer, parselength);
            }
            else
                PrintFault(ERROR_NO_FREE_STORE, NULL);
            FreeArgs(readargs);

        }
        else
            PrintFault(IoErr(), NULL);
        CloseLibrary((struct Library *) DOSBase);
    }
