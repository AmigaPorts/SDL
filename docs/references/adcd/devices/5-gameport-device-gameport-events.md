---
title: 5 Gameport Device / Gameport Events
manual: devices
chapter: devices
section: 5-gameport-device-gameport-events
functions: []
libraries: []
---

# 5 Gameport Device / Gameport Events

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A gameport event is an InputEvent structure which describes the following:

   * The class of the event - always set to IECLASS_RAWMOUSE for the

     gameport device.
   * The subclass of the event - 0 for the left port; 1 for the right port.

   * The code - which button and its state.  (No report = 0xFF)

   * The qualifier - only button and relative mouse bits are set.

   * The position - either a data address or mouse position count.

   * The time stamp - delta time since last report, returned as frame

     count in tv_secs field.
   * The next event - pointer to next event.



```c
    struct InputEvent GameEV
    {
        struct InputEvent *ie_NextEvent;  /* next event */
        UBYTE    ie_Class;                /* input event class */
        UBYTE    ie_SubClass;             /* subclass of the class */
        UWORD    ie_Code;                 /* input event code */
        UWORD    ie_Qualifier;            /* event qualifiers in effect */
           union
           {
             struct
             {
              WORD   ie_x;                /* x position for the event */
              WORD   ie_y;                /* y position for the event */
             }  ie_xy;
             APTR ie_addr;
           } ie_position;
        struct timeval ie_TimeStamp;      /* delta time since last report
    }
```
See the include file devices/[inputevent.h](autodocs-2.0/includes-devices-inputevent-h.md) for the complete structure
definition and listing of input event fields.

 [Reading Gameport Events](devices/5-gameport-events-reading-gameport-events.md) 
 [Setting Gameport Event Trigger Conditions](devices/5-gameport-events-setting-gameport-event-trigger-conditions.md) 
 [Determining The Trigger Conditions](devices/5-gameport-events-determining-the-trigger-conditions.md) 

