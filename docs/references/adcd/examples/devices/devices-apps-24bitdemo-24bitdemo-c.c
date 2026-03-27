/* Source: ADCD 2.1
 * Section: devices-apps-24bitdemo-24bitdemo-c
 * Library: devices
 * ADCD reference: devices/devices-apps-24bitdemo-24bitdemo-c.md
 */

    width  = 320;
    height = 200;
    depth  = 24;

    /* Page width, height, and mode for saved ILBM */
    pwidth  = width  < 320 ? 320 : width;
    pheight = height < 200 ? 200 : height;
    pmode   = pwidth >= 640  ? HIRES : 0L;
    pmode  |= pheight >= 400 ? LACE  : 0L;

    plsize = RASSIZE(width,height);

    if(!DoSave)	goto nosave;

    /*
     * Allocate Bitmap and planes
     */
    extra = depth > 8 ? depth - 8 : 0;
    if(ilbm[0]->brbitmap = AllocMem(sizeof(struct BitMap) + (extra<<2),
