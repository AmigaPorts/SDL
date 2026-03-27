/* Source: ADCD 2.1
 * Section: devices-modules-packer-c
 * Library: devices
 * ADCD reference: devices/devices-modules-packer-c.md
 */

    {
    BYTE *source, *dest;
    char c,lastc = '\0';
    BOOL mode = DUMP;
    short nbuf = 0;		/* number of chars in buffer */
    short rstart = 0;		/* buffer index current run starts */

    source = *pSource;
    dest = *pDest;
    putSize = 0;
    buf[0] = lastc = c = GetByte();  /* so have valid lastc */
    nbuf = 1;   rowSize--;	/* since one byte eaten.*/


    for (;  rowSize;  --rowSize) {
