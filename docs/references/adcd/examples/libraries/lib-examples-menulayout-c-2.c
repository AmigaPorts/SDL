/* Source: ADCD 2.1
 * Section: lib-examples-menulayout-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-menulayout-c.md
 */

    {
    if (drawinfo = GetScreenDrawInfo(screen))
        {
        /* get the colors for the window text */
        WinText[0].FrontPen = WinText[1].FrontPen = drawinfo->dri_Pens[TEXTPEN];
        WinText[0].BackPen  = WinText[1].BackPen  = drawinfo->dri_Pens[BACKGROUNDPEN];

        /* use the screen's font for the text */
        WinText[0].ITextFont = WinText[1].ITextFont = screen->Font;

        /* calculate window size */
        win_width  = 100 + IntuiTextLength(&(WinText[0]));
        alt_width  = 100 + IntuiTextLength(&(WinText[1]));
        if (win_width < alt_width)
            win_width  = alt_width;
        win_height = 1 + screen->WBorTop + screen->WBorBottom +
                     (screen->Font->ta_YSize * 5);

        /* calculate the correct positions for the text in the window */
        WinText[0].LeftEdge = (win_width - IntuiTextLength(&(WinText[0]))) >> 1;
        WinText[0].TopEdge  = 1 + screen->WBorTop + (2 * screen->Font->ta_YSize);
        WinText[1].LeftEdge = (win_width - IntuiTextLength(&(WinText[1]))) >> 1;
        WinText[1].TopEdge  = WinText[0].TopEdge + screen->Font->ta_YSize;

        /* Open the window */
        window = OpenWindowTags(NULL,
            WA_PubScreen, screen,
            WA_IDCMP,     IDCMP_MENUPICK | IDCMP_CLOSEWINDOW | IDCMP_MENUHELP,
            WA_Flags,     WFLG_DRAGBAR | WFLG_DEPTHGADGET | WFLG_CLOSEGADGET |
                              WFLG_ACTIVATE | WFLG_NOCAREREFRESH,
            WA_Left,      10,             WA_Top,       screen->BarHeight + 1,
            WA_Width,     win_width,      WA_Height,    win_height,
            WA_Title,     "Menu Example", WA_MenuHelp,  TRUE,
            TAG_END);



        if (window)
            {
            returnValue = RETURN_OK;  /* program initialized ok */

            /* Give a brief explanation of the program */
            PrintIText(window->RPort,&WinText[1],0,0);

            /* Adjust the menu to conform to the font (TextAttr) */
            adjustMenus(FirstMenu, window->WScreen->Font);

            /* attach the menu to the window */
            SetMenuStrip(window, FirstMenu);

            /* Set up the signals that you want to hear about ... */
            signalmask = 1L << window->UserPort->mp_SigBit;

            /* And wait to hear from your signals */
            while (!done)
                {
                signals = Wait(signalmask);
                if (signals & signalmask) done = handleIDCMP(window);
                };

            /* clean up everything used here */
            ClearMenuStrip(window);
            CloseWindow(window);
            }
        FreeScreenDrawInfo(screen,drawinfo);
        }
    UnlockPubScreen(NULL,screen);
    }
