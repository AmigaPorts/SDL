---
title: 9 / Intuition Input / IDCMP Events and the Input Focus
manual: libraries
chapter: libraries
section: 9-intuition-input-idcmp-events-and-the-input-focus
functions: []
libraries: []
---

# 9 / Intuition Input / IDCMP Events and the Input Focus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Although at any given time many applications may be waiting for input, in
most cases only the active application (the one with the currently active
window) will receive IDCMP messages.

Since the IDCMP messages are, in general, directed to a single window,
this window is said to have the input focus--the input from a variety of
sources is focused on this single location.

The active window is generally selected by the user, although it is
possible for applications to change the active window.  See the
"[Intuition Windows](libraries/4-communicating-with-intuition-the-idcmp-and-the-active.md)" chapter for information on selecting or setting the
active window.  Be aware that changing the active window will change the
input focus.  Usually this change is performed following user action--the
user selects a window with the mouse, or activates a new application.
Changes to the input focus without user control, such as activating
another window while the user is working in an application, may confuse
the user. Perform such changes with great care.

Not all events are sent only to the active IDCMP.  Some events, such as
"disk inserted," may be useful to many programs, so Intuition translates
these events into separate messages, one for each application.

