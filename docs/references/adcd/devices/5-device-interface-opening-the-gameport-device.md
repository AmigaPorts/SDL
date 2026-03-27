---
title: 5 / Device Interface / Opening The Gameport Device
manual: devices
chapter: devices
section: 5-device-interface-opening-the-gameport-device
functions: [OpenDevice]
libraries: [exec.library]
---

# 5 / Device Interface / Opening The Gameport Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the gameport device:

   *  Create a message port using [CreatePort()](autodocs-2.0/amiga-lib-createport.md). Reply messages from the

      device must be directed to a message port.
   *  Create an I/O request structure of type [IOStdReq](devices/5-gameport-device-device-interface.md). The IOStdReq

```c
      structure is created by the [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) function. CreateExtIO()
      will initialize the I/O request with your reply port.
```
   *  Open the gameport device.  Call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md), passing the I/O request

      and and indicating the unit you wish to use.
   struct MsgPort *GameMP;   /* Message port pointer */
   struct IOStdReq *GameIO;  /* I/O request pointer */

     /* Create port for gameport device communications */
   if (!(GameMP = CreatePort("RKM_game_port",0)))
```c
       cleanexit(" Error: Can't create port\n",RETURN_FAIL);

     /* Create message block for device I/O */
```
   if (!(GameIO = CreateExtIO(GameMP,sizeof(struct IOStdReq))))
```c
       cleanexit(" Error: Can't create I/O request\n",RETURN_FAIL);

     /* Open the right/back (unit 1, number 2) gameport.device unit */
```
   if (error=OpenDevice("gameport.device",1,GameIO,0))

```c
       cleanexit(" Error: Can't open gameport.device\n",RETURN_FAIL);
```
The gameport commands are unit specific.  The unit number specified in the
call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) determines which unit is acted upon.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
