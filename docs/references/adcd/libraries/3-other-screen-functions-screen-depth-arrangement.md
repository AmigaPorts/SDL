---
title: 3 / Other Screen Functions / Screen Depth Arrangement
manual: libraries
chapter: libraries
section: 3-other-screen-functions-screen-depth-arrangement
functions: [ScreenToBack, ScreenToFront]
libraries: [intuition.library]
---

# 3 / Other Screen Functions / Screen Depth Arrangement

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[ScreenToFront()](autodocs-2.0/intuition-library-screentofront.md) and [ScreenToBack()](autodocs-2.0/intuition-library-screentoback.md) make a screen either the frontmost or
the backmost screen.  If an application needs to render into a screen
before the screen becomes visible to the user, the screen may be opened
behind all other screens and later moved to the front when ready with
ScreenToFront().


```c
    VOID ScreenToFront( struct Screen * )
    VOID ScreenToBack ( struct Screen * )
```
Depth control of screens is also available through the depth arrangement
gadget in the screen's title bar or through keyboard shortcuts.  The N key
with the Left-Amiga qualifier moves the Workbench screen to front.  The M
key with the Left-Amiga qualifier moves the frontmost screen to back.
Repeated selection of Left-Amiga-M will cycle through available screens.
These keys are processed through the keymap and will retain their value
even if the key location changes.

---

## See Also

- [ScreenToBack — intuition.library](../autodocs/intuition.library.md#screentoback)
- [ScreenToFront — intuition.library](../autodocs/intuition.library.md#screentofront)
