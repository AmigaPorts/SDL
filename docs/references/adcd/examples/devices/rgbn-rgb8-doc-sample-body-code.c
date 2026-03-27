/* Source: ADCD 2.1
 * Section: rgbn-rgb8-doc-sample-body-code
 * Library: devices
 * ADCD reference: devices/rgbn-rgb8-doc-sample-body-code.md
 */

    if(!count) {
            if (Rgb8) {
                    fread (&w, 4, 1, RGBFile);
                    lock = w & 0x00000080;
                    rgb = w >> 8;
                    count = w & 0x0000007f;
            } else {
                    w = (UWORD) getw (RGBFile);
                    lock = w & 8;
                    rgb = w >> 4;
                    count = w & 7;
            }
            if (!count)
                    if (!(count = (UBYTE) getc (RGBFile)))
                            count = (UWORD) getw (RGBFile);
    }
