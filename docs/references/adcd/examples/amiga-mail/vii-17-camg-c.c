/* Source: ADCD 2.1
 * Section: vii-17-camg-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vii-17-camg-c.md
 */

    struct Screen  *screen;

    /*
     * Test the routines by passing various bad or possibly unavailable CAMG
     * modeid values
     */
    if (GfxBase = OpenLibrary("graphics.library", 0))
    {
        if (IntuitionBase = OpenLibrary("intuition.library", 0))
        {
            /* Junk CAMG    */
            if (screen = openidscreen(640, 400, 3, 0x12340000))
                CloseScreen(screen);

            /* Bad bits like VP_HIDE and SPRITES */
            if (screen = openidscreen(320, 400, 3, 0x00006004))
                CloseScreen(screen);

            /* Extended bit set but not a valid modeid */
            if (screen = openidscreen(320, 400, 3, 0x00009004))
                CloseScreen(screen);

            /* An ECS Mode - demonstrates modefallback if not available */
            if (screen = openidscreen(640, 400, 2, 0x00039025))
                CloseScreen(screen);

            CloseLibrary(IntuitionBase);
        }
        CloseLibrary(GfxBase);
    }
