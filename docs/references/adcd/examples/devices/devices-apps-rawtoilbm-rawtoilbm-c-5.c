/* Source: ADCD 2.1
 * Section: devices-apps-rawtoilbm-rawtoilbm-c
 * Library: devices
 * ADCD reference: devices/devices-apps-rawtoilbm-rawtoilbm-c.md
 */

    {
    if(ilbm.ParseInfo.iff)	FreeIFF(ilbm.ParseInfo.iff);

    if(GfxBase)		CloseLibrary(GfxBase);
    if(IntuitionBase)	CloseLibrary(IntuitionBase);
    if(IFFParseBase)	CloseLibrary(IFFParseBase);
    }
