---
title: 7 / True Requesters / Requester Display Position
manual: libraries
chapter: libraries
section: 7-true-requesters-requester-display-position
functions: []
libraries: []
---

# 7 / True Requesters / Requester Display Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The location of [true](libraries/7-intuition-requesters-and-alerts-true-requesters.md) requesters may be specified in one of three ways.
The requester may either be a constant location, which is an offset from
the top left corner of the window; a location relative to the current
location of the pointer; or a location relative to the center of the
window.

To display the requester as an offset from the upper left corner of the
window, initialize the [TopEdge](libraries/7-intuition-requesters-and-alerts-requester-structure.md) and [LeftEdge](libraries/7-intuition-requesters-and-alerts-requester-structure.md) variables and clear the
[POINTREL](libraries/7-intuition-requesters-and-alerts-requester-structure.md) flag.  This will create a requester with a fixed position
relative to the upper left corner for both normal requesters and
[double menu](libraries/7-true-requesters-double-menu-requesters.md) requesters.

Displaying the requester relative to the pointer can get the user's
attention immediately and closely associates the requester with whatever
the user was doing just before the requester was displayed in the window.
However, only [double menu](libraries/7-true-requesters-double-menu-requesters.md) requesters may be positioned relative to the
pointer position.  See below for more information on double menu
requesters.

Requesters that are not [double menu](libraries/7-true-requesters-double-menu-requesters.md) requesters may be positioned relative
to the center of the window on systems running Release 2 or a later
version of the OS.  This is done by setting the [POINTREL](libraries/7-intuition-requesters-and-alerts-requester-structure.md) flag and filling
in the relative top and left of the gadget.  Setting [RelTop](libraries/7-intuition-requesters-and-alerts-requester-structure.md) and [RelLeft](libraries/7-intuition-requesters-and-alerts-requester-structure.md) to
zero will center the requester in the window.  Positive values of RelTop
and RelLeft will move the requester down and to the right, negative values
will move it up and to the left.

