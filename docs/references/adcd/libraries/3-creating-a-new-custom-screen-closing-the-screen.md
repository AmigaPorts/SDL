---
title: 3 / / Creating A New Custom Screen / Closing the Screen
manual: libraries
chapter: libraries
section: 3-creating-a-new-custom-screen-closing-the-screen
functions: [CloseScreen]
libraries: [intuition.library]
---

# 3 / / Creating A New Custom Screen / Closing the Screen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When an application has finished using a screen, the memory that the
screen occupied should be returned to the system by calling [CloseScreen()](autodocs-2.0/intuition-library-closescreen.md).
Normally, an application should close only those screens that it created.
Under V34 and earlier versions of the OS, CloseScreen() returns no values.
Under Release 2, CloseScreen() returns a boolean value, TRUE for success
and FALSE for failure.  CloseScreen() can fail if the screen is [public](libraries/3-intuition-screens-public-screen-functions.md) and
another task is still using the screen.

---

## See Also

- [CloseScreen — intuition.library](../autodocs/intuition.library.md#closescreen)
