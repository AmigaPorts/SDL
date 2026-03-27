---
title: 3 Intuition Screens / Types of Screens
manual: libraries
chapter: libraries
section: 3-intuition-screens-types-of-screens
functions: []
libraries: []
---

# 3 Intuition Screens / Types of Screens

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Screens are important because they determine the basic resolution and
maximum number of colors in the display.  Once a screen is set up, these
attributes cannot be changed so any graphics work done on a given screen
is restricted to that screen's resolution and number of colors.  Hence,
the type of screen used is a basic design decision.

With Intuition screens, a [video display](libraries/27-introduction-introduction-to-raster-displays.md) can be created in any one of the
many Amiga display modes.  The basic parameters of the video display such
as resolution, total size, frame rate, genlock compatibility, support of
screen movement and number of colors are defined by these modes.  There
are currently four basic modes available on all Amiga models.  These basic
modes work with conventional monitors (15 kHz scan rate) and older
[versions](libraries/1-programming-in-the-amiga-environment-operating-system.md) of the operating system.




```c
            Table 3-1: Basic Amiga Display Modes


     Basic Amiga      Resolution  Maximum    Supports
    Display Modes        NTSC       PAL       Colors    HAM/EHB*
    -------------     ----------  -------    --------   -------
    [Lores](libraries/27-introduction-low-high-and-super-high-resolution-modes.md)              320x200    320x256   32 of 4096    Yes
    Lores-[Interlaced](libraries/27-introduction-interlaced-and-non-interlaced-modes.md)   320x400    320x512   32 of 4096    Yes
    [Hires](libraries/27-introduction-low-high-and-super-high-resolution-modes.md)              640x200    640x256   16 of 4096    No
    Hires-Interlaced   640x400    640x512   16 of 4096    No


    * [HAM](libraries/27-advanced-topics-hold-and-modify-mode.md) and [EHB](libraries/27-advanced-topics-extra-half-brite-mode.md) modes provide for additional colors with some
      restrictions.
```
With Release 2 of the operating system, many other display modes are
available (these usually require a [special monitor](libraries/27-monitors-modes-and-the-display-database-new-monitors.md) or [ECS](libraries/27-introduction-about-ecs.md)).  All these
display modes, including the specialized modes, are integrated through the
graphics library display database.  See the "[Graphics Primitives](libraries/27-resolution-modes-display-modes-colors-and-requirements.md)" chapter
for a complete list of all Amiga display modes.

 [Multiple Screens](libraries/3-types-of-screens-multiple-screens.md) 
 [Public Screens and Custom Screens](libraries/3-types-of-screens-public-screens-and-custom-screens.md) 
 [Screen Components](libraries/3-types-of-screens-screen-components.md) 

