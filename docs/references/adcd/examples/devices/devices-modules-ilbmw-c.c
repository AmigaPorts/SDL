/* Source: ADCD 2.1
 * Section: devices-modules-ilbmw-c
 * Library: devices
 * ADCD reference: devices/devices-modules-ilbmw-c.md
 */

    {
    extern struct Library *GfxBase;
    struct DisplayInfo DI;

    WORD rowBytes = bitmap->BytesPerRow;

    D(bug("In InitBMHD\n"));

    bmhd->w = width;
    bmhd->h = height;
    bmhd->x = bmhd->y = 0;	/* Default position is (0,0).*/
    bmhd->nPlanes = bitmap->Depth;
    bmhd->masking = masking;
    bmhd->compression = compression;
    bmhd->reserved1 = 0;
    bmhd->transparentColor = transparentColor;
    bmhd->pageWidth = pageWidth;
    bmhd->pageHeight = pageHeight;

    bmhd->xAspect = 0;	/* So we can tell when we've got it */
    if(GfxBase->lib_Version >=36)
