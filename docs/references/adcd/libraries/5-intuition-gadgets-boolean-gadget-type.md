---
title: 5 Intuition Gadgets / Boolean Gadget Type
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-boolean-gadget-type
functions: []
libraries: []
---

# 5 Intuition Gadgets / Boolean Gadget Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A boolean gadget gets yes/no or on/off responses from the user.  To make a
boolean gadget set the [GadgetType](libraries/5-intuition-gadgets-gadget-structure.md) field to [GTYP_BOOLGADGET](libraries/5-intuition-gadgets-gadget-structure.md) in the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
structure.

Boolean gadgets come in two types: hit-select and toggle-select.
Hit-select gadgets are only active while the user holds down the mouse
select button.  When the button is released, the gadget is unhighlighted.
Action buttons, such as "OK" and "Cancel", are hit-select.

Toggle-select gadgets become selected when the user clicks them.  To
"unselect" the gadget, the user has to click the gadget again.  Switches,
such as a checkbox, are toggle-select.

Set the [GACT_TOGGLESELECT](libraries/5-gadget-structure-gadget-activation-flags.md) flag in the [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
structure to create a toggle-select gadget.

The [GFLG_SELECTED](libraries/5-gadget-structure-gadget-flags.md) flag in [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure [Flags](libraries/5-intuition-gadgets-gadget-structure.md) field determines the
initial and current on/off selected state of a toggle-select gadget.  If
GFLG_SELECTED is set, the gadget will be highlighted.  The application can
set the GFLG_SELECTED flag before submitting the gadget to Intuition.  The
program may examine this flag at any time to determine the current state
of this gadget.

Try to make the imagery for toggle-select gadgets visually distinct from
hit-select gadgets so that their operation can be determined by the user
through visual inspection.

 [Masked Boolean Gadgets](libraries/5-boolean-gadget-type-masked-boolean-gadgets.md)    [BoolInfo Structure](libraries/5-boolean-gadget-type-boolinfo-structure.md)    [Mutual Exclude](libraries/5-boolean-gadget-type-mutual-exclude.md) 

