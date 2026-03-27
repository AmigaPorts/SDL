/* Source: ADCD 2.1
 * Section: iv-41-usemyic-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-41-usemyic-c.md
 */

    Class          *cl;
    struct Image   *im;
    struct Window  *win;
    struct RastPort *rp;
    UWORD           top, left, height;

    /* Make sure we're at least using Version 2.0 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36))
    {
        GfxBase = OpenLibrary("graphics.library", 36);
        UtilityBase = OpenLibrary("utility.library", 36);

        /* Open a window, without system gadgets or IDCMP events */
        if (win = OpenWindowTags(NULL,
                                 WA_Left, 10,
                                 WA_Top, 10,
                                 WA_Width, 320,
                                 WA_Height, 100,
                                 TAG_DONE))
        {
            /* Cache the pointer to the RastPort */
            rp = win->RPort;

            /* Cache the upper-left coordinates of the window */
            top = win->BorderTop + INTERHEIGHT;
            left = win->BorderRight + INTERWIDTH;

            /* Cache the height of the font */
            height = rp->TxHeight + INTERHEIGHT;

            /* Initialize the custom image class. */
            if (cl = initmyTextLabelClass())
            {
                /* Create a new image structure, using the given string. */
                if (im = NewObject(cl, NULL,
                                   IA_Data, (ULONG) "Line _1",
                                   TAG_DONE))
                {
                    /* Paint using the provided text string. */
                    DrawImageState(rp, im, left, top,
                                   IDS_NORMAL, NULL);

                    /* Replace the text string, and paint it. */
                    im->ImageData = (USHORT *) "Line _2";
                    DrawImageState(rp, im, left, top + height,
                                   IDS_NORMAL, NULL);

                    /* Replace the text string, and paint it. */
                    im->ImageData = (USHORT *) "Line _3";
                    DrawImageState(rp, im, left, top + (height * 2),
                                   IDS_NORMAL, NULL);

                    /* Free the image. */
                    DisposeObject(im);
                }

                /* Free the image class. */
                freemyTextLabelClass(cl);
            }

            Delay(250);
            CloseWindow(win);
        }

        CloseLibrary(UtilityBase);
        CloseLibrary(GfxBase);
        CloseLibrary(IntuitionBase);
    }
