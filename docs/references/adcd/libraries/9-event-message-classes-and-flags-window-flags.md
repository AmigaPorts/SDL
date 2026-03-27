---
title: 9 / / Event Message Classes and Flags / Window Flags
manual: libraries
chapter: libraries
section: 9-event-message-classes-and-flags-window-flags
functions: [BeginRefresh, EndRefresh, ScrollRaster]
libraries: [graphics.library, intuition.library]
---

# 9 / / Event Message Classes and Flags / Window Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IDCMP_NEWSIZE

    Intuition sends this message after the user has resized the window.
    After receiving this, the program can examine the size variables in
    the window structure to discover the new size of the window.  The
    message is sent, even if the size of the window did not actually
    change.
IDCMP_REFRESHWINDOW

```c
    This message is sent whenever the window needs refreshing.  This flag
    makes sense only with windows that have a refresh type of
    [WA_SimpleRefresh](libraries/4-window-attributes-boolean-window-attribute-tags.md) or [WA_SmartRefresh](libraries/4-window-attributes-boolean-window-attribute-tags.md).

    As a minimum, the application must call [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) and
    [EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) for the window after receiving an IDCMP_REFRESHWINDOW
    event.  Create the window with the [WA_NoCareRefresh](libraries/4-window-attributes-boolean-window-attribute-tags.md) attribute if you
    do not want to manage these events.  See the "[Intuition Windows](libraries/4-preserving-the-window-display-refreshing-intuition-windows.md)"
    chapter for details.

    Most of the graphics library calls used for display output are
    compatible with Intuition, with the exception of ScrollRaster().
    Intuition will not send an IDCMP_REFRESHWINDOW event when damage is
    caused to a window by [ScrollRaster()](libraries/27-data-move-operations-scrolling-a-sub-rectangle-of-a.md).  This may happen in a simple
    refresh window which is partially obscured by another window--the
    region that scrolls out from behind the front window will be damaged,
    but the window will receive no notification.  Check the LAYERREFRESH
    bit in the [Layer](libraries/30-layers-the-layer-structure.md) structure Flags field to see if damage did happen as
    a result of ScrollRaster().
```
IDCMP_SIZEVERIFY

```c
    Set this flag if the program must complete some operation before the
    user sizes the window.  When the user sizes the window, Intuition
    sends an IDCMP_SIZEVERIFY message to the application and then waits
    until the program replies before allowing the user to size the
    window.  See the "[Verification Functions](libraries/9-idcmp-flags-verification-functions.md)" section below for some
    things to consider when using this flag.
```
IDCMP_ACTIVEWINDOW and IDCMP_INACTIVEWINDOW

    Set these flags to discover when the window becomes activated or
    deactivated.

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [ScrollRaster — graphics.library](../autodocs/graphics.library.md#scrollraster)
