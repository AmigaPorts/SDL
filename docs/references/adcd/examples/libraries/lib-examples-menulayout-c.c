/* Source: ADCD 2.1
 * Section: lib-examples-menulayout-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-menulayout-c.md
 */

    {
    /* Open the Graphics Library */
    GfxBase = (struct GfxBase *)OpenLibrary("graphics.library", 33);
    if (GfxBase)
        {
        returnValue = doWindow();

        CloseLibrary(GfxBase);
        }
    CloseLibrary(IntuitionBase);
    }
