/* Source: ADCD 2.1
 * Section: lib-examples-visiblewindow-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-visiblewindow-c.md
 */

    {
    if (IntuitionBase = OpenLibrary("intuition.library",37))
        {
        fullScreen();

        CloseLibrary(IntuitionBase);
        }
    CloseLibrary(GfxBase);
    }
