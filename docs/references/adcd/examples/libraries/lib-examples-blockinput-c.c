/* Source: ADCD 2.1
 * Section: lib-examples-blockinput-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-blockinput-c.md
 */

    {
    if (win = OpenWindowTags(NULL,
                        WA_IDCMP, IDCMP_CLOSEWINDOW|IDCMP_INTUITICKS,
                        WA_Activate, TRUE,
                        WA_Width,  320,
                        WA_Height, 100,
                        WA_CloseGadget, TRUE,
                        WA_DragBar, TRUE,
                        WA_DepthGadget, TRUE,
                        WA_SizeGadget, TRUE,
                        WA_MaxWidth, ~0,
                        WA_MaxHeight, ~0,
                        TAG_END))
        {
        processIDCMP(win);
        CloseWindow(win);
        }
    CloseLibrary(IntuitionBase);
    }
