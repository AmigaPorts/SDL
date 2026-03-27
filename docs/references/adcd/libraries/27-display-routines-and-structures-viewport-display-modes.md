---
title: 27 / Display Routines and Structures / Viewport Display Modes
manual: libraries
chapter: libraries
section: 27-display-routines-and-structures-viewport-display-modes
functions: [VideoControl]
libraries: [graphics.library]
---

# 27 / Display Routines and Structures / Viewport Display Modes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The system has many different display modes that you can specify for each
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).  Under 1.3, the eight constants that control the modes are
DUALPF, PFBA, HIRES, SUPERHIRES, LACE, HAM, SPRITES, and EXTRA_HALFBRITE.
Some, but not all of the modes can be combined in a ViewPort.  HIRES and
LACE combine to make a high-resolution, interlaced ViewPort, but HIRES and
SUPERHIRES conflict, and cannot be combined.

Under 1.3, you set these flags directly in the Modes field during
initialization of the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).  Under Release 2, there are many more
display modes possible than in 1.3 so a new system of flags and structures
is used to set the mode.  With Release 2, you set the display mode for a
ViewPort by using the [VideoControl()](libraries/27-mode-specification-viewport-interface.md) function as described in the section
on "[Monitors, Modes and the Display Database](libraries/27-routines-and-structures-monitors-modes-and-display.md)" later in this chapter.

The [DUALPF](autodocs-2.0/includes-graphics-view-h.md) and PFBA modes are related.  DUALPF tells the system to treat
the raster specified by this [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) as the first of two independent and
separately controllable playfields. It also modifies the manner in which
the pixel colors are selected for this raster (see the [above table](libraries/27-display-routines-and-structures-viewport-color-selection.md)).

When [PFBA](autodocs-2.0/includes-graphics-view-h.md) is specified, it indicates that the second playfield has video
priority over the first one.  Playfield relative priorities can be
controlled when the playfield is split into two overlapping regions.
Single-playfield and dual-playfield modes are discussed below in
"[Advanced Topics](libraries/27-advanced-topics-creating-a-dual-playfield-display.md)."

[HIRES](autodocs-2.0/includes-graphics-view-h.md) tells the system that the raster specified by this [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) is to be
displayed with (nominally) 640 horizontal pixels, rather than the 320
horizontal pixels of Lores mode.

[SUPERHIRES](autodocs-2.0/includes-graphics-view-h.md) tells the system that the raster specified by this [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) is
to be displayed with (nominally) 1280 horizontal pixels.  This can be used
with 31 kHz scan rates to provide the VGA and Productivity modes available
in Release 2.  SUPERHIRES modes require both the ECS and Release 2.   See
the section on "[Determining Chip Versions](libraries/27-about-ecs-determining-chip-versions.md)" earlier in this chapter for an
explanation of how to find out if the ECS is present.

[LACE](autodocs-2.0/includes-graphics-view-h.md) tells the system that the raster specified by this [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) is to be
displayed in interlaced mode. If the ViewPort is non-interlaced and the
[View](libraries/27-display-routines-and-structures-viewport-display-memory.md) is interlaced, the ViewPort will be displayed at its specified height
and will look only slightly different than it would look when displayed in
a non-interlaced View (this is handled by the system automatically). See
"[Interlaced Mode vs. Non-interlaced Mode](libraries/27-viewport-display-modes-interlaced-vs-non-interlaced-mode.md)" below for more information.

[HAM](autodocs-2.0/includes-graphics-view-h.md) tells the system to use "hold-and-modify" mode, a special mode that
lets you display up to 4,096 colors on screen at the same time. It is
described in the "[Advanced Topics](libraries/27-advanced-topics-hold-and-modify-mode.md)" section.

[SPRITES](autodocs-2.0/includes-graphics-view-h.md) tells the system that you are using sprites in this display
(either [VSprites](libraries/28-graphics-sprites-bobs-and-animation-using-virtual-sprites.md) or [Simple Sprites](libraries/28-sprites-bobs-and-animation-using-simple-hardware-sprites.md)). The system will load color registers
for the sprites. Note that since the mouse pointer is a sprite, omitting
this mode will prevent the mouse pointer from being displayed when this
ViewPort is frontmost. See the "[Graphics Sprites, Bobs and Animation](libraries/28-graphics-sprites-bobs-and-animation.md)"
chapter for more information about sprites.

[EXTRA_HALFBRITE](autodocs-2.0/includes-graphics-view-h.md) tells the system to use the Extra-Half-Brite mode, a
special mode that allows you to display up to 64 colors on screen at the
same time.  It is described in the "[Advanced Topics](libraries/27-advanced-topics-extra-half-brite-mode.md)" section.

If you peruse the <graphics/[view.h](autodocs-2.0/includes-graphics-view-h.md)> include file you will see another
flag, [EXTENDED_MODE](autodocs-2.0/includes-graphics-view-h.md). Never set this flag yourself; it is used by the
Release 2 system to control more advanced mode features.

Be sure to read the section on "[Monitors, Modes and the Display Database](libraries/27-routines-and-structures-monitors-modes-and-display.md)"
for additional information about the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) mode and how it has changed
in the Release 2 version of the operating system.

 [Single-playfield Mode vs. Dual-playfield Mode](libraries/27-viewport-display-modes-single-vs-dual-playfield-mode.md) 
 [Low-resolution Mode vs. High-resolution Mode](libraries/27-viewport-display-modes-low-vs-high-resolution-mode.md) 
 [Interlaced Mode vs. Non-interlaced Mode](libraries/27-viewport-display-modes-interlaced-vs-non-interlaced-mode.md) 

---

## See Also

- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
