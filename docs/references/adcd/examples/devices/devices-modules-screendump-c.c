/* Source: ADCD 2.1
 * Section: devices-modules-screendump-c
 * Library: devices
 * ADCD reference: devices/devices-modules-screendump-c.md
 */

    {
    struct IODRPReq *iodrp;
    struct MsgPort  *printerPort;
    struct ViewPort *vp;
    ULONG tmpl;
    int error = PDERR_BADDIMENSION;

    if(!scr)	return(error);

    if((!destcols)&&(!iospecial))
