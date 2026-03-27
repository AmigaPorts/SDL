/* Source: ADCD 2.1
 * Section: lib-examples-simplemenu-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-simplemenu-c.md
 */

    {
    /* Open the Intuition Library */
    IntuitionBase = OpenLibrary("intuition.library", 33);
    if (IntuitionBase)
        {
        if ( win = OpenWindow(&mynewWindow) )
            {
            left = 2;
            for (m = 0; m < NUM_MENUS; m++)
                {
                menustrip[m].LeftEdge = left;
                menustrip[m].MenuName = menutitle[m];
                menustrip[m].Width = TextLength(&win->WScreen->RastPort,
                    menutitle[m], strlen(menutitle[m])) + 8;
                left += menustrip[m].Width;
                }
            if (SetMenuStrip(win, menustrip))
                {
                handleWindow(win, menustrip);
                ClearMenuStrip(win);
                }
            CloseWindow(win);
            }
        CloseLibrary(IntuitionBase);
        }
    CloseLibrary(GfxBase);
    }
