/* Source: ADCD 2.1
 * Section: devices-modules-ilbmr-c
 * Library: devices
 * ADCD reference: devices/devices-modules-ilbmr-c.md
 */

        while (ncolors--)
                {
                r = (*rgb++ & 0xF0) << 4;
                g = *rgb++ & 0xF0;
                b = *rgb++ >> 4;
                colortable[idx] = r | g | b;
                idx++;
                }
        return(0);
        }
