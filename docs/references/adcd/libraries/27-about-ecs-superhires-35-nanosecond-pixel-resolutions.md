---
title: 27 / / About ECS / SuperHires (35 nanosecond) Pixel Resolutions
manual: libraries
chapter: libraries
section: 27-about-ecs-superhires-35-nanosecond-pixel-resolutions
functions: []
libraries: []
---

# 27 / / About ECS / SuperHires (35 nanosecond) Pixel Resolutions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The enhanced version of the Denise chip can generate SuperHires pixels
that are twice as fine as Hires pixels.  It is convenient to refer to
pixels here by their speed, rather than width, for reasons that will be
explained below.  They are approximately 35nS long, while Hires are 70nS,
and Lores 140nS.  In the absence of any other features, this can bring a
new mode with nominal dimensions of 1280 x 200 (NTSC) or 1280 x 256 (PAL).
This mode requires the ECS Agnus chip as well.

When Denise is generating these new fast pixels, simple bandwidth
arithmetic indicates that at most two bitplanes can be supported.  Also
note that with two bitplanes, DMA bandwidth is saturated.  The palette for
SuperHires pixels is also restricted to 64 colors.

