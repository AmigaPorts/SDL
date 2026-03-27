/* Source: ADCD 2.1
 * Section: lib-examples-simplegtgadget-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-simplegtgadget-c.md
 */

    {
    if ( (GadToolsBase = OpenLibrary("gadtools.library", 37)) != NULL )
        {
        gadtoolsWindow();

        CloseLibrary(GadToolsBase);
        }
    CloseLibrary(IntuitionBase);
    }
