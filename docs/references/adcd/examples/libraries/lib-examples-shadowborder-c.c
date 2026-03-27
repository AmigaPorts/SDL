/* Source: ADCD 2.1
 * Section: lib-examples-shadowborder-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-shadowborder-c.md
 */

    {
    if (screen = LockPubScreen(NULL))
        {
        if (drawinfo = GetScreenDrawInfo(screen))
            {
            /* Get a copy of the correct pens for the screen.
            ** This is very important in case the user or the
            ** application has the pens set in a unusual way.
            */
            mySHADOWPEN = drawinfo->dri_Pens[SHADOWPEN];
            mySHINEPEN  = drawinfo->dri_Pens[SHINEPEN];

            FreeScreenDrawInfo(screen,drawinfo);
            }
        UnlockPubScreen(NULL,screen);
        }

    /* open a simple window on the workbench screen for displaying
    ** a border.  An application would probably never use such a
    ** window, but it is useful for demonstrating graphics...
    */
    if (win = OpenWindowTags(NULL,
                        WA_PubScreen,  screen,
                        WA_RMBTrap,      TRUE,
                        TAG_END))
        {
        /* set information specific to the shadow component of the border */
        shadowBorder.LeftEdge   = MYBORDER_LEFT + 1;
        shadowBorder.TopEdge    = MYBORDER_TOP + 1;
        shadowBorder.FrontPen   = mySHADOWPEN;
        shadowBorder.NextBorder = &shineBorder;

        /* set information specific to the shine component of the border */
        shineBorder.LeftEdge    = MYBORDER_LEFT;
        shineBorder.TopEdge     = MYBORDER_TOP;
        shineBorder.FrontPen    = mySHINEPEN;
        shineBorder.NextBorder  = NULL;

        /* the following attributes are the same for both borders. */
        shadowBorder.BackPen    = shineBorder.BackPen   = 0;
        shadowBorder.DrawMode   = shineBorder.DrawMode  = JAM1;
        shadowBorder.Count      = shineBorder.Count     = 5;
        shadowBorder.XY         = shineBorder.XY        = myBorderData;

        /* Draw the border at 10,10 */
        DrawBorder(win->RPort,&shadowBorder,10,10);

        /* Draw the border again at 100,10 */
        DrawBorder(win->RPort,&shadowBorder,100,10);

        /* Wait a bit, then quit.
        ** In a real application, this would be an event loop, like the
        ** one described in the Intuition Input and Output Methods chapter.
        */
        Delay(200);

        CloseWindow(win);
        }
    CloseLibrary(IntuitionBase);
    }
