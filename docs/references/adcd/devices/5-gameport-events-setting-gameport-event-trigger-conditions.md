---
title: 5 / Gameport Events / Setting Gameport Event Trigger Conditions
manual: devices
chapter: devices
section: 5-gameport-events-setting-gameport-event-trigger-conditions
functions: []
libraries: []
---

# 5 / Gameport Events / Setting Gameport Event Trigger Conditions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You set the conditions that can trigger a gameport event by passing an I/O
request to the device with [GPD_SETTRIGGER](autodocs-2.0/gameport-device-gpd-settrigger.md) set in io_Command and the
address of a GamePortTrigger structure set in io_Data.

The information needed for gameport trigger setting is placed into a
GamePortTrigger data structure which is defined in the include file
devices/[gameport.h](autodocs-2.0/includes-devices-gameport-h.md).


```c
    struct GamePortTrigger
    {
        UWORD    gpt_Keys;      /* key transition triggers */
        UWORD    gpt_Timeout;   /* time trigger (vertical blank units) */
        UWORD    gpt_XDelta;    /* X distance trigger */
        UWORD    gpt_YDelta;    /* Y distance trigger */
    }
```
A few points to keep in mind with the [GPD_SETTRIGGER](autodocs-2.0/gameport-device-gpd-settrigger.md) command are:


```c
    *  Setting GPTF_UPKEYS enables the reporting of upward transitions.
       Setting GPTF_DOWNKEYS enables the reporting of downward transitions.
       These flags may both be specified.

    *  The field gpt_Timeout specifies the time interval (in vertical blank
       units) between reports in the absence of another trigger condition.
       In other words, an event is generated every gpt_Timeout ticks.
       Vertical blank units may differ from country to country (e.g 60 Hz
       NTSC, 50 Hz PAL.)  To find out the exact frequency use this code
       fragment:

       #include <exec/execbase.h>
       extern struct ExecBase *SysBase;

       UBYTE get_frequency(void)
       {
       return((UBYTE)SysBase->VBlankFrequency);
       }

    *  The gpt_XDelta and gpt_YDelta fields specify the x and y distances
       which, if exceeded, trigger a report.
```
For a mouse controller, you can trigger on a certain minimum-sized move in
either the x or y direction, on up or down transitions of the mouse
buttons, on a timed basis, or any combination of these conditions.

For example, suppose you normally signal mouse events if the mouse moves
at least 10 counts in either the x or y directions. If you are moving the
cursor to keep up with mouse movements and the user moves the mouse less
than 10 counts, after a period of time you will want to update the
position of the cursor to exactly match the mouse position. Thus the timed
report of current mouse counts would be preferred. The following structure
would be used:


```c
    #define XMOVE 10
    #define YMOVE 10

    struct GamePortTrigger GameTR =
    {
        GPTF_UPKEYS | GPTF_DOWNKEYS, /* trigger on all key transitions */
        1800,                  /* and every 36(PAL) or 30(NTSC) seconds */
        XMOVE,                 /* for any 10 in an x or y direction */
        YMOVE
    };
```
For a joystick controller, you can select timed reports as well as
button-up and button-down report trigger conditions. For an absolute
joystick specify a value of one (1) for the GameTR_XDelta and
GameTR_YDelta fields or you will not get any direction events. You set the
trigger conditions by using the following code or its equivalent:


```c
    struct IOStdReq *GameIO;

    void set_trigger_conditions(struct GamePortTrigger *GameTR)
    {
    GameIO->io_Command = GPD_SETTRIGGER;    /* set trigger conditions */
    GameIO->io_Data = (APTR)GameTR;         /* from GameTR */
    GameIO->io_Length = sizeof(struct GamePortTrigger);
    DoIO(GameIO);
    }
```
   Triggers and Reads.
   -------------------
   If a task sets trigger conditions and does not ask for the position
   reports the gameport device will queue them up anyway. If the trigger
   conditions occur again and the gameport device buffer is filled, the
   additional triggers will be ignored until the buffer is read by a
   device read request ([GPD_READEVENT](devices/5-gameport-events-reading-gameport-events.md)) or a system CMD_CLEAR command
   flushes the buffer.

