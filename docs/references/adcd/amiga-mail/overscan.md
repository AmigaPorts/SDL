---
title: Overscan
manual: amiga-mail
chapter: amiga-mail
section: overscan
functions: [OpenScreenTagList, QueryOverscan]
libraries: [intuition.library]
---

# Overscan

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In release 2.0, Intuition fully supports video overscan.  There are
four standard overscan specifiers: OSCAN_TEXT, OSCAN_STANDARD,
OSCAN_MAX and OSCAN_VIDEO.  OSCAN_TEXT is based on user preference
settings and indicates a display which is within the visible bounds
of the monitor.  The dimensions of this type of overscan are used for
the Workbench screen and for the defaults for OpenScreenTagList(),
STDSCREENWIDTH and STDSCREENHEIGHT.  OVERSCAN_STANDARD is also based
on user preference settings.  The edges of an OVERSCAN_STANDARD
display are set by the user via Preferences to be just outside the
visible bounds of the monitor.  OSCAN_MAX is the largest display
fully supported by Intuition.  OSCAN_VIDEO is the largest display
region which, for a given display mode, can be reliably generated.
Note that OSCAN_VIDEO displays are not scrollable.

The Intuition function QueryOverscan() returns rectangle information
for the indicated overscan type of a particular display mode.  Using
the rectangle returned by QueryOverscan(), it is possible to
explicitly specify the offset and dimensions of the DisplayClip
region.  Note however that this custom rectangle must fit within the
OSCAN_MAX rectangle, offset included.  It is not permitted to specify
custom rectangles whose values are in between OSCAN_MAX and
OSCAN_VIDEO, nor is it permitted to specify rectangles larger than
OSCAN_VIDEO.

---

## See Also

- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
- [QueryOverscan — intuition.library](../autodocs/intuition.library.md#queryoverscan)
