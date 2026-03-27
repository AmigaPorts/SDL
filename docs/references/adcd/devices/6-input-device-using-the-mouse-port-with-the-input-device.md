---
title: 6 Input Device / Using the Mouse Port With the Input Device
manual: devices
chapter: devices
section: 6-input-device-using-the-mouse-port-with-the-input-device
functions: []
libraries: []
---

# 6 Input Device / Using the Mouse Port With the Input Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To get mouse port information you must first set the current mouse port by
passing an [IOStdReq](devices/6-input-device-device-interface.md) to the device with [IND_SETMPORT](autodocs-2.0/input-device-ind-setmport.md) set in io_Command and
a pointer to a byte set in io_Data.  If the byte is set to 0 the left
controller port will be used as the current mouse port; if it is set to 1,
the right controller port will be used.

   BYTE port = 1;      /* set mouse port to right controller */

   InputIO->io_Data = &port;
   InputIO->io_Flags = IOF_QUICK;
   InputIO->io_Length = 1;
   InputIO->io_Command = IND_SETMPORT;
   BeginIO((struct IORequest *)InputIO);
   if (InputIO->io_Error)

```c
       printf("\nSETMPORT failed %d\n",InputIO->io_Error);
```
   Put That Back!
   --------------
   The default mouse port is the left controller.  Don't forget to set
   the mouse port back to the left controller before exiting if you
   change it to the right controller during your application.

 [Setting The Conditions For A Mouse Port Report](devices/6-setting-the-conditions-for-a-mouse-port-report.md) 

