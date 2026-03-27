/* Source: ADCD 2.1
 * Section: lib-examples-visiblewindow-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-visiblewindow-c.md
 */

    {
    /* this technique returns the text overscan rectangle of the screen that we
    ** are opening on.  If you really need the actual value set into the display
    ** clip of the screen, use the VideoControl() command of the graphics library
    ** to return a copy of the ViewPortExtra structure.  See the Graphics
    ** library chapter and Autodocs for more details.
    **
    ** GetVPModeID() is a graphics call...
    */

    screen_modeID = GetVPModeID(&pub_screen->ViewPort);
    if(screen_modeID != INVALID_ID)
        {
        if (QueryOverscan(screen_modeID, &rect, OSCAN_TEXT))
            {
            /* make sure window coordinates are positive or zero */
            left = max(0, -pub_screen->LeftEdge);
            top  = max(0, -pub_screen->TopEdge);

            /* get width and height from size of display clip */
            width  = rect.MaxX - rect.MinX + 1;
            height = rect.MaxY - rect.MinY + 1;

            /* adjust height for pulled-down screen (only show visible part) */
            if (pub_screen->TopEdge > 0)
                height -= pub_screen->TopEdge;

            /* insure that window fits on screen */
            height = min(height, pub_screen->Height);
            width  = min(width,  pub_screen->Width);

            /* make sure window is at least minimum size */
            width  = max(width,  MIN_WINDOW_WIDTH);
            height = max(height, MIN_WINDOW_HEIGHT);
            }
        }

    /* open the window on the public screen */
    test_window = OpenWindowTags(NULL,
            WA_Left, left,            WA_Width,  width,
            WA_Top,  top,             WA_Height, height,
            WA_CloseGadget, TRUE,
            WA_IDCMP,       IDCMP_CLOSEWINDOW,
            WA_PubScreen,   pub_screen,
            TAG_END);

    /* unlock the screen.  The window now acts as a lock on the screen,
    ** and we do not need the screen after the window has been closed.
    */
    UnlockPubScreen(NULL, pub_screen);

    /* if we have a valid window open, run the rest of the
    ** program, then clean up when done.
    */
    if (test_window)
        {
        handle_window_events(test_window);
        CloseWindow(test_window);
        }
    }
