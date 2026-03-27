# 5 / String Gadget Type / String Gadget IDCMP Messages


If the application has specified the [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) activation flag, it
will be sent an [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) message when the gadget is properly
deactivated.  This happens when Return or Enter is pressed, when tabbing
to the next [string](../Libraries_Manual_guide/node0164.html) gadget (where supported), and when a custom string
editing hook returns [SGA_END](../Libraries_Manual_guide/node0171.html#line5).

The gadget may become inactive without the application receiving an
[IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) message.  This will happen if the user performs some other
operation with the mouse or if another window is activated.  The gadget
may still contain updated, valid information even though the
IDCMP_GADGETUP message was not received.

