---
title: Opening Full Sized Windows
manual: amiga-mail
chapter: amiga-mail
section: opening-full-sized-windows
functions: [GetScreenData, LockPubScreen, OpenScreen, OpenWindow]
libraries: [intuition.library]
---

# Opening Full Sized Windows

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Because there is no guarantee that GetScreenData() will return the
correct screen resolution, programs can't use it to obtain the
dimensions needed to open a full sized window.  To get the correct
screen resolution of the Workbench screen, programs have to examine
the Height and Width fields of the Screen structure returned by
LockPubScreen().

To make supporting new and old versions of the operating system
easier, Intuition V36 offers a way to open screens and windows that is
compatible with previous versions of the Amiga OS.  Instead of
requiring the use of new functions to open V36 specific screens and
windows, the OpenWindow() and OpenScreen() functions each accept an
extended structure, ExtNewWindow and ExtNewScreen, respectively.
These structures allow the programmer to pass tags to the V36
OpenScreen() and OpenWindow() functions while remaining compatible
with older versions of these functions.  Older versions of Intuition
ignore the excess baggage at the end of the structure where the tags
are kept.  These tags are partially used in V35 (a 1.3 release) to
support the A2024 modes.  Note that the ExtNewScreen and ExtNewWindow
structures may be extended in the future, so programs must not assume
their size is static.

To use the "New Look", pass the SA_Pens tag and a pen array in
ExtNewScreen.  Using the New Look requires a little bit more
responsibility from an application.  Programs that aren't careful can
experience problems with the layout of graphics and gadgets in New
Look windows and screens.  For example, a lot of programs made
assumptions about the height of a window's title bar.  Under 1.3, this
didn't present much of a problem because the title bar height didn't
normally change.  Under 2.0, the user can choose system fonts, varying
the size of the title bar.  Graphics and gadgets rendered into the
application's window can write over the title bar if the application
isn't careful.

The example at the end of this article, [extscreen.c](amiga-mail/iv-17-extscreen-c.md), illustrates how
to open a screen and window under release 2.0, using 2.0 specific
features if they are available, while staying compatible with older
versions of the operating system.  This example will open a screen in
A2024 mode (under V37, V36, or V35) if the resources are available.

---

## See Also

- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
