# 15 / / The Kinds of GadTools Gadgets / Checkbox Gadgets


Checkboxes (CHECKBOX_KIND) are appropriate for presenting options which
may be turned on or off.  This kind of gadget consists of a raised box
which contains a checkmark if the option is selected or is blank if the
option is not selected.  Clicking on the box toggles the state of the
checkbox.

The width and height of a checkbox are currently fixed (to 26x11). If
variable-sized checkboxes are added in the future,  they will be done in a
compatible manner.  Currently the width and height specified in the
[NewGadget](../Libraries_Manual_guide/node0259.html) structure are ignored.

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
When the user selects a checkbox, the program will receive an [IntuiMessage](../Libraries_Manual_guide/node01D9.html)
with a class of [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6).  As this gadget always toggles, the
program can easily track the state of the gadget.  Feel free to read the
[Gadget->Flags](../Libraries_Manual_guide/node0149.html#line48) [GFLG_SELECTED](../Libraries_Manual_guide/node014A.html#line63) bit.  Note, however, that the [Gadget](../Libraries_Manual_guide/node0149.html) structure
itself is not synchronized to the IntuiMessages received.  If the user
clicks a second time, the GFLG_SELECTED bit can toggle again before the
program gets a chance to read it.  This is true of any of the dynamic
fields of the Gadget structure, and is worth being aware of, although only
rarely will an application have to account for it.

