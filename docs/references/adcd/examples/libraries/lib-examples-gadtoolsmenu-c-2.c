/* Source: ADCD 2.1
 * Section: lib-examples-gadtoolsmenu-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-gadtoolsmenu-c.md
 */

    {
    /* Open the gadtools Library */
    GadToolsBase = OpenLibrary("gadtools.library", 37);
    if (GadToolsBase != NULL)
        {
        if (NULL != (win = OpenWindowTags(NULL,
                            WA_Width,  400,       WA_Activate,    TRUE,
                            WA_Height, 100,       WA_CloseGadget, TRUE,
                            WA_Title,  "Menu Test Window",
                            WA_IDCMP,  IDCMP_CLOSEWINDOW | IDCMP_MENUPICK,
                            TAG_END)))
            {
            if (NULL != (my_VisualInfo = GetVisualInfo(win->WScreen, TAG_END)))
                {
                if (NULL != (menuStrip = CreateMenus(mynewmenu, TAG_END)))
                    {
                    if (LayoutMenus(menuStrip, my_VisualInfo, TAG_END))
                        {
                        if (SetMenuStrip(win, menuStrip))
                            {
                            handle_window_events(win,menuStrip);

                            ClearMenuStrip(win);
                            }
                        FreeMenus(menuStrip);
                        }
                    }
                FreeVisualInfo(my_VisualInfo);
                }
            CloseWindow(win);
            }
        CloseLibrary((struct Library *)GadToolsBase);
        }
    CloseLibrary((struct Library *)IntuitionBase);
    }
