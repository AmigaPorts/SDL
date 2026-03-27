/* Source: ADCD 2.1
 * Section: devices-modules-ilbmr-c
 * Library: devices
 * ADCD reference: devices/devices-modules-ilbmr-c.md
 */

                /* check for bogus CAMG like DPaintII brushes
                 * with junk in upper word and extended bit
                 * not set in lower word.
                 */
                if((modeid & 0xFFFF0000)&&(!(modeid & 0x00001000))) sp=NULL;
                }

        if(!sp) {
                /*
                 * No CAMG (or bad CAMG) present; use computed modes.
                 */
                if (wide >= 640)        modeid = HIRES;
                if (high >= 400)        modeid |= LACE;
                if (deep == 6)
                        {
                        modeid |= ilbm->EHB ? EXTRA_HALFBRITE : HAM;
                        }
