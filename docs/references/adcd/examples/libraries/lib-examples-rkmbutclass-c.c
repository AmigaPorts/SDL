/* Source: ADCD 2.1
 * Section: lib-examples-rkmbutclass-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rkmbutclass-c.md
 */

    if (IntuitionBase = OpenLibrary("intuition.library", 37L))
    {
        if (UtilityBase = OpenLibrary("utility.library", 37L))
        {
            if (GfxBase = OpenLibrary("graphics.library", 37L))
            {
                if (w = OpenWindowTags(NULL,
                    WA_Flags,       WFLG_DEPTHGADGET | WFLG_DRAGBAR |
                                        WFLG_CLOSEGADGET | WFLG_SIZEGADGET,
                    WA_IDCMP,       IDCMP_CLOSEWINDOW,
                    WA_Width,           640,
                    WA_Height,          200,
                    TAG_END))
                {
                    WindowLimits(w, 450, 200, 640, 200);

                    if (rkmbutcl = initRKMButGadClass())
                    {
                        if (integer = (struct Gadget *)NewObject(NULL,
                                       "strgclass",
                                       GA_ID,            1L,
                                       GA_Top,           (w->BorderTop) + 5L,
                                       GA_Left,          (w->BorderLeft) + 5L,
                                       GA_Width,         INTWIDTH,
                                       GA_Height,        INTHEIGHT,
                                       STRINGA_LongVal,  0L,
                                       STRINGA_MaxChars, 5L,
                                       TAG_END))
                        {
                            if (but = (struct Gadget *)NewObject(rkmbutcl,
                                       NULL,
                                       GA_ID,       2L,
                                       GA_Top,      (w->BorderTop) + 5L,
                                       GA_Left,     integer->LeftEdge +
                                                        integer->Width + 5L,
                                       GA_Width,    40L,
                                       GA_Height,   INTHEIGHT,
                                       GA_Previous, integer,
                                       ICA_MAP,     pulse2int,
                                       ICA_TARGET,  integer,
                                       TAG_END))
                            {
                                AddGList(w, integer, -1, -1, NULL);
                                RefreshGList(integer, w, NULL, -1);

                                SetWindowTitles(w,
                                    "<-- Click to resize gadget Height",
                                    NULL);
                                MainLoop(TAG_DONE, 0L);

                                SetWindowTitles(w,
                                    "<-- Click to resize gadget Width",
                                    NULL);
                                MainLoop(GA_Height, 100L);

                                SetWindowTitles(w,
                                    "<-- Click to resize gadget Y position",
                                    NULL);
                                MainLoop(GA_Width, 100L);

                                SetWindowTitles(w,
                                    "<-- Click to resize gadget X position",
                                    NULL);
                                MainLoop(GA_Top, but->TopEdge + 20);

                                SetWindowTitles(w,
                                    "<-- Click to quit", NULL);
                                MainLoop(GA_Left, but->LeftEdge + 20);

                                RemoveGList(w, integer, -1);
                                DisposeObject(but);
                            }
                            DisposeObject(integer);
                        }
                        freeRKMButGadClass(rkmbutcl);
                    }
                    CloseWindow(w);
                }
                CloseLibrary(GfxBase);
            }
            CloseLibrary(UtilityBase);
        }
        CloseLibrary(IntuitionBase);
    }
