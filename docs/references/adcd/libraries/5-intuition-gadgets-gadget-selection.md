---
title: 5 Intuition Gadgets / Gadget Selection
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-gadget-selection
functions: []
libraries: []
---

# 5 Intuition Gadgets / Gadget Selection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The user operates a gadget by pressing the select button while the mouse
pointer is within the gadget's select box.  Intuition provides two ways of
notifying your program about the user operating a gadget.  If your
application needs immediate notification when the gadget is chosen, set
the [GACT_IMMEDIATE](libraries/5-gadget-structure-gadget-activation-flags.md) flag in the gadget's [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field.  Intuition will
send an [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) message to the window's [UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md) when it detects
the mouse select button being pressed on the gadget.

If the application needs notification when the gadget is released, i.e.,
when the user releases the mouse select button, set the [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md)
(for "release verify") flag in the gadget's [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field.  For [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md)
gadgets, Intuition will send an [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message to the window's
[UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md) when the mouse select button is released over a GACT_RELVERIFY
gadget.  The program will only receive the IDCMP_GADGETUP message if the
user still has the pointer positioned over the select box of the gadget
when the mouse select button is released.

If the user moves the mouse out of the gadget's select box before
releasing the mouse button an [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) event will be sent with a
code of SELECTUP.  This indicates the user's desire to not proceed with
the action.  [Boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets that are [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) allow the user a
chance to cancel a selection by rolling the mouse off of the gadget before
releasing the select button.

[String](libraries/5-intuition-gadgets-string-gadget-type.md) gadgets have a slightly different behavior, in that they remain
active after the mouse button has been released.  The gadget remains
active until Return or Enter is pressed, the user tabs to the next or
previous gadget, another window becomes active or the user chooses another
object with the mouse.  An [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message is only sent for
[GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) string gadgets if the user ends the gadget interaction
through the Return, Enter or (if activated) one of the tab keys.

[GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadgets send [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) events even if the
mouse button is released when the pointer is not positioned over the
select box of the gadget.

Gadgets can specify both the [GACT_IMMEDIATE](libraries/5-gadget-structure-gadget-activation-flags.md) and [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) activation
types, in which case, the program will receive both [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) and
[IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) messages.

