/* Source: ADCD 2.1
 * Section: devices-apps-play8svx-play8svx-c
 * Library: devices
 * ADCD reference: devices/devices-apps-play8svx-play8svx-c.md
 */

    {
    /* Simple case for oneshot sample <= 128K (ie. most samples) */
    if(osize <= MAXSAMPLE)	BeginIO((struct IORequest *)(aout0=aio[0]));

    /* Note - this else case code is for samples >128K */
    else
