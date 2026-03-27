/* Source: ADCD 2.1
 * Section: devices-apps-ilbmtoc-ilbmtoc-c
 * Library: devices
 * ADCD reference: devices/devices-apps-ilbmtoc-ilbmtoc-c.md
 */

    {
    UBYTE *sw;
    FILE *fp;
    LONG error=NULL;
    UBYTE *ilbmname, name[80], fname[80];

    if ((argc < 2)||(argv[argc-1][0]=='?'))
