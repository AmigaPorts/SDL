/* Source: ADCD 2.1
 * Section: devices-dev-examples-cbio-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-cbio-c.md
 */

    {
    if (ior=CreateExtIO(mp,sizeof(struct IOClipReq)))
        {
        if (!(OpenDevice("clipboard.device",unit,ior,0L)))
            {
            return((struct IOClipReq *)ior);
            }
        DeleteExtIO(ior);
        }
    DeletePort(mp);
    }
