/* Source: ADCD 2.1
 * Section: lib-examples-lines-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-lines-c.md
 */

    {
    if (GfxBase = OpenLibrary("graphics.library",33L))
        {
        if (LayersBase = OpenLibrary("layers.library",33L))
            {
            /* LockPubScreen()/UnlockPubScreen is only available under V36
            ** and later... Use GetScreenData() under V34 systems to get a
            ** copy of the screen structure...
            */
            if (NULL != (myscreen = LockPubScreen(NULL)))
                {
                superWindow(myscreen);
                UnlockPubScreen(NULL,myscreen);
                }
            CloseLibrary(LayersBase);
            }
        CloseLibrary(GfxBase);
        }
    CloseLibrary(IntuitionBase);
    }
