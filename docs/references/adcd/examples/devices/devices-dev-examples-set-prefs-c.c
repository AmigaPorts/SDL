/* Source: ADCD 2.1
 * Section: devices-dev-examples-set-prefs-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-set-prefs-c.md
 */

    {
    if (GfxBase = OpenLibrary("graphics.library",0L))
        {
        DoPrinter();
        CloseLibrary(GfxBase);
        }

    CloseLibrary(IntuitionBase);
    }
