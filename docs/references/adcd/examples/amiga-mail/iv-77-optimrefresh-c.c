/* Source: ADCD 2.1
 * Section: iv-77-optimrefresh-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-77-optimrefresh-c.md
 */

    /* open the system libraries we need.
     */
    IntuitionBase = OpenLibrary("intuition.library",37);
    GfxBase       = OpenLibrary("graphics.library",37);
    LayersBase    = OpenLibrary("layers.library",37);

    if (IntuitionBase && GfxBase && LayersBase)
    {
        /* get a pointer to the default public screen */
        if (screen = LockPubScreen(NULL))
        {
            /* allocate and initialize a scroller as a BOOPSI object */
            if (scroller = NewObject(NULL,"propgclass",
                  GA_RelRight,    -13,
                  GA_Top,         1+screen->WBorTop+screen->Font->ta_YSize+1,
                  GA_Width,       10,
                  GA_RelHeight,   -12-(screen->WBorTop+screen->Font->ta_YSize+1),
                  GA_RelVerify,   TRUE,
                  GA_Immediate,   TRUE,
                  GA_FollowMouse, TRUE,
                  GA_RightBorder, TRUE,
                  PGA_Borderless, TRUE,
                  PGA_Freedom,    FREEVERT,
                  PGA_Total,      1,
                  PGA_Visible,    1,
                  PGA_Top,        0,
                  PGA_NewLook,    TRUE,
                  TAG_DONE))
            {
                /* initialize data used by the backfill hook */
                refreshHook.h_Entry = ( ULONG (*)() )BackFillHook;  /* point the */
                taskBusy            = TRUE;               /* hook to our routine. */

                /* open the window */
                if (window = OpenWindowTags(NULL,
                      WA_Left,          0,
                      WA_Top,           0,
                      WA_PubScreen,     screen,
                      WA_AutoAdjust,    TRUE,
                      WA_CloseGadget,   TRUE,
                      WA_DepthGadget,   TRUE,
                      WA_DragBar,       TRUE,
                      WA_SizeGadget,    TRUE,
                      WA_SizeBRight,    TRUE,
                      WA_Title,         "Optimized Refresh Sample",
                      WA_SimpleRefresh, TRUE,
                      WA_Activate,      TRUE,
                      WA_Gadgets,       scroller,
                      WA_MinWidth,      32,
                      WA_MinHeight,     10+12+(screen->Font->ta_YSize+1),
                      WA_MaxWidth,      -1,
                      WA_MaxHeight,     -1,
                      WA_IDCMP,         IDCMP_CLOSEWINDOW | IDCMP_NEWSIZE
                                        | IDCMP_REFRESHWINDOW | IDCMP_GADGETUP
                                        | IDCMP_GADGETDOWN | IDCMP_MOUSEMOVE
                                        | IDCMP_VANILLAKEY,
                      WA_BackFill,      &refreshHook,
                      TAG_DONE))
                {
                    /* initialize our document structure */
                    InitDocument();

                    /* process user events in the window */
                    EventLoop();

                    /* free our document structure */
                    FreeDocument();

                    /* close up shop */
                    CloseWindow(window);
                }
                /* free the scroller BOOPSI object */
                DisposeObject(scroller);
            }
            /* unlock the default public screem */
            UnlockPubScreen(NULL,screen);
        }
    }

    /* close the libraries we opened */
    CloseLibrary(LayersBase);
    CloseLibrary(GfxBase);
    CloseLibrary(IntuitionBase);

    /* tell the shell everything is all right */
    return(0);
