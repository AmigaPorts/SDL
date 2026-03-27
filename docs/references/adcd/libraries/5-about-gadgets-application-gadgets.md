---
title: 5 / About Gadgets / Application Gadgets
manual: libraries
chapter: libraries
section: 5-about-gadgets-application-gadgets
functions: []
libraries: []
---

# 5 / About Gadgets / Application Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Application gadgets imitate real life controls: they are the switches,
knobs, handles and buttons of the Intuition environment.  Gadgets can be
created with almost any imaginable type of imagery and function.  Visual
imagery for gadgets can combine text with hand drawn imagery or lines of
multiple colors.

A gadget is created by declaring and initializing a Gadget structure as
defined in <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>.  See the "[Gadget Structure](libraries/5-intuition-gadgets-gadget-structure.md)" section
later in this chapter for more details.

Gadgets always appear in a window or requester.  All windows and
requesters keep a list of the gadgets they contain.  Gadgets can be added
when the window or requester is opened, or they can be added or removed
from the window or requester after it is open.

As with other types of input events, Intuition notifies your application
about gadget activity by sending a message to your window's I/O channels:
the IDCMP ([Window.UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md)) or the console device.  The message is sent as
an Intuition [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) structure.  The [Class](libraries/9-using-the-idcmp-intuimessages.md) field of this structure is
set to [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) or [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) with the [IAddress](libraries/9-using-the-idcmp-intuimessages.md) field set to
the address of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) that was activated.  (See the chapter on
"[Intuition Input and Output Methods](libraries/9-event-message-classes-and-flags-gadget-flags.md)" for details.)

Application gadgets can go anywhere in windows or requesters, including in
the borders, and can be any size or shape.  When application gadgets are
placed into the window's border at the time the window is opened,
Intuition will adjust the border size accordingly.  Application gadgets
are not supported in screens (although this may be simulated by placing
the gadget in a [backdrop](libraries/4-window-types-backdrop-window-type.md) window).

Gadget size can be fixed, or can change relative to the window size.
Gadget position can be set relative to either the top or bottom border,
and either the left or right border of the window, allowing the gadget to
move with a border as the window is sized.

This flexibility provides the application designer the freedom to create
gadgets that mimic real devices, such as light switches or joysticks, as
well as the freedom to create controls that satisfy the unique needs of
the application.

 [A Simple Gadget Example](libraries/lib-examples-simplegad-c.md) 

