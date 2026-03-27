/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-render-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-render-c.md
 */

        ULONG *lptr, i, j;

        /*
                Note : Since 'NUMTOTALCMD + NUMLFCMD' is > 3 bytes if is safe
                to do the following to speed things up.
        */
        i = TwoBufSize - NUMTOTALCMD - NUMLFCMD;
        j = (ULONG)ptr;
        if (!(j & 1)) { /* if on a word boundary, clear by longs */
                i = (i + 3) / 4;
                lptr = (ULONG *)ptr;
                do {
                        *lptr++ = 0;
                } while (--i);
        }
        else { /* clear by bytes */
                do {
                        *ptr++ = 0;
                } while (--i);
        }
        return(0);
