---
title: 3 / Device Interface / Opening The Clipboard Device
manual: devices
chapter: devices
section: 3-device-interface-opening-the-clipboard-device
functions: [OpenDevice]
libraries: [exec.library]
---

# 3 / Device Interface / Opening The Clipboard Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the clipboard device:


```c
    *  Create a message port using [CreatePort()](autodocs-2.0/amiga-lib-createport.md). Reply messages from the
       device must be directed to a message port.

    *  Create an extended I/O request structure of type [IOClipReq](devices/3-clipboard-device-device-interface.md) using
       [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).

    *  Open the clipboard device. Call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md), passing the IOClipReq.


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

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
