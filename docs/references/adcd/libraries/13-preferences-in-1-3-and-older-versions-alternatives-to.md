---
title: 13 / Preferences in 1.3 and Older Versions / Alternatives to SetPrefs
manual: libraries
chapter: libraries
section: 13-preferences-in-1-3-and-older-versions-alternatives-to
functions: [LoadRGB4, SetFont, SetPointer]
libraries: [graphics.library, intuition.library]
---

# 13 / Preferences in 1.3 and Older Versions / Alternatives to SetPrefs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Since the Amiga is a multitasking system, it is rarely correct for a
single Amiga application to modify the user's system-wide Preferences.
Instead, use methods such as the following to modify only your own
application's appearance or behavior.

  * Custom screen applications can control their own display mode,

```c
    resolution, palette, and fonts. Use functions such a [LoadRGB4()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md) to
    change your own screen's palette, and [SetFont()](libraries/29-the-text-function-choosing-the-font.md) to change your own
    screen and window fonts. Workbench applications should never change
    the attributes of the user's Workbench.
```
  * The mouse pointer for a window may be changed with [SetPointer()](libraries/10-the-pointer-custom-pointer.md).

  * Serial device settings can be changed with the command

    SDCMD_SETPARAMS.
  * Printer device settings may be changed by altering the printer's copy

    of the Preferences structure when you have the printer open. Note
    that Amiga applications should only keep the printer open while they
    are printing.  This allows other applications to print, and also
    allows user changes to Printer Preferences to take effect.
See the [Inutition](libraries/user-interface-libraries.md) and [graphics](libraries/graphics-libraries.md) chapters of this manual, and the
"[Printer Device](devices/10-printer-device.md)" and "[Serial Device](devices/12-serial-device.md)" chapters of the Amiga ROM Kernel
Reference Manual: Devices for more information.

---

## See Also

- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
- [SetPointer — intuition.library](../autodocs/intuition.library.md#setpointer)
