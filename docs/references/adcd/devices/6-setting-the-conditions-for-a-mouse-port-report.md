---
title: 6 / Setting The Conditions For A Mouse Port Report
manual: devices
chapter: devices
section: 6-setting-the-conditions-for-a-mouse-port-report
functions: []
libraries: []
---

# 6 / Setting The Conditions For A Mouse Port Report

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You set the conditions for a mouse port report by passing an [IOStdReq](devices/6-input-device-device-interface.md) to
the device with [IND_SETMTRIG](autodocs-2.0/input-device-ind-setmtrig.md) set in io_Command, the address of a
GamePortTrigger structure set in io_Data and the length of the structure
set in io_Length.

   struct GamePortTrigger InputTR;

   InputIO->io_Data = (APTR)InputTR;     /* set trigger conditions */
   InputIO->io_Command = IND_SETMTRIG;   /* from InputTR */
   InputIO->io_Length = sizeof(struct GamePortTrigger);
   DoIO(InputIO);

The information needed for mouse port report setting is contained in a
GamePortTrigger data structure which is defined in the include file
devices/[gameport.h](autodocs-2.0/includes-devices-gameport-h.md).

   struct GamePortTrigger
   {
```c
       UWORD    gpt_Keys;      /* key transition triggers */
       UWORD    gpt_Timeout;   /* time trigger (vertical blank units) */
       UWORD    gpt_XDelta;    /* X distance trigger */
       UWORD    gpt_YDelta;    /* Y distance trigger */
```
   };

See the [Gameport Device](devices/5-gameport-device.md) chapter of this manual for a full description
of setting mouse port trigger conditions.

