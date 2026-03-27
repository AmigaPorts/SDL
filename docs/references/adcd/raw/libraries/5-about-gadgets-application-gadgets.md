# 5 / About Gadgets / Application Gadgets


Application gadgets imitate real life controls: they are the switches,
knobs, handles and buttons of the Intuition environment.  Gadgets can be
created with almost any imaginable type of imagery and function.  Visual
imagery for gadgets can combine text with hand drawn imagery or lines of
multiple colors.

A gadget is created by declaring and initializing a Gadget structure as
defined in <intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line215)>.  See the "[Gadget Structure](../Libraries_Manual_guide/node0149.html)" section
later in this chapter for more details.

Gadgets always appear in a window or requester.  All windows and
requesters keep a list of the gadgets they contain.  Gadgets can be added
when the window or requester is opened, or they can be added or removed
from the window or requester after it is open.

As with other types of input events, Intuition notifies your application
about gadget activity by sending a message to your window's I/O channels:
the IDCMP ([Window.UserPort](../Libraries_Manual_guide/node01D6.html#line16)) or the console device.  The message is sent as
an Intuition [IntuiMessage](../Libraries_Manual_guide/node01D9.html) structure.  The [Class](../Libraries_Manual_guide/node01D9.html#line28) field of this structure is
set to [IDCMP_GADGETDOWN](../Libraries_Manual_guide/node01DD.html) or [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) with the [IAddress](../Libraries_Manual_guide/node01D9.html#line73) field set to
the address of the [Gadget](../Libraries_Manual_guide/node0149.html) that was activated.  (See the chapter on
"[Intuition Input and Output Methods](../Libraries_Manual_guide/node01DD.html)" for details.)

Application gadgets can go anywhere in windows or requesters, including in
the borders, and can be any size or shape.  When application gadgets are
placed into the window's border at the time the window is opened,
Intuition will adjust the border size accordingly.  Application gadgets
are not supported in screens (although this may be simulated by placing
the gadget in a [backdrop](../Libraries_Manual_guide/node0114.html) window).

Gadget size can be fixed, or can change relative to the window size.
Gadget position can be set relative to either the top or bottom border,
and either the left or right border of the window, allowing the gadget to
move with a border as the window is sized.

This flexibility provides the application designer the freedom to create
gadgets that mimic real devices, such as light switches or joysticks, as
well as the freedom to create controls that satisfy the unique needs of
the application.

 [A Simple Gadget Example](../Libraries_Manual_guide/node0595.html) 

