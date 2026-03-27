---
title: 15 / / The Kinds of GadTools Gadgets / Checkbox Gadgets
manual: libraries
chapter: libraries
section: 15-the-kinds-of-gadtools-gadgets-checkbox-gadgets
functions: []
libraries: []
---

# 15 / / The Kinds of GadTools Gadgets / Checkbox Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Checkboxes (CHECKBOX_KIND) are appropriate for presenting options which
may be turned on or off.  This kind of gadget consists of a raised box
which contains a checkmark if the option is selected or is blank if the
option is not selected.  Clicking on the box toggles the state of the
checkbox.

The width and height of a checkbox are currently fixed (to 26x11). If
variable-sized checkboxes are added in the future,  they will be done in a
compatible manner.  Currently the width and height specified in the
[NewGadget](libraries/15-gadtools-gadgets-the-newgadget-structure.md) structure are ignored.

The checkbox may be controlled with the following tags:

GTCB_Checked (BOOL)

```c
    Set this attribute to TRUE to set the gadget's state to checked.  Set
    it to FALSE to mark the gadget as unchecked.  The default is FALSE.
    (Create and set.)
```
GA_Disabled (BOOL)

```c
    Set this attribute to TRUE to disable the checkbox, to FALSE
    otherwise.  The default is FALSE.  (Create and set.)
```
When the user selects a checkbox, the program will receive an [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)
with a class of [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md).  As this gadget always toggles, the
program can easily track the state of the gadget.  Feel free to read the
[Gadget->Flags](libraries/5-intuition-gadgets-gadget-structure.md) [GFLG_SELECTED](libraries/5-gadget-structure-gadget-flags.md) bit.  Note, however, that the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure
itself is not synchronized to the IntuiMessages received.  If the user
clicks a second time, the GFLG_SELECTED bit can toggle again before the
program gets a chance to read it.  This is true of any of the dynamic
fields of the Gadget structure, and is worth being aware of, although only
rarely will an application have to account for it.

