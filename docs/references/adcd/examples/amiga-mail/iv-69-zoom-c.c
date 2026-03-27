/* Source: ADCD 2.1
 * Section: iv-69-zoom-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-69-zoom-c.md
 */

    struct IBox     ibox;    /* The structure we'll use to specify the zoom'ed
                              * dimension. */
    struct Screen  *wbscreen;
    struct Window  *window;
    struct Message *msg;     /* Make this an IntuiMessage when you want to use
                              * it */


    if (IntuitionBase = OpenLibrary("intuition.library", 37))
    {

        /* Lock workbench screen so we can watch it closely */
        if (wbscreen = LockPubScreen("Workbench"))
        {

            /*
             * Generate a nice position for the zoom'ed window. Note that this
             * specifies the INITIAL position of the window. Since we don't
             * have a size gadget, the user can't change the height and width,
             * but the offset is changed as the window is dragged.
             */
            ibox.Left = wbscreen->Width - 180;   /* far right corner */
            ibox.Top = wbscreen->BarHeight + 1;  /* Just below screen bar */
            ibox.Width = 180;
            /* ght of the window topborder */
            ibox.Height = wbscreen->WBorTop + wbscreen->Font->ta_YSize + 1;

            /* open a window with tags */
            if (window = OpenWindowTags(NULL,    /* no NewWindow structure,
                                                  * tags only */
                                        WA_Left, 0,     /* Open at far left
                                                         * corner */
                                        WA_Top, wbscreen->BarHeight + 1,
                                        WA_Width, 200,
                                        WA_Height, 100,
                                        WA_Title, (LONG) "A simple window",
                WA_Flags, WFLG_DRAGBAR | WFLG_DEPTHGADGET | WFLG_CLOSEGADGET |
                     WFLG_ACTIVATE | WFLG_SIMPLE_REFRESH | WFLG_NOCAREREFRESH,

                                        /* Only interested in closewindow      */
                                        WA_IDCMP, IDCMP_CLOSEWINDOW,

                                        /* pass the alternate zoom dimension   */
                                        WA_Zoom, (LONG) & ibox,

                                        TAG_DONE))
            {

                /* And just wait for windowclose */
                WaitPort(window->UserPort);
                /* clear the message port */
                while (msg = GetMsg(window->UserPort))
                    ReplyMsg(msg);

                CloseWindow(window);
            }
            UnlockPubScreen(NULL, wbscreen);
        }
        CloseLibrary(IntuitionBase);
    }
