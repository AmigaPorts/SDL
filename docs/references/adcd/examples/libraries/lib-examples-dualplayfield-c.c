/* Source: ADCD 2.1
 * Section: lib-examples-dualplayfield-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-dualplayfield-c.md
 */

    {
    GfxBase = OpenLibrary("graphics.library", 37);
    if (GfxBase != NULL)
        {
        scr = OpenScreenTags(NULL,
                             SA_Depth,     2,
                             SA_DisplayID, HIRES_KEY,
                             SA_Title,     "Dual Playfield Test Screen",
                             TAG_END);
        if ( scr != NULL )
            {
            win = OpenWindowTags(NULL,
                                 WA_Title,        "Dual Playfield Mode",
                                 WA_IDCMP,        IDCMP_CLOSEWINDOW,
                                 WA_Width,        200,
                                 WA_Height,       100,
                                 WA_DragBar,      TRUE,
                                 WA_CloseGadget,  TRUE,
                                 WA_CustomScreen, scr,
                                 TAG_END);
            if ( win != NULL )
                {
                doDualPF(win);

                CloseWindow(win);
                }
            CloseScreen(scr);
            }
        CloseLibrary(GfxBase);
        }
    CloseLibrary(IntuitionBase);
    }
