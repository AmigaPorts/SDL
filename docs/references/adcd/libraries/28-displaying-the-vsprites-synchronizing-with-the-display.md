---
title: 28 / / Displaying the VSprites / Synchronizing with the Display
manual: libraries
chapter: libraries
section: 28-displaying-the-vsprites-synchronizing-with-the-display
functions: [WaitTOF]
libraries: [graphics.library]
---

# 28 / / Displaying the VSprites / Synchronizing with the Display

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To synchronize application functions with the display, call the system
function [WaitTOF()](autodocs-2.0/graphics-library-waittof.md). WaitTOF() holds your task until the vertical-blanking
interval (blank area at the top of the screen) has begun.  At that time,
the system has retrieved the current Copper instruction list and is ready
to allow generation of a new list.


```c
    WaitTOF();
```
[WaitTOF()](autodocs-2.0/graphics-library-waittof.md) takes no arguments and returns no values.  It simply suspends
your task until the video beam is at the top of field.

---

## See Also

- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
