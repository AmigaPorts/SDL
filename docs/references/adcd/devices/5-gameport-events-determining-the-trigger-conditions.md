---
title: 5 / Gameport Events / Determining The Trigger Conditions
manual: devices
chapter: devices
section: 5-gameport-events-determining-the-trigger-conditions
functions: []
libraries: []
---

# 5 / Gameport Events / Determining The Trigger Conditions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You determine the conditions required for triggering gameport events by
passing an I/O request to the device with [GPD_ASKTRIGGER](autodocs-2.0/gameport-device-gpd-asktrigger.md) set in
io_Command, the length of the [GamePortTrigger](devices/5-gameport-events-setting-gameport-event-trigger-conditions.md) structure set in io_Length
and the address of the structure set in io_Data.  The gameport device will
respond with the event trigger conditions currently set.


```c
    struct IOStdReq *GameIO;  /* Must be initialized prior to using */

    struct GamePortTrigger GameTR;

    void get_trigger_conditions(struct GamePortTrigger *GameTR)
    {
    GameIO->io_Command = GPD_ASKTRIGGER;    /* get type of triggers */
    GameIO->io_Data = (APTR)GameTR;         /* place data here */
    GameIO->io_Length= sizeof(GameTR);
    DoIO(GameIO);
    }
```
