---
title: 28 / / Other Items Influencing Bob Colors / PlanePick
manual: libraries
chapter: libraries
section: 28-other-items-influencing-bob-colors-planepick
functions: []
libraries: []
---

# 28 / / Other Items Influencing Bob Colors / PlanePick

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Because the [Depth](libraries/28-using-bobs-specifying-the-colors-of-a-bob.md) of the Bob can be less than the background, the
[PlanePick](autodocs-2.0/includes-graphics-gels-h.md) member is provided so that the application can indicate which
background bitplanes are to have image data put into them.  The system
starts with the least significant plane of the Bob, and scans PlanePick
starting at the least significant bit, looking for a plane of the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)
to put it in.

For example, if [PlanePick](autodocs-2.0/includes-graphics-gels-h.md) has a binary value of: 0 0 0 0   0 0 1 1 (0x03)
then the system draws the first plane of the Bob's image into background
plane 0 and the second plane into background plane 1.

Alternatively, a [PlanePick](autodocs-2.0/includes-graphics-gels-h.md) value of:  0 0 0 1   0 0 1 0 (0x12) directs the
system to put the first Bob plane into plane 1, and the second Bob plane
into plane 4.

