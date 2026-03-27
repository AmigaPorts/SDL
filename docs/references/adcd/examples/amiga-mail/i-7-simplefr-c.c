/* Source: ADCD 2.1
 * Section: i-7-simplefr-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/i-7-simplefr-c.md
 */

    struct FileRequester *fr;

    if (AslBase = OpenLibrary("asl.library", 36L))
    {
        if (fr = (struct FileRequester *)
            AllocAslRequest(ASL_FileRequest, frtags))
        {
            /* Application body, blah, blah,... */

            /* Application need a requester */
            if (AslRequest(fr, 0L))
                printf("file choice = %s%s\n", fr->rf_Dir, fr->rf_File);
            else
                printf("User Cancelled\n");

            /* More application body, blah, blah... */
        }

        /* Don't need any more requesters, better
        ** give the requester structure back.
        */
        FreeAslRequest(fr);
    }
    CloseLibrary(AslBase);
