---
title: 7 / True Requesters / Requester I/O
manual: libraries
chapter: libraries
section: 7-true-requesters-requester-i-o
functions: [DisplayBeep]
libraries: [intuition.library]
---

# 7 / True Requesters / Requester I/O

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

So long as a requester is active in a window, the only gadgets that can be
used are those that are in the requester, plus all of the window's system
gadgets except for the close gadget (i.e., the drag bar, size gadget,
depth gadget, and zoom gadget).  A requester also makes the menus of the
parent window inaccessible.  Additionally, mouse button and keyboard
events will be blocked (unless the requester's [NOISYREQ](libraries/7-intuition-requesters-and-alerts-requester-structure.md) flag is set; see
"[Requester Structure](libraries/7-intuition-requesters-and-alerts-requester-structure.md)" below).  Mouse movement events, if enabled in the
parent window (with [WFLG_REPORTMOUSE](libraries/4-window-attributes-boolean-window-attribute-tags.md)), are not blocked.

Requesters do not have their own IDCMP message ports.  Instead, events for
a requester are sent to the IDCMP port of the requester's parent window
([Window.UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md)).  Since the window's menus and application gadgets are
inaccessible, no IDCMP events will be sent for them.

Even though the window containing the requester is blocked for input, the
user can work in another application or even in a different window of the
same application without satisfying the requester.  Only input to the
parent window is blocked by a requester.

Output is not blocked by a requester so nothing prevents the application
from writing to the window.  Be aware, however, that the requester
obscures part of the display and cannot be moved within the window so this
may limit the usefulness of any output you send to the parent window.
There are several ways to monitor the comings and goings of requesters
that allow the program to know if requesters are currently displayed in a
given window.  See "[IDCMP Requester Features](libraries/7-true-requesters-idcmp-requester-features.md)" below.

The information displayed in a requester is placed in its own layer, so it
does not overwrite the information in the window.  Output to the window
while the requester is displayed will not change the requester's display,
it will go into the window's layer.  The requester's layer is clipped to
the window's boundaries, so the data in the requester is only visible if
the window is large enough to allow for the complete display of that data.

The requester will remain in the window and input will remain blocked
until the user satisfies the request or the application removes the
requester.  Applications can set up some or all of the gadgets in the
requester to automatically terminate the requester when the gadget is
selected.  This allows the requester to be removed from the window by user
action.  The application may also remove requesters from the window based
on some event internal to the program.

Multiple requesters may be nested in a single window.  Such requesters
must be satisfied in the reverse order in which they were posted; the last
requester to be displayed must be satisfied first.  Input will not be
restored to a previous requester until all later requesters are satisfied.

Note that the application may not bring up a limitless number of
requesters in a window.  Each requester creates a new layer for rendering
in its window and the system currently has a limit of ten layers per
window.  Normal windows use one layer for the window rendering,
[GimmeZeroZero](libraries/4-window-types-gimmezerozero-window-type.md) windows use a second layer for the border rendering.  This
leaves a maximum of eight or nine simultaneous requesters open in a window
at any given time.

If the requester is being brought up only to display an error message, the
application may want to use a less intrusive method of bringing the error
to the user's attention than a requester.  Requesters interrupt the flow
of the user's work, and force them to respond before continuing.

As an alternative to bringing up an error requester, the application could
flash the screen instead with Intuition's [DisplayBeep()](libraries/3-other-screen-functions-miscellaneous-screen-functions.md) function.  This
allows the application to notify the user of an error that is not serious
enough to warrant a requester and to which the user does not really need
to respond.  For more information, see the description of DisplayBeep() in
the "[Intuition Screens](libraries/3-other-screen-functions-miscellaneous-screen-functions.md)" chapter.

---

## See Also

- [DisplayBeep — intuition.library](../autodocs/intuition.library.md#displaybeep)
