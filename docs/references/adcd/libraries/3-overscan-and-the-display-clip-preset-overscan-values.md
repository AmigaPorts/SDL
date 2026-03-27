---
title: 3 / Overscan and the Display Clip / Preset Overscan Values
manual: libraries
chapter: libraries
section: 3-overscan-and-the-display-clip-preset-overscan-values
functions: [GetVPModeID, QueryOverscan, VideoControl]
libraries: [graphics.library, intuition.library]
---

# 3 / Overscan and the Display Clip / Preset Overscan Values

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Four preset overscan dimensions are provided.  Applications that support
overscan should use these preset values where possible since they will be
tailored to each individual system.  Avoid using custom values that happen
to look good on a specific system.  However, be aware that the size and
positioning of overscan screens can be different on every system depending
on how the user has set Overscan Preferences.  These preset values are
also dependent on the underlying display mode so keep in mind that both
offset and size parameters will change under different screen modes.
Overscan presets can be used, among other things, with the [SA_Overscan](libraries/3-custom-screen-functions-screen-attributes.md) tag
to set the size of the screen's display clip or passed as an argument to
[QueryOverscan()](autodocs-2.0/intuition-library-queryoverscan.md) to find their current overscan settings.

OSCAN_TEXT

```c
    This overscan region is based on user preference settings and
    indicates a display that is completely within the visible bounds of
    the monitor. The [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) origin is set to the upper left corner of the
    text overscan rectangle which is the highest leftmost point known to
    be visible on the physical display.  This position is set by the user
    through the Overscan Preferences editor.  All screen positions and
    display clips are relative to this origin.
```
OSCAN_STANDARD

    The edges of OSCAN_STANDARD display are also based on user
    preferences and are set to be just outside the visible bounds of the
    monitor.  OSCAN_STANDARD provides the smallest possible display that
    will fill the entire screen with no border around it.  Parts of the
    display created with OSCAN_STANDARD may not be visible to the user.
OSCAN_MAX

    Create the largest display fully supported by Intuition and the
    graphics library.  This is the largest size for which all enclosed
    sizes and positions are legal.  Parts of the display created with
    OSCAN_MAX may not be visible to the user.
OSCAN_VIDEO

```c
    Create the largest display, restricted by the hardware.  This is the
    only legal size and position that is possibly (but not necessarily)
    larger than OSCAN_MAX.  You must use the exact size and position
    specified.  OSCAN_VIDEO does not support variable left edge, top edge
    positioning.  Parts of the display created with OSCAN_VIDEO may not
    be visible to the user.
```
If custom clipping is required, a display clip may be explicitly specified
using the [SA_DClip](libraries/3-custom-screen-functions-screen-attributes.md) tag and a [Rectangle](libraries/29-graphics-library-and-text-does-the-text-fit.md) structure specification.  This
custom rectangle must fit within the OSCAN_MAX rectangle, offset included.
It is not permitted to specify custom rectangles whose values are in
between OSCAN_MAX and OSCAN_VIDEO, nor is it permitted to specify
rectangles larger than OSCAN_VIDEO.  For an example of how to open a
centered overscan screen based on user preferences, see the
module/[screen.c](libraries/devices-modules-screen-c.md) listing in the IFF Appendix of the Amiga ROM Kernel
Reference Manual: Devices.

Use the Graphics library call VideoControl() to find the true display clip
of a screen.  See the Graphics [Autodocs](autodocs-2.0/graphics-library-videocontrol.md) and the chapter
"[Graphics Primitives](libraries/27-mode-specification-viewport-interface.md)" for more information on VideoControl().  The
[ViewPortExtra](autodocs-2.0/includes-graphics-view-h.md) structure contains the display clip information.

If any dimension of a screen is not equal to the equivalent display clip
dimension, then the screen may be scrolled. If the screen's dimensions are
smaller than the display clip, then the screen may be positioned within
the display clip. If the screen is larger than the display clip, then it
may be positioned such that any part of the screen is visible.

AutoScroll may be activated by setting the tag [SA_AutoScroll](libraries/3-custom-screen-functions-screen-attributes.md). Screens will
only scroll when they are the active screen. Activate a window in the
screen to make the screen active.


```c
    About the Default Display Clip.
    -------------------------------
    The default display clip for a screen is the entire screen, that
    is, the rectangle starting from the upper left corner of the screen
    and ending at the lower right corner of the screen.  This display
    clip is only used if the application does not specify [SA_Overscan](libraries/3-custom-screen-functions-screen-attributes.md) or
    [SA_DClip](libraries/3-custom-screen-functions-screen-attributes.md).  When using this default display clip the screen will not
    scroll as the screen exactly fits into the clipping region.
```
When opening a window in an overscanned screen, it is often useful to open
it relative to the visible part of the screen rather than relative to the
entire screen.  Use [QueryOverscan()](autodocs-2.0/intuition-library-queryoverscan.md) to find the overscan region and where
the screen is positioned relative to it.


```c
    LONG QueryOverscan(ULONG displayID,
                       struct Rectangle *rect, WORD overscanType )
```
This example was taken from the chapter "Intuition Windows" in the section
"[A Display Sized Window Example](libraries/4-window-dimensions-a-display-sized-window-example.md)". The [complete example](libraries/lib-examples-visiblewindow-c.md) is reproduced
there.


/* this technique returns the text overscan rectangle of the screen that
** we are opening on.  If you really need the actual value set into the
** display clip of the screen, use the VideoControl() command of the
** graphics library to return a copy of the ViewPortExtra structure.  See
** the Graphics library chapter and Autodocs for more details.
**
** GetVPModeID() is a graphics call...
*/

screen_modeID = GetVPModeID(&(pub_screen->ViewPort))))
if (screen_modeID != INVALID_ID)

```c
    {
    if ( QueryOverscan(screen_modeID, &rect, OSCAN_TEXT) )
        {
        /* if this screen's origin is up or to the left of the */
        /* view origin then move the window down and to the right */
        left = max(0, -pub_screen->LeftEdge);
        top  = max(0, -pub_screen->TopEdge);

        /* get width and height from size of display clip */
        width  = rect.MaxX - rect.MinX + 1;
        height = rect.MaxY - rect.MinY + 1;

        /* adjust height for pulled-down screen (only show visible part) */
        if (pub_screen->TopEdge > 0)
            height -= pub_screen->TopEdge;

        /* ensure that window fits on screen */
        height = min(height, pub_screen->Height);
        width  = min(width,  pub_screen->Width);

        /* make sure window is at least minimum size */
        width  = max(width,  MIN_WINDOW_WIDTH);
        height = max(height, MIN_WINDOW_HEIGHT);
        }
    }
```

---

## See Also

- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [QueryOverscan — intuition.library](../autodocs/intuition.library.md#queryoverscan)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
