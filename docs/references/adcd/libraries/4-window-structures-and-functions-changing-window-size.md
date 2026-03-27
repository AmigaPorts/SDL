---
title: 4 / Window Structures and Functions / Changing Window Size Limits
manual: libraries
chapter: libraries
section: 4-window-structures-and-functions-changing-window-size
functions: [WindowLimits]
libraries: [intuition.library]
---

# 4 / Window Structures and Functions / Changing Window Size Limits

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To change the sizing limits after the window has been opened, call
[WindowLimits()](autodocs-2.0/intuition-library-windowlimits.md) with the new values.

   BOOL WindowLimits( struct Window *window, long widthMin, long heightMin,

```c
                      unsigned long widthMax, unsigned long heightMax );
```
To maintain the current dimension, set the corresponding argument to 0.
Out of range numbers are ignored.  If the user is currently sizing the
window, new limits take effect after the user releases the select button.

---

## See Also

- [WindowLimits — intuition.library](../autodocs/intuition.library.md#windowlimits)
