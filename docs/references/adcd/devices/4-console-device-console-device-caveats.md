---
title: 4 Console Device / Console Device Caveats
manual: devices
chapter: devices
section: 4-console-device-console-device-caveats
functions: [ScrollRaster]
libraries: [graphics.library]
---

# 4 Console Device / Console Device Caveats

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   *  Only one console unit can be attached per window.  Sharing a console

      window must be done at a level higher than the device.
   *  Do not mix graphics.library calls with console rendering in the same

      areas of a window.  It is permissible to send console sequences to
      adjust the area in which console renders, and use graphics.library
      calls to render outside of the area console is using.
For example, do not render text with console sequences and scroll using
the graphics.library [ScrollRaster()](autodocs-2.0/graphics-library-scrollraster.md) function.

   *  The character map feature is private and cannot be accessed by the

      programmer.  Implementation details and behaviors of the character
      map my change in the future.
   *  Do not use an IDCMP with character mapped consoles.  All Intuition

      messages should be obtained via RAW INPUT EVENTS from the console
      device.

---

## See Also

- [ScrollRaster — graphics.library](../autodocs/graphics.library.md#scrollraster)
