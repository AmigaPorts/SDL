/* Source: ADCD 2.1
 * Section: devices-apps-ilbmtoc-ilbmtoc-c
 * Library: devices
 * ADCD reference: devices/devices-apps-ilbmtoc-ilbmtoc-c.md
 */

    {
    if(ilbm.ParseInfo.iff)		FreeIFF(ilbm.ParseInfo.iff);

    if(IFFParseBase)	CloseLibrary(IFFParseBase);
    if(GfxBase)		CloseLibrary(GfxBase);
    }
