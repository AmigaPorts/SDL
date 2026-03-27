---
title: 5 / Setting and Reading Controller Type / Determining The Controller Type
manual: devices
chapter: devices
section: 5-setting-and-reading-controller-type-determining-the
functions: []
libraries: []
---

# 5 / Setting and Reading Controller Type / Determining The Controller Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You determine the type of controller being used by passing an I/O request
to the device with [GPD_ASKCTYPE](autodocs-2.0/gameport-device-gpd-askctype.md) set in io_Command, 1 set in io_Length and
the number of the unit set in io_Unit. The gameport device will respond
with the type of controller being used.

   struct IOStdReq *GameIO;  /* Must be initialized prior to using */

   BYTE GetControllerType()
   {
   BYTE controller_type = 0;

   GameIO->io_Command = GPD_ASKCTYPE;         /* get type of controller */
   GameIO->io_Data = (APTR)&controller_type;  /* place data here */
   GameIO->io_Length = 1;
   DoIO(GameIO);
   return (controller_type);
   }

The BYTE value returned corresponds to one of the five controller types
noted above.

