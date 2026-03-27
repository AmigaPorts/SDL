/* Source: ADCD 2.1
 * Section: lib-examples-filepat-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-filepat-c.md
 */

    struct FileRequester *fr;
    struct WBArg *frargs;
    int x;

    if (AslBase = OpenLibrary("asl.library", 37L))
    {
        if (IntuitionBase = (struct IntuitionBase *)
                OpenLibrary("intuition.library", 37L))
        {
            if (screen = (struct Screen *)OpenScreenTags(NULL,
                    SA_DisplayID, HIRESLACE_KEY,
                    SA_Title, "ASL Test Screen",
                    TAG_END))
            {
                if (window = (struct Window *)OpenWindowTags(NULL,
                        WA_CustomScreen, screen,
                        WA_Title, "Demo Customscreen, File Pattern, Multi-select",
                        WA_Flags, WINDOWDEPTH | WINDOWDRAG,
                        TAG_END))
                {
                    if (fr = (struct FileRequester *)
                        AllocAslRequestTags(ASL_FileRequest,
                            ASL_Hail, (ULONG)"FilePat/MultiSelect Demo",
                            ASL_Dir,  (ULONG)"libs:",
                            ASL_File, (ULONG)"asl.library",

                            /* Initial pattern string for pattern matching */
                            ASL_Pattern, (ULONG)"~(rexx#?|math#?)",

                            /* Enable multiselection and pattern match gadget */
                            ASL_FuncFlags, FILF_MULTISELECT | FILF_PATGAD,

                            /* This requester comes up on the screen of this
                            ** window (and uses window's message port, if any).
                            */
                            ASL_Window, window,
                            TAG_DONE))
                    {
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
                                ** (see <workbench/startup.h>). Each entry in
                                ** this array corresponds to one of the files
                                ** the user selected (in alphabetical order).
                                */
                                frargs = fr->rf_ArgList;

                                /* The user multiselected, step through
                                ** the list of selected files.
                                */
                                for ( x=0;  x < fr->rf_NumArgs;  x++ )
                                    printf("Argument %d: PATH=%s FILE=%s\n",
                                        x, fr->rf_Dir, frargs[x].wa_Name);
                            }
                            else
                                /* The user didn't multiselect, use the
                                ** normal way to get the file name.
                                */
                                printf("PATH=%s FILE=%s\n", fr->rf_Dir, fr->rf_File);
                        }
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
