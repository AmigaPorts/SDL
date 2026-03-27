---
title: 9 / Intuition Input / Intuition as an Input Handler
manual: libraries
chapter: libraries
section: 9-intuition-input-intuition-as-an-input-handler
functions: []
libraries: []
---

# 9 / Intuition Input / Intuition as an Input Handler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Intuition is an input handler linked into the input stream, and it
monitors and modifies events that it receives.  The input arrives at
Intuition as a single stream of events.  These events are filtered,
altered, and enhanced by Intuition, then dispatched to windows as
appropriate, or passed down to input handlers lower in the chain.  If the
active window has a console attached to it, then it can receive the input
events that are still left in the stream, which can include some events
that Intuition played a role in forming.

Many kinds of input event undergo little conversion by Intuition.  For
instance, raw keyboard events are not modified by Intuition (with the
exception of a few keystrokes that have special meaning).  Other events
may produce differing results based on Intuition's view of the system. For
example, when the mouse select button is pressed, the event may become a
gadget down-press event, a window activation event, or it may remain a
simple button press, depending on the mouse position and the arrangement
of windows and screens.  Still other events are consumed by Intuition, and
the application is not directly notified.  An example would be when the
select button is pressed over a system gadget.

Intuition is also the originator of certain kinds of events.  For example,
a window-refreshing event is generated when Intuition discovers that part
of a window is in need of redrawing.  This might have resulted indirectly
from some other input (for example, the user might have dragged a window),
but not necessarily (the refresh might have been necessitated by a program
bringing a window to the front).

