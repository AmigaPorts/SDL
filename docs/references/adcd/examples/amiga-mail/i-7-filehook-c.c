/* Source: ADCD 2.1
 * Section: i-7-filehook-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/i-7-filehook-c.md
 */

    struct FileRequester *fr;

    /* This is a dos.library function that turns a pattern matching
    ** string into something the DOS pattern matching functions
    ** can understand.
    */
    ParsePattern(sourcepattern, pat, DESTPATLENGTH);

    if (AslBase = OpenLibrary("asl.library", 36L))
    {
        if (IntuitionBase = (struct IntuitionBase *)
                    OpenLibrary("intuition.library", 36L))
        {
            /* open a window that gets ACTIVEWINDOW events */
            if (window = (struct Window *)OpenWindowTags(NULL,
                    WA_Title, "ASL Hook Function Example",
                    WA_IDCMP, IDCMP_ACTIVEWINDOW,
                    WA_Flags, WINDOWDEPTH,
                    TAG_END))
            {
                if (fr = AllocFileRequest())
                {
                    /* application body here... */


                    if (AslRequestTags(fr,
                        ASL_Window, window,
                        ASL_TopEdge, 0L,
                        ASL_Height, 200L,
                        ASL_Hail, (ULONG)"Pick an icon to save",
                        ASL_HookFunc, (ULONG)HookFunc,
                        ASL_FuncFlags, FILF_DOWILDFUNC | FILF_DOMSGFUNC | FILF_SAVE,
                        ASL_OKText, (ULONG)"Save",
                        TAG_DONE))
                    {
                        printf("You picked %s%s\n", fr->rf_Dir, fr->rf_File);
                    }

                    /* more application body here */

                    FreeFileRequest(fr);
                }
                CloseWindow(window);
            }
            CloseLibrary(IntuitionBase);
        }
        CloseLibrary(AslBase);
    }
