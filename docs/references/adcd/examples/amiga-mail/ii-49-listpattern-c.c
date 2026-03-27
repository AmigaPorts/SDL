/* Source: ADCD 2.1
 * Section: ii-49-listpattern-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-listpattern-c.md
 */

    /* Fail silently if < 37 */
    if (DOSBase = (struct DosLibrary *) OpenLibrary("dos.library", 37))
    {
        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("PATTERN/A", rargs, NULL))
        {
            pattern = (UBYTE *) rargs[0];
            if (anchorpath = AllocMem(sizeof(struct AnchorPath) + 512, MEMF_CLEAR))
            {
                anchorpath->ap_Strlen = 512;
                anchorpath->ap_BreakBits = SIGBREAKF_CTRL_C;

                if ((error = MatchFirst(pattern, anchorpath)) == 0)
                {
                    do
                    {
                        vargs[0] = (LONG) anchorpath->ap_Buf;
                        VFPrintf(Output(), "%s\n", vargs);
                    } while ((error = MatchNext(anchorpath)) == 0);
                }

                MatchEnd(anchorpath);

                if (error != ERROR_NO_MORE_ENTRIES)
                    PrintFault(error, NULL);

                FreeMem(anchorpath, sizeof(struct AnchorPath) + 512);
            }
            FreeArgs(readargs);
        }
        else
            PrintFault(IoErr(), NULL);
        CloseLibrary((struct Library *) DOSBase);
    }
