/* Source: ADCD 2.1
 * Section: lib-examples-filehook-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-filehook-c.md
 */

    struct FileRequester *fr;

    if (AslBase = OpenLibrary("asl.library", 37L))
    {
        if (IntuitionBase = (struct IntuitionBase *)
                    OpenLibrary("intuition.library", 37L))
        {
            /* This is a V37 dos.library function that turns a pattern matching
            ** string into something the DOS pattern matching functions can
            ** understand.
            */
            ParsePattern(sourcepattern, pat, DESTPATLENGTH);

            /* open a window that gets ACTIVEWINDOW events */
            if (window = (struct Window *)OpenWindowTags(NULL,
                    WA_Title, "ASL Hook Function Example",
                    WA_IDCMP, IDCMP_ACTIVEWINDOW,
                    WA_Flags, WFLG_DEPTHGADGET,
                    TAG_END))
            {
                if (fr = AllocFileRequest())
                {
                    if (AslRequestTags(fr,
                        ASL_Dir, (ULONG)"SYS:Utilities",
                        ASL_Window, window,
                        ASL_TopEdge, 0L,
                        ASL_Height, 200L,
                        ASL_Hail, (ULONG)"Pick an icon, select save",
                        ASL_HookFunc, (ULONG)HookFunc,
                        ASL_FuncFlags, FILF_DOWILDFUNC | FILF_DOMSGFUNC | FILF_SAVE,
                        ASL_OKText, (ULONG)"Save",
                        TAG_DONE))
                    {
                        printf("PATH=%s FILE=%s\n", fr->rf_Dir, fr->rf_File);
                        printf("To combine the path and filename, copy the path\n");
                        printf("to a buffer, add the filename with Dos AddPart().\n");
                    }
                    FreeFileRequest(fr);
                }
                CloseWindow(window);
            }
            CloseLibrary(IntuitionBase);
        }
        CloseLibrary(AslBase);
    }
