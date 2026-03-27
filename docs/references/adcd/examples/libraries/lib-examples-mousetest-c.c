/* Source: ADCD 2.1
 * Section: lib-examples-mousetest-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-mousetest-c.md
 */

    {
    if (GfxBase = (struct GfxBase *)OpenLibrary("graphics.library", 37))
        {
        /* Lock the default public screen in order to read its DrawInfo data */
        if (scr = LockPubScreen(NULL))
            {
            if (dr_info = GetScreenDrawInfo(scr))
                {
                /* use wider of space needed for output (18 chars and spaces)
                 * or titlebar text plus room for titlebar gads (approx 18 each)
                 */
                width = max((GfxBase->DefaultFont->tf_XSize * 18),
                            (18 * 2) + TextLength(&scr->RastPort,"MouseTest",9));

                if (win = OpenWindowTags(NULL,
                            WA_Top,    20,
                            WA_Left,   100,
                            WA_InnerWidth,  width,
                            WA_Height, (2 * GfxBase->DefaultFont->tf_YSize) +
                                       scr->WBorTop + scr->Font->ta_YSize + 1 +
                                       scr->WBorBottom,
                            WA_Flags, WFLG_DEPTHGADGET | WFLG_CLOSEGADGET |
                                      WFLG_ACTIVATE    | WFLG_REPORTMOUSE |
                                      WFLG_RMBTRAP     | WFLG_DRAGBAR,
                            WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_RAWKEY |
                                      IDCMP_MOUSEMOVE   | IDCMP_MOUSEBUTTONS,
                            WA_Title, "MouseTest",
                            WA_PubScreen, scr,
                            TAG_END))
                    {
                    printf("Monitors the Mouse:\n");
                    printf("    Move Mouse, Click and DoubleClick in Window\n");

                    SetAPen(win->RPort,dr_info->dri_Pens[TEXTPEN]);
                    SetBPen(win->RPort,dr_info->dri_Pens[BACKGROUNDPEN]);
                    SetDrMd(win->RPort,JAM2);

                    process_window(win);

                    CloseWindow(win);
                    }
                FreeScreenDrawInfo(scr, dr_info);
                }
            UnlockPubScreen(NULL,scr);
            }
        CloseLibrary((struct Library *)GfxBase);
        }
    CloseLibrary(IntuitionBase);
    }
