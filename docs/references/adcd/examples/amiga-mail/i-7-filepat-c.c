/* Source: ADCD 2.1
 * Section: i-7-filepat-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/i-7-filepat-c.md
 */

    struct FileRequester *fr;

    if (AslBase = OpenLibrary("asl.library", 36L))
    {
        if (IntuitionBase = (struct IntuitionBase *)
                OpenLibrary("intuition.library", 36L))
        {
            if (screen = (struct Screen *)OpenScreenTags(NULL,
                    SA_DisplayID, HIRESLACE_KEY,
                    SA_Title, "ASL Test Screen",
                    TAG_END))
            {
                if (window = (struct Window *)OpenWindowTags(NULL,
                        WA_CustomScreen, screen,
                        WA_Title, "ASL Test Window",
                        WA_Flags, WINDOWDEPTH | WINDOWDRAG,
                        TAG_END))
                {
                    if (fr = (struct FileRequester *)
                        AllocAslRequestTags(ASL_FileRequest,
                            ASL_Hail, (ULONG)"RKM File Requester, FilePat",
                            ASL_Dir,  (ULONG)"libs:",
                            ASL_File, (ULONG)"asl.library",

                            /* The initial pattern string for the
                            ** pattern gadget.
                            */
                            ASL_Pattern, (ULONG)"~(rexx#?|math#?)",

                            /* turn on multiselection and the pattern
                            ** matching gadget.
                            */
                            ASL_FuncFlags, FILF_MULTISELECT | FILF_PATGAD,

                            /* This requester is associated with this
                            ** window (and uses its message port).
                            */
                            ASL_Window, window,
                            TAG_DONE))
                    {
                        /* Application code body...*/

                        /* Put up file requester */
                        if (AslRequest(fr, 0L))
                        {
                            /* If the file requester's rf_NumArgs field
                            ** is not zero, the user multiselected. The
                            ** number of files is stored in rf_NumArgs.
                            */
                            if (fr->rf_NumArgs)
                            {
                                /* rf_ArgList is an array of WBArg structures
                                ** (defined in <workbench/startup.h>).
                                ** Each entry in the WBArg array corresponds
                                ** to one of the files the user selected
                                ** (the entries are in alphabetical order).
                                */
                                wbargs = fr->rf_ArgList;

                                /* The user multiselected, step through
                                ** the list of selected files.
                                */
                                for ( x=0;  x < fr->rf_NumArgs;  x++ )
                                    printf("Argument %d - %s%s\n", x,
                                        fr->rf_Dir, wbargs[x].wa_Name);
                            }
                            else
                                /* The user didn't multiselect, use the
                                ** normal way to get the file name.
                                */
                                printf("%s%s\n", fr->rf_Dir, fr->rf_File);
                        }
                        /* More application code body... */

                        /* Done with the FileRequester, better return it */
                        FreeAslRequest(fr);
                    }
                    CloseWindow(window);
                }
                CloseScreen(screen);
            }
            CloseLibrary(IntuitionBase);
        }
        CloseLibrary(AslBase);
    }
