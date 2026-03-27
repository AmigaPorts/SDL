---
title: 7 / System Requesters / Redirecting System Requesters
manual: libraries
chapter: libraries
section: 7-system-requesters-redirecting-system-requesters
functions: []
libraries: []
---

# 7 / System Requesters / Redirecting System Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A process can force the [system](libraries/7-intuition-requesters-and-alerts-system-requesters.md) requests which are caused by its actions to
appear on a custom screen by changing the pr_WindowPtr field of its
[Process](autodocs-2.0/includes-dos-dosextens-h.md) structure.  This field may be set to three values: zero, negative
one or a valid pointer to the [Window](libraries/4-intuition-windows-the-window-structure.md) structure of an open window.  If
pr_WindowPtr is set to zero, the request will appear on the default public
screen.  If pr_WindowPtr is set to negative one, the system request will
never appear and the return code will be as if the user had selected the
rightmost button (negative response).  If pr_WindowPtr is set to a valid
window pointer, then the request will appear on the same screen as the
window.

The original value of [pr_WindowPtr](autodocs-2.0/includes-dos-dosextens-h.md) should be cached and restored before
the window is closed.

