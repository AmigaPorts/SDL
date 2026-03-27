/* Source: ADCD 2.1
 * Section: 3-overscan-and-the-display-clip-preset-overscan-values
 * Library: libraries
 * ADCD reference: libraries/3-overscan-and-the-display-clip-preset-overscan-values.md
 */

    {
    if ( QueryOverscan(screen_modeID, &rect, OSCAN_TEXT) )
        {
        /* if this screen's origin is up or to the left of the */
        /* view origin then move the window down and to the right */
        left = max(0, -pub_screen->LeftEdge);
        top  = max(0, -pub_screen->TopEdge);

        /* get width and height from size of display clip */
        width  = rect.MaxX - rect.MinX + 1;
        height = rect.MaxY - rect.MinY + 1;

        /* adjust height for pulled-down screen (only show visible part) */
        if (pub_screen->TopEdge > 0)
            height -= pub_screen->TopEdge;

        /* ensure that window fits on screen */
        height = min(height, pub_screen->Height);
        width  = min(width,  pub_screen->Width);

        /* make sure window is at least minimum size */
        width  = max(width,  MIN_WINDOW_WIDTH);
        height = max(height, MIN_WINDOW_HEIGHT);
        }
    }
