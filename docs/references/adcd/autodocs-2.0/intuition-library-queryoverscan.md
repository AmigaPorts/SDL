---
title: intuition.library/QueryOverscan
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-queryoverscan
functions: [OpenScreen, OpenScreenTagList]
libraries: [intuition.library]
---

# intuition.library/QueryOverscan

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    QueryOverscan -- Inquire about a standard overscan region. (V36)
```
SYNOPSIS

```c
    success = QueryOverscan( DisplayID, Rect, OScanType )
    D0                       A0         A1    D0

    LONG QueryOverscan( ULONG, struct [Rectangle](autodocs-2.0/includes-graphics-gfx-h.md) *, WORD );
```
FUNCTION


```c
    This function fills in a rectangle with one of the system
    overscan dimensions, scaled appropriately for the mode of
    the DisplayID it is passed.

    There are three types of system overscan values:
    OSCAN_TEXT: completely visible, by user preference.  Used
      for Workbench screen and screen dimensions STDSCREENWIDTH
      and STDSCREENHEIGHT.  Left/Top is always 0,0.
    OSCAN_STANDARD: just beyond visible bounds of monitor, by
      user preference.  Left/Top may be negative.
    OSCAN_MAX: The largest region we can display, AND display
      any smaller region (see note below).
    OSCAN_VIDEO: The absolute largest region that the graphics.library
      can display.  This region must be used as-is.
```
INPUTS

```c
    DisplayID -- A 32-bit identifier for a display mode, as
      defined in [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md).

      NOTE: If you only intend to use one of the four standard
      overscan dimensions as is, and open your screen to exactly
      the DisplayClip dimensions, you can specify one of
      the OSCAN_ values in the [ExtNewScreen](autodocs-2.0/includes-intuition-screens-h.md) tag SA_StdDClip,
      and specify STDSCREENWIDTH and STDSCREENHEIGHT as the
      dimensions to more easily open up an overscanned screen
      (or use no [NewScreen](autodocs-2.0/includes-intuition-screens-h.md) in [OpenScreenTagList()](autodocs-2.0/intuition-library-openscreentaglist.md) and accept
      the default standard screen dimensions).

    Rect -- pointer to a [Rectangle](autodocs-2.0/includes-graphics-gfx-h.md) structure which this function
      will fill out with its return values.  Note that to convert
      a rectangle to a screen "Height" you do (MaxY - MinY + 1), and
      similarly for "Width."  The rectangle may be passed directly
      to [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md) as a DisplayClip region (SA_DClip).
```
RESULT

```c
    0 (FALSE) if the [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md) your [NewScreen](autodocs-2.0/includes-intuition-screens-h.md) requests
    does not exist.  Non-zero (TRUE) if it does.
```
BUGS

    Change in parameter V36.A17 might cause problems for some.
SEE ALSO

```c
    [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md), Intuition V36 update documentation
```

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
