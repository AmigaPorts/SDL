---
title: 27 / / About ECS / Productivity Mode
manual: libraries
chapter: libraries
section: 27-about-ecs-productivity-mode
functions: []
libraries: []
---

# 27 / / About ECS / Productivity Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The enhanced version of the Denise chip can support monitor horizontal
scan frequencies of 31KHz, twice the old 15.75KHz rate.  This provides
over 400 non-interlaced horizontal lines in a frame, but requires the use
of a multiple scan rate, or multi-sync monitor.

This effect speeds up the video beam roughly by a factor of two, which has
the side effect of doubling the width of a pixel emitted at a given speed.
Thus, for a given Denise mode, pixels are twice as fat, and there are half
as many on a given line.

The increased scan rate interacts with all of the Denise modes.  So with
both SuperHires (35nS) pixels and the double scan rate the display
generated would be 640 pixels wide by more than 400 rows, non-interlaced,
with up to four colors from a palette of 64.  This combination is termed
Productivity mode, and the default international height is 480 rows. This
conforms, in a general way, to the VGA Mode 3 Standard 8514/A.

The support in Agnus is actually more flexible, and gives the ability to
conform to special-purpose modes, such as displays synchronized to motion
picture cameras.

