/* Source: ADCD 2.1
 * Section: devices-apps-rawtoilbm-rawtoilbm-c
 * Library: devices
 * ADCD reference: devices/devices-apps-rawtoilbm-rawtoilbm-c.md
 */

        {
        InitBitMap(ilbm.brbitmap,depth,width,height);
        for(k=0, error=0, rlen=1; k<depth && (!error) && (rlen >0); k++)
            {
            if(!(ilbm.brbitmap->Planes[k] = AllocRaster(width,height)))
