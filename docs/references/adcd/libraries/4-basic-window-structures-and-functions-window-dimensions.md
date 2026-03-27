---
title: 4 / Basic Window Structures and Functions / Window Dimensions
manual: libraries
chapter: libraries
section: 4-basic-window-structures-and-functions-window-dimensions
functions: [OpenWindowTagList]
libraries: [intuition.library]
---

# 4 / Basic Window Structures and Functions / Window Dimensions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The initial position and dimensions of the window are defined in the
[OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call.  These values undergo error checking before the
window is actually opened on the screen.  If the dimensions are too big,
the window will fail to open.  (Or, you can use the [WA_AutoAdjust](libraries/4-window-attributes-boolean-window-attribute-tags.md) tag if
you want Intuition to move or size your window to fit.)

Maximum and minimum size values may also be defined, but are not required
If the window does not have a sizing gadget.  In setting these dimensions,
bear in mind the horizontal and vertical resolutions of the screen in
which the window will open.

The maximum dimensions of the window are unsigned values and may legally
be set to the maximum by using the value 0xFFFF, better expressed as "~0".
Using this value for the maximum dimensions allows the window to be sized
to the full screen.

 [A Display Sized Window Example](libraries/4-window-dimensions-a-display-sized-window-example.md) 

---

## See Also

- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
