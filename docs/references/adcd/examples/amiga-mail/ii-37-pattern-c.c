/* Source: ADCD 2.1
 * Section: ii-37-pattern-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-37-pattern-c.md
 */

    /* Fail silently if < 37 */
    if (DOSBase = (struct DosLibrary *) OpenLibrary("dos.library", 37))
    {
        UtilityBase = DOSBase->dl_UtilityBase;

        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("PATTERN/A,CASE/S,STRINGS/A/M", rargs, NULL))
        {

            /* The pattern. */
            pattern = (UBYTE *) (rargs[0]);

            /*
             * Case sensitive or not? (default not. Note filename matching
             * should ALWAYS be case insensitive).
             */
            case_sensitive = (UWORD) (rargs[1]);

            /* Pointer to array of strings to match */
            strings = (UBYTE **) (rargs[2]);

            /* Get a buffer big enough to hold all the tokens */
            buffersize = StrLen(pattern) * 3;

            if (parsebuffer = AllocMem(buffersize, MEMF_CLEAR))
            {

                /* Parse the pattern, according to case sensitivity flag */
                if (case_sensitive)
                    iswild = ParsePattern(pattern, parsebuffer, buffersize);
                else
                {
                    /* make pattern uppercase in case of character classes */
                    i = 0;
                    while (pattern[i])
                        pattern[i] = ToUpper(pattern[i++]);
                    iswild = ParsePatternNoCase(pattern, parsebuffer, buffersize);
                }

                /*
                 * -1 if ParsePattern() failed, 0 for no wildcards, 1 for
                 * wildcards. For this I don't care if the supplied pattern had
                 * wildcards or not.
                 */
                if (iswild != -1)
                {
                    /* The array of strings is terminated with a NULL */
                    while (*strings)
                    {

                        /*
                         * MatchPattern() returns 1 for a successful match, 0
                         * for no match
                         */
                        if (case_sensitive)
                            success = MatchPattern(parsebuffer, *strings);
                        else
                            success = MatchPatternNoCase(parsebuffer, *strings);
                        if (success)
                        {
                            vargs[0] = (LONG) * strings;
                            VFPrintf(Output(), "Match: %s\n", vargs);
                        }
                        else
                        {
                            if (IoErr() != 0)
                            {
                                VFPrintf(Output(), "Overflow\n", NULL);
                                break;
                            }
                        }
                        strings++;
                    }
                }
                else
                    PrintFault(ERROR_BAD_TEMPLATE, pattern);
                FreeMem(parsebuffer, buffersize);
            }
            else
                PrintFault(ERROR_NO_FREE_STORE, NULL);
            FreeArgs(readargs);
        }
        else
            PrintFault(IoErr(), NULL);
        CloseLibrary((struct Library *) DOSBase);
    }
