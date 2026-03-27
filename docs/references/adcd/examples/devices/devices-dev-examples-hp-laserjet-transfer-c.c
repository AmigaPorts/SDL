/* Source: ADCD 2.1
 * Section: devices-dev-examples-hp-laserjet-transfer-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-hp-laserjet-transfer-c.md
 */

        static UBYTE bit_table[] = {128, 64, 32, 16, 8, 4, 2, 1};
        UBYTE *dmatrix, Black, dvalue, threshold;
        union colorEntry *ColorInt;
        UWORD x, width, sx, *sxptr, bit;

        /* pre-compute */
        /* printer non-specific, MUST DO FOR EVERY PRINTER */
        x = PInfo->pi_xpos; /* get starting x position */
        ColorInt = PInfo->pi_ColorInt; /* get ptr to color intensities */
        sxptr = PInfo->pi_ScaleX;
        width = PInfo->pi_width; /* get # of source pixels */

        /* pre-compute threshold; are we thresholding? */
        if (threshold = PInfo->pi_threshold) { /* thresholding */
                dvalue = threshold ^ 15; /* yes, so pre-compute dither value */
                do { /* for all source pixels */
                        /* pre-compute intensity value for Black */
                        Black = ColorInt->colorByte[PCMBLACK];
                        ColorInt++; /* bump ptr for next time */

                        sx = *sxptr++;

                        /* dither and render pixel */
                        do { /* use this pixel 'sx' times */
                                /* if we should render Black */
                                if (Black > dvalue) {
                                        /* set bit */
                                        *(ptr + (x >> 3)) |= bit_table[x & 7];
                                }
                                ++x; /* done 1 more printer pixel */
                        } while (--sx);
                } while (--width);
        }
        else { /* not thresholding, pre-compute ptr to dither matrix */
                dmatrix = PInfo->pi_dmatrix + ((y & 3) << 2);
                do { /* for all source pixels */
                        /* pre-compute intensity value for Black */
                        Black = ColorInt->colorByte[PCMBLACK];
                        ColorInt++; /* bump ptr for next time */

                        sx = *sxptr++;

                        /* dither and render pixel */
                        do { /* use this pixel 'sx' times */
                                /* if we should render Black */
                                if (Black > dmatrix[x & 3]) {
                                        /* set bit */
                                        *(ptr + (x >> 3)) |= bit_table[x & 7];
                                }
                                ++x; /* done 1 more printer pixel */
                        } while (--sx);
                } while (--width);
        }
