/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-render-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-render-c.md
 */

        static int x;
        UBYTE *ptr, *ptr2;
        long ct;
        int i;

        ptr2 = ptr2start; /* where to put the compacted data */
        if (flag) {
                x = 0; /* flag no transfer required yet */
        }

        for (ct=0; ct<NumColorBufs; ct++, ptrstart += ColorSize) {
                i = RowSize;
                ptr = ptrstart + i - 1;
                while (i > 0 && *ptr == 0) {
                        i--;
                        ptr--;
                }

                if (i != 0) { /* if data */
                        *(++ptr) = 13;                  /* <cr> */
                        ptr = ptrstart - NUMSTARTCMD;
                        *ptr++ = 27;
                        *ptr++ = 'r';
                        *ptr++ = colorcodes[ct];        /* color */
                        *ptr++ = 27;
                        *ptr++ = dpi_code;              /* density */
                        *ptr++ = i & 0xff;
                        *ptr++ = i >> 8;                /* size */
                        i += NUMTOTALCMD;
                        if (x != 0) { /* if must transfer data */
                                /* get src start */
                                ptr = ptrstart - NUMSTARTCMD;
                                do { /* transfer and update dest ptr */
                                        *ptr2++ = *ptr++;
                                } while (--i);
                        }

                        else { /* no transfer required */
                                ptr2 += i; /* update dest ptr */
                        }
                }

                if (i != RowSize + NUMTOTALCMD) { /* if compacted or 0 */
                        x = 1; /* flag that we need to transfer next time */
                }
        }

        *ptr2++ = 13; /* cr */
        *ptr2++ = 27;
        *ptr2++ = 'J';
        *ptr2++ = y; /* y/216 lf */
        return(ptr2);
