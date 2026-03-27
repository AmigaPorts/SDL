---
title: DisplayClip
manual: amiga-mail
chapter: amiga-mail
section: displayclip
functions: []
libraries: []
---

# DisplayClip

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The DisplayClip defines the on-monitor region, and is independent of
the screen dimension.  The rectangle describing the DisplayClip
determines how much of the screen can be seen at a time.  The screen
is "shown through" the DisplayClip in much the same way a SuperBitmap
is shown through a window.  If the screen is larger than the
DisplayClip, only part of the screen will be visible.  The DisplayClip
makes it is possible for Intuition to support hardware scrolling of a
raster larger than can fit on the display.  Intuition will take care
of specifying the rectangle of the DisplayClip region based on the
default screen dimensions or based on the SA_Overscan tag (if it is
present), so most programs shouldn't have to specify the DisplayClip
rectangle.

Example 3, [ScreenDisplayModes.c](amiga-mail/iv-3-screendisplaymodes-c.md), illustrates opening any type of
screen currently available to the system, using any type of available
overscan.

