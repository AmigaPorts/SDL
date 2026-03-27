# 5 Intuition Gadgets / Gadget Selection


The user operates a gadget by pressing the select button while the mouse
pointer is within the gadget's select box.  Intuition provides two ways of
notifying your program about the user operating a gadget.  If your
application needs immediate notification when the gadget is chosen, set
the [GACT_IMMEDIATE](../Libraries_Manual_guide/node014B.html#line9) flag in the gadget's [Activation](../Libraries_Manual_guide/node0149.html#line53) field.  Intuition will
send an [IDCMP_GADGETDOWN](../Libraries_Manual_guide/node01DD.html) message to the window's [UserPort](../Libraries_Manual_guide/node01D6.html#line16) when it detects
the mouse select button being pressed on the gadget.

If the application needs notification when the gadget is released, i.e.,
when the user releases the mouse select button, set the [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14)
(for "release verify") flag in the gadget's [Activation](../Libraries_Manual_guide/node0149.html#line53) field.  For [boolean](../Libraries_Manual_guide/node014C.html)
gadgets, Intuition will send an [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) message to the window's
[UserPort](../Libraries_Manual_guide/node01D6.html#line16) when the mouse select button is released over a GACT_RELVERIFY
gadget.  The program will only receive the IDCMP_GADGETUP message if the
user still has the pointer positioned over the select box of the gadget
when the mouse select button is released.

If the user moves the mouse out of the gadget's select box before
releasing the mouse button an [IDCMP_MOUSEBUTTONS](../Libraries_Manual_guide/node01DC.html) event will be sent with a
code of SELECTUP.  This indicates the user's desire to not proceed with
the action.  [Boolean](../Libraries_Manual_guide/node014C.html) gadgets that are [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) allow the user a
chance to cancel a selection by rolling the mouse off of the gadget before
releasing the select button.

[String](../Libraries_Manual_guide/node0164.html) gadgets have a slightly different behavior, in that they remain
active after the mouse button has been released.  The gadget remains
active until Return or Enter is pressed, the user tabs to the next or
previous gadget, another window becomes active or the user chooses another
object with the mouse.  An [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) message is only sent for
[GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) string gadgets if the user ends the gadget interaction
through the Return, Enter or (if activated) one of the tab keys.

[GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) [proportional](../Libraries_Manual_guide/node0153.html) gadgets send [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) events even if the
mouse button is released when the pointer is not positioned over the
select box of the gadget.

Gadgets can specify both the [GACT_IMMEDIATE](../Libraries_Manual_guide/node014B.html#line9) and [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) activation
types, in which case, the program will receive both [IDCMP_GADGETDOWN](../Libraries_Manual_guide/node01DD.html) and
[IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) messages.

