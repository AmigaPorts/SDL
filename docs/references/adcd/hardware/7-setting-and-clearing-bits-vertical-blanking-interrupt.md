---
title: 7 / / Setting and Clearing Bits / Vertical Blanking Interrupt
manual: hardware
chapter: hardware
section: 7-setting-and-clearing-bits-vertical-blanking-interrupt
functions: []
libraries: []
---

# 7 / / Setting and Clearing Bits / Vertical Blanking Interrupt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Bit 5, VERTB, causes an interrupt at line 0 (start of vertical blank) of
the video display frame. The system is often required to perform many
different tasks during the vertical blanking interval. Among these tasks
are the updating of various pointer registers, rewriting lists of Copper
tasks when necessary, and other system-control operations.

The minimum time of vertical blanking is 20 horizontal scan lines for an
NTSC system and 25 horizontal scan lines for a PAL system. The range
starts at line 0 and ends at line 20 for NTSC or line 25 for PAL. After
the minimum vertical blanking range, you can control where the display
actually starts by using the  [DIWSTRT](hardware/3-picture-larger-selecting-the-display-window-starting.md)  (display window start) register
to extend the effective vertical blanking time. See Chapter 3, "Playfield
Hardware," for more information on  [DIWSTRT](hardware/3-picture-larger-selecting-the-display-window-starting.md) .

If you find that you still require additional time during vertical
blanking, you can use the Copper to create a  [level 3 interrupt](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md) . This
Copper interrupt would be timed to occur just after the last line of
display on the screen (after the display window stop which you have
defined by using the  [DIWSTOP](hardware/3-size-display-window-setting-display-window-stopping.md)  register).

