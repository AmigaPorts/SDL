/* Source: ADCD 2.1
 * Section: lib-examples-winpubscreen-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-winpubscreen-c.md
 */

    {
    /* get a lock on the default public screen */
    if (test_screen = LockPubScreen(NULL))
            {
            /* open the window on the public screen */
            test_window = OpenWindowTags(NULL,
                    WA_Left,  10,    WA_Top,    20,
                    WA_Width, 300,   WA_Height, 100,
                    WA_DragBar,         TRUE,
                    WA_CloseGadget,     TRUE,
                    WA_SmartRefresh,    TRUE,
                    WA_NoCareRefresh,   TRUE,
                    WA_IDCMP,           IDCMP_CLOSEWINDOW,
                    WA_Title,           "Window Title",
                    WA_PubScreen,       test_screen,
                    TAG_END);

            /* Unlock the screen.  The window now acts as a lock on
            ** the screen, and we do not need the screen after the
            ** window has been closed.
            */
            UnlockPubScreen(NULL, test_screen);

            /* if we have a valid window open, run the rest of the
            ** program, then clean up when done.
            */
            if (test_window)
                {
                handle_window_events(test_window);
                CloseWindow(test_window);
                }
            }
    CloseLibrary(IntuitionBase);
    }
