---
title: 3 Intuition Screens / Overscan and the Display Clip
manual: libraries
chapter: libraries
section: 3-intuition-screens-overscan-and-the-display-clip
functions: []
libraries: []
---

# 3 Intuition Screens / Overscan and the Display Clip

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Screens may be larger or smaller than the defined display area (overscan
rectangle or display clip).  When a screen is smaller than the display
area, the display clip acts as a "container" for the screen.  The screen
may be moved anywhere within the display clip.  When a screen is larger
than the display area, the display clip acts as a "window" into the
screen.  The screen may be moved so that different parts are visible.
Each dimension of the screen is independent and may be larger than, the
same as, or smaller than the dimensions of the display clip.

The system is very flexible in its specification of screen size.  Unless
an application fixes its screen size with hard coded values, it should be
prepared to handle the possibility that the user has changed the default
overscan presets or the default monitor (NTSC/PAL).

Use the constants STDSCREENHEIGHT and STDSCREENWIDTH with the [SA_Width](libraries/3-custom-screen-functions-screen-attributes.md) and
[SA_Height](libraries/3-custom-screen-functions-screen-attributes.md) tags to open a screen the same size as the display clip.  These
constants will work with any of the preset overscan values set with
[SA_Overscan](libraries/3-custom-screen-functions-screen-attributes.md), and with custom overscan values set with [SA_DClip](libraries/3-custom-screen-functions-screen-attributes.md).

 [Preset Overscan Values](libraries/3-overscan-and-the-display-clip-preset-overscan-values.md) 

