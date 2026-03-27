/* Source: ADCD 2.1
 * Section: devices-modules-unpacker-c
 * Library: devices
 * ADCD reference: devices/devices-modules-unpacker-c.md
 */

    {
    register BYTE *source = *pSource;
    register BYTE *dest   = *pDest;
    register WORD n;
    register BYTE c;
    register WORD srcBytes = srcBytes0, dstBytes = dstBytes0;
    BOOL error = TRUE;	/* assume error until we make it through the loop */
    WORD minus128 = -128;  /* get the compiler to generate a CMP.W */

    while( dstBytes > 0 )  {
