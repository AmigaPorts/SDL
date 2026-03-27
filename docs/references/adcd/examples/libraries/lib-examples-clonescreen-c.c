/* Source: ADCD 2.1
 * Section: lib-examples-clonescreen-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-clonescreen-c.md
 */

    {
    /* Require version 37 of Intuition. */
    if (IntuitionBase->lib_Version >= 37)
        {
        /* Note the two methods of getting the library version
        ** that you really want.
        */
        GfxBase = (struct GfxBase *)OpenLibrary("graphics.library",37);
        if (GfxBase != NULL)
            {
            cloneScreen(pub_screen_name);

            CloseLibrary((struct Library *)GfxBase);
            }
        }
    CloseLibrary(IntuitionBase);
    }
