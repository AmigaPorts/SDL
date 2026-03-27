/* Source: ADCD 2.1
 * Section: devices-apps-ilbmtoraw-ilbmtoraw-c
 * Library: devices
 * ADCD reference: devices/devices-apps-ilbmtoraw-ilbmtoraw-c.md
 */

    {
    if(ilbm.ParseInfo.iff)		FreeIFF(ilbm.ParseInfo.iff);

    if(IFFParseBase)	CloseLibrary(IFFParseBase);
    if(GfxBase)		CloseLibrary(GfxBase);
    }
