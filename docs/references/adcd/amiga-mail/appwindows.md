---
title: AppWindows
manual: amiga-mail
chapter: amiga-mail
section: appwindows
functions: []
libraries: []
---

# AppWindows

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The workbench.library's AddAppWindow() call makes an application's
Intuition window into an AppWindow.  It has one parameter that is
different from the other AddApp calls, a window pointer.  The mywindow
field (from the prototype above) must point to an open Intuition window
that is on the Workbench screen.

The C source code example [AppWindow.c](amiga-mail/iv-59-appwindow-c.md) at the end of this article is a
simple example of how to create an AppWindow.

There are two interesting things to note about the AppWindow.  First,
because an AppWindow is still an Intuition window, an application can use
a Workbench AppWindow for any purpose it would need a normal Workbench
based window for. An application can render graphics and text in it,
process its IntuiMessages, or create menus for it.  Also, because
Workbench tells where on an AppWindow icons were dropped, an application
can use a small region of a window as a drop box rather than the entire
AppWindow.  A program can even have several drop boxes on the same window.
Using simple rendering routines, an application can draw the boxes so the
user can see where to drop icons.

