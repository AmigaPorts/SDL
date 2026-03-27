/* Source: ADCD 2.1
 * Section: devices-apps-rawtoilbm-rawtoilbm-c
 * Library: devices
 * ADCD reference: devices/devices-apps-rawtoilbm-rawtoilbm-c.md
 */

    /*
     * Allocate Bitmap and planes
     */
     extra = depth > 8 ? depth - 8 : 0;
     if(ilbm.brbitmap = AllocMem(sizeof(struct BitMap) + (extra<<2),
