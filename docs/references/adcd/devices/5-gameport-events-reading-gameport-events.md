---
title: 5 / Gameport Events / Reading Gameport Events
manual: devices
chapter: devices
section: 5-gameport-events-reading-gameport-events
functions: []
libraries: []
---

# 5 / Gameport Events / Reading Gameport Events

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You read gameport events by passing an I/O request to the device with
[GPD_READEVENT](autodocs-2.0/gameport-device-gpd-readevent.md) set in io_Command, the address of the [InputEvent](devices/5-gameport-device-gameport-events.md) structure
to store events set in io_Data and the size of the structure set in
io_Length.

   struct InputEvent  GameEV;
   struct IOStdRequest *GameIO;  /* Must be initialized prior to using */

   void send_read_request()
   {
   GameIO->io_Command = GPD_READEVENT;  /* Read events */
   GameIO->io_Length = sizeof (struct InputEvent);
   GameIO->io_Data = (APTR)&GameEV;     /* put events in GameEV*/
   SendIO(GameIO);                      /* Asynchronous */
   }

