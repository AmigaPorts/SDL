/* Source: ADCD 2.1
 * Section: devices-dev-examples-read-keyboard-matrix-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-read-keyboard-matrix-c.md
 */

    {
    printf("\n%x |",bitcount);
    mask=1 << bitcount;
    for (bytecount=0;bytecount<16;bytecount+=2)
        {
        twobyte=keyMatrix[bytecount] | (keyMatrix[bytecount+1] << 8);
        if (twobyte & mask)
            printf(" *");
        else
            printf(" -");
        }
    }
