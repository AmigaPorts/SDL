/* Source: ADCD 2.1
 * Section: lib-examples-gadtoolsgadgets-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-gadtoolsgadgets-c.md
 */

    {
    if (NULL == (GfxBase = OpenLibrary("graphics.library", 37)))
        errorMessage( "Requires V37 graphics.library");
    else
        {
        if (NULL == (GadToolsBase = OpenLibrary("gadtools.library", 37)))
            errorMessage( "Requires V37 gadtools.library");
        else
            {
            gadtoolsWindow();

            CloseLibrary(GadToolsBase);
            }
        CloseLibrary(GfxBase);
        }
    CloseLibrary(IntuitionBase);
    }
