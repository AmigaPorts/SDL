---
title: 7 / Device Interface / Opening The Keyboard Device
manual: devices
chapter: devices
section: 7-device-interface-opening-the-keyboard-device
functions: [OpenDevice]
libraries: [exec.library]
---

# 7 / Device Interface / Opening The Keyboard Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the keyboard device:

   *  Create a message port using the [CreatePort()](autodocs-2.0/amiga-lib-createport.md) function.

   *  Create an extended I/O request structure using the [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)

```c
      function. CreateExtIO() will initialize the I/O request with your
      reply port.
```
   *  Open the keyboard device. Call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md), passing the I/O request.


struct MsgPort  *KeyMP;         /* Pointer for Message Port */
struct IOStdReq *KeyIO;         /* Pointer for I/O request */

if (KeyMP=CreatePort(NULL,NULL))
  if (KeyIO=(struct IOStdReq *)CreateExtIO(KeyMP,sizeof(struct IOStdReq)))

```c
    if (OpenDevice( "keyboard.device",NULL,(struct IORequest *)KeyIO,NULL))
        printf("keyboard.device did not open\n");
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
