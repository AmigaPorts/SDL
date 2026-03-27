/* Source: ADCD 2.1
 * Section: devices-apps-play8svx-play8svx-c
 * Library: devices
 * ADCD reference: devices/devices-apps-play8svx-play8svx-c.md
 */

    {
    struct IFFHandle *iff;
    struct StoredProperty *sp;
    Voice8Header *vhdr;
    BYTE *oneshot, *repeat;
    ULONG osize, rsize, spcyc;
    int oct;
    LONG error = 0L;

    D(bug("LoadSample:\n"));

    if(!esvx)				return(CLIENT_ERROR);
    if(!(iff=esvx->ParseInfo.iff))	return(CLIENT_ERROR);

    if(!(error = openifile((struct ParseInfo *)esvx, filename, IFFF_READ)))
