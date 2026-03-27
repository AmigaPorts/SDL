/* Source: ADCD 2.1
 * Section: ii-37-setstar-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-37-setstar-c.md
 */

    /* Fail silently if < 37 */
    if (DOSBase = (struct DosLibrary *) OpenLibrary("dos.library", 37))
    {
        rargs[0] = 0;
        rargs[1] = 0;

        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("ON/S,OFF/S", rargs, NULL))
        {
            on = (UWORD) (rargs[0]);
            off = (UWORD) (rargs[1]);

            /*
             * The RNF_WILDSTAR bit in the rn_Flags field indicates whether the
             * '*' should be treated as wildcard or not.
             *
             * Show current setting if both ON & OFF or specified or neither.
             */
            if (on == off)
            {
                if (DOSBase->dl_Root->rn_Flags & RNF_WILDSTAR)
                    rargs[0] = (LONG) "ON";
                else
                    rargs[0] = (LONG) "OFF";
                VFPrintf(Output(), "Wildstar is %s\n", rargs);
            }
            else
            {
                if (on)
                    DOSBase->dl_Root->rn_Flags |= RNF_WILDSTAR;
                else
                    DOSBase->dl_Root->rn_Flags &= ~RNF_WILDSTAR;
            }
            FreeArgs(readargs);
        }
        else
            PrintFault(IoErr(), NULL);
        CloseLibrary((struct Library *) DOSBase);
    }
