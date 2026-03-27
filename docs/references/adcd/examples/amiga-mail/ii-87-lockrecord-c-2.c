/* Source: ADCD 2.1
 * Section: ii-87-lockrecord-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-87-lockrecord-c.md
 */

    struct CSource *csource = &rdargs->RDA_Source;
    UBYTE *cmdlinebuffer = csource->CS_Buffer;
    LONG error;

    /* Prompt for command line */
    Write(Output(), "Cmd> ", 5);

    /* Loop forever, waiting for commands */
    for (;;)
    {
        /* Get command line */
        if ((FGets(Input(), cmdlinebuffer, 512)) != NULL)
        {

            /* Use ReadItem() to isolate actual command */
            error = ReadItem(cmdbuffer, 80, csource);

            /* Break on error */
            if (error == ITEM_ERROR)
                break;

            /* Make sure I've got something */
            else if (error != ITEM_NOTHING)
            {
                /* cmdbuffer now contains the command:
                 *
                 * KNOWN COMMANDS:
                 * QUIT
                 * LIST
                 * LOCKRECORD
                 * UNLOCKRECORD
                 */

                if ((Stricmp("QUIT", cmdbuffer)) == 0)
                    break;
                else if ((Stricmp("HELP", cmdbuffer)) == 0)
                {
                    Printf("Available commands:\n");
                    Printf("LOCKRECORD %s\n", LOCK_TEMPLATE);
                    Printf("UNLOCKRECORD %s\n", UNLOCK_TEMPLATE);
                    Printf("LIST\n");
                    Printf("QUIT\n");
                }
                else if ((Stricmp("LIST", cmdbuffer)) == 0)
                    ListRecordLocks();  /* Show all current locks */
                else
                {

                    /* Note that I've already isolated the command
                     * keyword, so I'm using Source->CS_CurChr to point
                     * after it.
                     */
                    csource->CS_Buffer += csource->CS_CurChr;
                    csource->CS_CurChr = 0;

                    if ((Stricmp("LOCKRECORD", cmdbuffer)) == 0)
                        DoLockRecord(fh, rdargs);
                    else if ((Stricmp("UNLOCKRECORD", cmdbuffer)) == 0)
                        DoUnLockRecord(fh, rdargs);
                    else
                        PrintFault(ERROR_NOT_IMPLEMENTED, cmdbuffer);

                    /* Reset CSource */
                    csource->CS_Buffer = cmdlinebuffer;
                }

                /* Output new prompt. Make sure csource is OK. */
                Write(Output(), "Cmd> ", 5);
                csource->CS_CurChr = 0;
            }
        } else
            break;
    }
