# 3 / Device Interface / Opening The Clipboard Device


Three primary steps are required to open the clipboard device:


```c
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
```
