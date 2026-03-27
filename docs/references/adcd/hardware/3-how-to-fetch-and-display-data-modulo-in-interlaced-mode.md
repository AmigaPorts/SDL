---
title: 3 / / How to Fetch and Display Data / Modulo in Interlaced Mode
manual: hardware
chapter: hardware
section: 3-how-to-fetch-and-display-data-modulo-in-interlaced-mode
functions: []
libraries: []
---

# 3 / / How to Fetch and Display Data / Modulo in Interlaced Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For interlaced mode, you must redefine the modulo, because interlaced mode
uses two separate scannings of the video screen for a single display of
the playfield. During the first scanning, the odd-numbered lines are
fetched to the screen; and during the second scanning, the even-numbered
lines are fetched.

The bitplanes for a full-screen-sized, interlaced display are 400 NTSC
(512 PAL), rather than 200 NTSC (256 PAL), lines long. Assuming that the
playfield in memory is the normal 320 pixels wide, data for the interlaced
picture begins at the following locations (these are all byte addresses):


                    Line 1   START
                    Line 2   START+40
                    Line 3   START+80
                    Line 4   START+120
and so on. Therefore, you use a modulo of 40 to skip the lines in the
other field. For odd fields, the bitplane pointers begin at START. For
even fields, the bitplane pointers begin at START+40.

You can use the Copper to handle resetting of the bitplane pointers for
interlaced displays.

