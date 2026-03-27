# 5 Intuition Gadgets / Boolean Gadget Type


A boolean gadget gets yes/no or on/off responses from the user.  To make a
boolean gadget set the [GadgetType](../Libraries_Manual_guide/node0149.html#line58) field to [GTYP_BOOLGADGET](../Libraries_Manual_guide/node0149.html#line63) in the [Gadget](../Libraries_Manual_guide/node0149.html)
structure.

Boolean gadgets come in two types: hit-select and toggle-select.
Hit-select gadgets are only active while the user holds down the mouse
select button.  When the button is released, the gadget is unhighlighted.
Action buttons, such as "OK" and "Cancel", are hit-select.

Toggle-select gadgets become selected when the user clicks them.  To
"unselect" the gadget, the user has to click the gadget again.  Switches,
such as a checkbox, are toggle-select.

Set the [GACT_TOGGLESELECT](../Libraries_Manual_guide/node014B.html#line2) flag in the [Activation](../Libraries_Manual_guide/node0149.html#line53) field of the [Gadget](../Libraries_Manual_guide/node0149.html)
structure to create a toggle-select gadget.

The [GFLG_SELECTED](../Libraries_Manual_guide/node014A.html#line63) flag in [Gadget](../Libraries_Manual_guide/node0149.html) structure [Flags](../Libraries_Manual_guide/node0149.html#line48) field determines the
initial and current on/off selected state of a toggle-select gadget.  If
GFLG_SELECTED is set, the gadget will be highlighted.  The application can
set the GFLG_SELECTED flag before submitting the gadget to Intuition.  The
program may examine this flag at any time to determine the current state
of this gadget.

Try to make the imagery for toggle-select gadgets visually distinct from
hit-select gadgets so that their operation can be determined by the user
through visual inspection.

 [Masked Boolean Gadgets](../Libraries_Manual_guide/node014D.html)    [BoolInfo Structure](../Libraries_Manual_guide/node014E.html)    [Mutual Exclude](../Libraries_Manual_guide/node014F.html) 

