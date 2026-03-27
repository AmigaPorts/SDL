---
title: 4 / / Refreshing Intuition Windows / Simple Refresh
manual: libraries
chapter: libraries
section: 4-refreshing-intuition-windows-simple-refresh
functions: []
libraries: []
---

# 4 / / Refreshing Intuition Windows / Simple Refresh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For a Simple Refresh window, only those pixels actually on-screen are
maintained by the system.  When part of a Simple Refresh window is
obscured, the imagery that was there is lost.  As well, any rendering into
obscured portions of such a window is discarded.

When part of the window is newly revealed (either because the window was
just made larger, or because that part used to be obscured by another
window), the application must refresh any rendering it wishes to appear
into that part.  The application will learn that refresh is needed because
Intuition sends an [IDCMP_REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) event.

