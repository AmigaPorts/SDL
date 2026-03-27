/* Source: ADCD 2.1
 * Section: visitor-windows
 * Library: amiga-mail
 * ADCD reference: amiga-mail/visitor-windows.md
 */

    struct Screen *screen;
    struct Window *window;
    UBYTE namebuffer[MAXPUBSCREENNAME];

    if (!(screen = LockPubScreen("CATScreen"))) {
        /* Can't lock CATScreen, fall back on default */
        /* The method used in this example to fall back on the default
           screen is not necessary and is provided only to illustrate
           the usage of GetDefaultPubScreen().
        */
        GetDefaultPubScreen(namebuffer);
        /* Lock it, so it can't go away. */
        /* If in this split second another screen is made the default
           and this one closes, screen would become NULL and the window
           will open on the default public screen anyway.
        */
        screen = LockPubScreen(namebuffer);
    }
    if (window = OpenWindowTags(NULL,
                    WA_Left, 0, WA_Width, screen->Width,
                    WA_Top, screen->BarHeight,
                    WA_Height, screen->Height - screen->BarHeight,
                    WA_PubScreen, screen,
                    WA_Flags,
                    WINDOWDRAG|WINDOWDEPTH|WINDOWCLOSE|ACTIVATE|
                              SIMPLE_REFRESH|NOCAREREFRESH,
                    WA_Title, "AmigaMail Visitor window", TAG_END)) {
        /* Don't need the lock anymore. */
        UnlockPubScreen(NULL, screen);
                        .
                        .
                        .
        CloseWindow(window);
    } else UnlockPubScreen(NULL, screen);   /* OpenWindow failed for
                                           some other reason */
