/* Source: ADCD 2.1
 * Section: lib-examples-clipping-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-clipping-c.md
 */

        (struct IntuitionBase *)OpenLibrary("intuition.library",37)))
    {
    if (NULL != (GfxBase = (struct GfxBase *)OpenLibrary("graphics.library",37)))
        {
        if (NULL != (LayersBase = OpenLibrary("layers.library",37)))
            {
            if (NULL != (win = OpenWindowTags(NULL,
                                WA_Width,       MY_WIN_WIDTH,
                                WA_Height,      MY_WIN_HEIGHT,
                                WA_IDCMP,       IDCMP_CLOSEWINDOW,
                                WA_CloseGadget, TRUE,
                                WA_DragBar,     TRUE,
                                WA_Activate,    TRUE,
                                TAG_END)))
                {
                clip_test(win);

                CloseWindow(win);
                }
            CloseLibrary(LayersBase);
            }
        CloseLibrary((struct Library *)GfxBase);
        }
    CloseLibrary((struct Library *)IntuitionBase);
    }
