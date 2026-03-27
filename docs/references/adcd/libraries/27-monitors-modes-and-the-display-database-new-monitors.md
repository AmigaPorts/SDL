---
title: 27 / / Monitors, Modes and the Display Database / New Monitors
manual: libraries
chapter: libraries
section: 27-monitors-modes-and-the-display-database-new-monitors
functions: []
libraries: []
---

# 27 / / Monitors, Modes and the Display Database / New Monitors

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Currently, there are five possible monitor settings in the display
database (more may be added in future releases):

default.monitor

    Since the default system monitor must be capable of displaying an
    image no matter what chips are installed or what software revision is
    in ROM, the graphics.library default.monitor is defined as a 15 Khz
    monitor which can display NTSC in the U.S. or PAL in Europe.
ntsc.monitor

    Since the ECS chip set allows for dynamic choice of standard scan
    rates, NTSC applications running on European machines may choose to
    be displayed on the ntsc.monitor to preserve the aspect ratio.
pal.monitor

    Since the ECS chip set allows for dynamic choice of standard scan
    rates, PAL applications running on American machines may choose to be
    displayed on the pal.monitor to preserve the aspect ratio.
multisync.monitor

```c
    Programmably variable scan rates from 15 Khz through 31 Khz or more.
    Responds to signal timings to decide what scan rate to display.
    Required for Productivity (640 x 480 x 2 non-interlaced) display.
```
A2024.monitor

```c
    Scan converter monitor which provides 1008 x 800 x 2 (U.S.) or 1008 x
    1024 x 2 (European) high-resolution, greyscale display.  Does not
    require ECS.  Does require Release 2 (or 1.3 V35) graphics library.
```
