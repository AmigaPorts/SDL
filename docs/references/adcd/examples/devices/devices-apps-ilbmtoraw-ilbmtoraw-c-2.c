/* Source: ADCD 2.1
 * Section: devices-apps-ilbmtoraw-ilbmtoraw-c
 * Library: devices
 * ADCD reference: devices/devices-apps-ilbmtoraw-ilbmtoraw-c.md
 */

    {
    SHORT i;
    LONG nb,plsize;

    LONG file = Open( name, MODE_NEWFILE);
    if( file == 0 )
