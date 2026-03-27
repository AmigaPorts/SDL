---
title: Opening Full Size Screens
manual: amiga-mail
chapter: amiga-mail
section: opening-full-size-screens
functions: [GetScreenData]
libraries: [intuition.library]
---

# Opening Full Size Screens

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Under pre-V36 versions of the operating system, a method commonly used
to open a screen according to user preference was to "clone" the
Workbench screen (to create a screen with the same resolution and view
mode as the Workbench screen).  Normally, applications called the
Intuition function GetScreenData() to learn the Workbench screen's
resolution and display mode.

Programmers should no longer rely on GetScreenData() to return the
actual resolution and display mode under release 2.0.  When asked
about the Workbench screen, the V2.0 GetScreenData() returns the video
mode of a Hires screen, or, if the screen is interlaced, a Hires
interlaced screen.  The dimensions GetScreenData() returns will be the
lesser of either the OSCAN_TEXT dimensions or the actual Workbench
screen dimensions.  This change to GetScreenData() prevents some
programs developed for 1.3 from opening full size screens and windows
under 2.0.  The change had to be made to avoid confusing programs that
couldn't handle the higher resolutions and new display modes that are
available in release 2.0.  For example, when GetScreenData() is called
on a system using a SuperHires interlaced Workbench screen, it returns
the dimensions and view mode of a Hires interlaced screen.  If
GetScreenData() had supplied the actual resolution instead, a program
that assumed the resolution could not be greater than 640x400 could be
severely crippled.  The exception to this rule is a system running in
one of the A2024 (or Hedley Hires) modes.  To remain compatible with
the V35 version of GetScreenData(), the release 2.0 version returns
the correct dimensions of a screen in A2024 mode.

Another method previously used to get information about the Workbench
screen was to look at the GfxBase->NormalDisplayRows and
GfxBase->NormalDisplayColumns fields.  As with GetScreenData(), these
fields contain the dimensions of a text overscan Hires (or Hires
interlace) screen.  Obviously, these fields should no longer be used
to obtain the actual dimensions of the Workbench screen.

To clone the Workbench screen under 2.0, lock the Workbench screen,
get the screen's display mode ID, and get the necessary display
information.  The article "[An Introduction to V36 Screens and Windows](amiga-mail/iv-3-an-introduction-to-v36-screens-and-windows.md)"
from the September/October 1990 issue of Amiga Mail contains the
example [CloneWB.c](amiga-mail/iv-3-clonewb-c.md) which illustrates cloning the Workbench screen
under release 2.0.  Any application that wants to clone the Workbench
screen should be prepared to handle any type of screen, because the
user can change the Workbench screen to any type of screen they
desire.

---

## See Also

- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
