/* Source: ADCD 2.1
 * Section: 3-device-interface-opening-the-clipboard-device
 * Library: devices
 * ADCD reference: devices/3-device-interface-opening-the-clipboard-device.md
 */

    *  Create a message port using [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html). Reply messages from the
       device must be directed to a message port.

    *  Create an extended I/O request structure of type [IOClipReq](../Devices_Manual_guide/node0067.html#line5) using
       [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).

    *  Open the clipboard device. Call [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html), passing the IOClipReq.


    struct MsgPort  *ClipMP;          /* pointer to message port*/
    struct IOClipReq *ClipIO;         /* pointer to IORequest */

    if (ClipMP=CreatePort(0L,0L) )
        {
        if (ClipIO=(struct IOClipReq *)
                    CreateExtIO(ClipMP,sizeof(struct IOClipReq)))
            {
            if (OpenDevice("clipboard.device",0L,ClipIO,0))
                printf("clipboard.device did not open\n");
            else
                {
                 ... do device processing
                }
            {
        else
            printf("Error: Could not create IORequest\n");
        }
    else
        printf("Error: Could not create message port\n");
