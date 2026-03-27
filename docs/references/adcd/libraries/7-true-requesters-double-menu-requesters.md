---
title: 7 / True Requesters / Double Menu Requesters
manual: libraries
chapter: libraries
section: 7-true-requesters-double-menu-requesters
functions: [ClearDMRequest, SetDMRequest]
libraries: [intuition.library]
---

# 7 / True Requesters / Double Menu Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A double menu requester is exactly like other requesters with one
exception: it is displayed only when the user double clicks the mouse menu
button.  Double menu requesters block input in exactly the same manner as
other [true](libraries/7-intuition-requesters-and-alerts-true-requesters.md) requesters.  A double menu requester is attached to a window by
calling [SetDMRequest()](autodocs-2.0/intuition-library-setdmrequest.md).


```c
    BOOL SetDMRequest( struct Window *window,
                       struct Requester *requester );
```
This call does not display the requester, it simply prepares it for
display.  The requester will be brought up when the user double clicks the
mouse menu button.  The parent window will receive [IDCMP_REQSET](libraries/7-true-requesters-idcmp-requester-features.md) and
[IDCMP_REQCLEAR](libraries/7-true-requesters-idcmp-requester-features.md) messages when the requester is added and removed.

To prevent the user from bringing up a double menu requester, unlink it
from the window by calling [ClearDMRequest()](autodocs-2.0/intuition-library-cleardmrequest.md).  If a double menu request is
set for a window, ClearDMRequest() should be called to remove the
requester before that window is closed.


```c
    BOOL ClearDMRequest( struct Window *window );
```
This function unlinks the requester from the window and disables the
ability of the user to bring it up.  [ClearDMRequest()](autodocs-2.0/intuition-library-cleardmrequest.md) will fail if the
double menu request is currently being displayed.

Double menu requesters can be positioned relative to the current mouse
pointer position.  For a mouse relative requester, specify [POINTREL](libraries/7-intuition-requesters-and-alerts-requester-structure.md) in the
[Flags](libraries/7-intuition-requesters-and-alerts-requester-structure.md) field and initialize the [RelLeft](libraries/7-intuition-requesters-and-alerts-requester-structure.md) and [RelTop](libraries/7-intuition-requesters-and-alerts-requester-structure.md) variables.  RelLeft and
RelTop describe the offset of the upper, left corner of the requester from
the pointer position at the time the requester is displayed.  These values
can be either negative or positive.

The values of [RelLeft](libraries/7-intuition-requesters-and-alerts-requester-structure.md) and [RelTop](libraries/7-intuition-requesters-and-alerts-requester-structure.md) are only advisory; the actual position
will be restricted such that the requester is entirely contained within
the borders of its parent window, if possible.  The actual top and left
positions are stored in the [TopEdge](libraries/7-intuition-requesters-and-alerts-requester-structure.md) and [LeftEdge](libraries/7-intuition-requesters-and-alerts-requester-structure.md) variables.

Positioning relative to the mouse pointer is possible only with double
menu requesters.  Setting [POINTREL](libraries/7-intuition-requesters-and-alerts-requester-structure.md) in a requester which is not a double
menu requester will position the requester relative to the center of the
window.

---

## See Also

- [ClearDMRequest — intuition.library](../autodocs/intuition.library.md#cleardmrequest)
- [SetDMRequest — intuition.library](../autodocs/intuition.library.md#setdmrequest)
