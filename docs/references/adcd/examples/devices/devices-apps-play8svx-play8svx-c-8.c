/* Source: ADCD 2.1
 * Section: devices-apps-play8svx-play8svx-c
 * Library: devices
 * ADCD reference: devices/devices-apps-play8svx-play8svx-c.md
 */

    {
    struct IFFHandle *iff;
    LONG sbytes, rlen, error = 0L;
    ULONG memtype;
    Voice8Header *vhdr = &esvx->Vhdr;
    BYTE *t;

    D(bug("LoadSBody:\n"));

    if(!(iff=esvx->ParseInfo.iff))	return(CLIENT_ERROR);
    if(!esvx)				return(CLIENT_ERROR);

    if(!(currentchunkis(iff,ID_8SVX,ID_BODY)))
