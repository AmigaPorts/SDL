# 15 / / / Implementing a Gadget's Keyboard Equivalent Behavior


Currently, GadTools does not process keyboard equivalents for gadgets.  It
is up to the application writer to implement the correct behavior,
normally by calling [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html) on the appropriate gadget.  For
some kinds of gadget, the behavior should be the same regardless of
whether the keyboard equivalent was pressed with or without the shift key.
For other gadgets, shifted and unshifted keystrokes will have different,
usually opposite, effects.

Here is the correct behavior for keyboard equivalents for each kind of
GadTools gadget:

Button Gadgets

    The keyboard equivalent should invoke the same function that clicking
    on the gadget does.  There is currently no way to highlight the
    button visuals programmatically when accessing the button through a
    keyboard equivalent.
Text-Entry and Number-Entry Gadgets

```c
    The keyboard equivalent should activate the gadget so the user may
    type into it.  Use Intuition's [ActivateGadget()](../Libraries_Manual_guide/node0167.html) call.
```
Checkbox Gadgets

```c
    The keyboard equivalent should toggle the state of the checkbox.  Use
    [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html) and the [GTCB_Checked](../Libraries_Manual_guide/node0262.html#line13) tag.
```
Mutually-Exclusive Gadgets

```c
    The unshifted keystroke should activate the next choice, wrapping
    around from the last to the first.  The shifted keystroke should
    activate the previous choice, wrapping around from the first to the
    last.  Use [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html) and the [GTMX_Active](../Libraries_Manual_guide/node0263.html#line23) tag.
```
Cycle Gadgets

```c
    The unshifted keystroke should activate the next choice, wrapping
    around from the last to the first.  The shifted keystroke should
    activate the previous choice, wrapping around from the first to the
    last.  Use [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html) and the [GTCY_Active](../Libraries_Manual_guide/node0264.html#line27) tag.
```
Slider Gadgets

```c
    The unshifted keystroke should increase the slider's level by one,
    stopping at the maximum, while the shifted keystroke should decrease
    the level by one, stopping at the minimum.  Use [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html)
    and the [GTSL_Level](../Libraries_Manual_guide/node0265.html#line14) tag.
```
Scroller Gadgets

```c
    The unshifted keystroke should increase the scroller's top by one,
    stopping at the maximum, while the shifted keystroke should decrease
    the scroller's top by one, stopping at the minimum.  Use
    [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html) and the [GTSC_Top](../Libraries_Manual_guide/node0266.html#line27) tag.
```
Listview Gadgets

```c
    The unshifted keystroke should cause the next entry in the list to
    become the selected one, stopping at the last entry, while the
    shifted keystroke should cause the previous entry in the list to
    become the selected one, stopping at the first entry.  Use
    [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html) and the [GTLV_Top](../Libraries_Manual_guide/node0267.html#line15) and [GTLV_Selected](../Libraries_Manual_guide/node0267.html#line38) tags.
```
Palette Gadgets

```c
    The unshifted keystroke should select the next color, wrapping around
    from the last to the first.  The shifted keystroke should activate
    the previous color, wrapping around from the first to the last.  Use
    [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html) and the [GTPA_Color](../Libraries_Manual_guide/node0268.html#line14) tag.
```
Text-Display and Number-Display Gadgets

    These kinds of GadTools gadget have no keyboard equivalents since
    they are not selectable.
Generic Gadgets

    Define appropriate keyboard functions based on the kinds of keyboard
    behavior defined for other GadTools kinds.
