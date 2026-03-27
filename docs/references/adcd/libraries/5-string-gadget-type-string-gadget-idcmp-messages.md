---
title: 5 / String Gadget Type / String Gadget IDCMP Messages
manual: libraries
chapter: libraries
section: 5-string-gadget-type-string-gadget-idcmp-messages
functions: []
libraries: []
---

# 5 / String Gadget Type / String Gadget IDCMP Messages

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If the application has specified the [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) activation flag, it
will be sent an [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message when the gadget is properly
deactivated.  This happens when Return or Enter is pressed, when tabbing
to the next [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget (where supported), and when a custom string
editing hook returns [SGA_END](libraries/5-custom-string-editing-actions-definitions.md).

The gadget may become inactive without the application receiving an
[IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message.  This will happen if the user performs some other
operation with the mouse or if another window is activated.  The gadget
may still contain updated, valid information even though the
IDCMP_GADGETUP message was not received.

