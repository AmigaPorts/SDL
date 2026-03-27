---
title: 15 / / / Implementing a Gadget's Keyboard Equivalent Behavior
manual: libraries
chapter: libraries
section: 15-implementing-a-gadget-s-keyboard-equivalent-behavior
functions: [ActivateGadget]
libraries: [intuition.library]
---

# 15 / / / Implementing a Gadget's Keyboard Equivalent Behavior

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Currently, GadTools does not process keyboard equivalents for gadgets.  It
is up to the application writer to implement the correct behavior,
normally by calling [GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md) on the appropriate gadget.  For
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
    type into it.  Use Intuition's [ActivateGadget()](libraries/5-string-gadget-type-program-control-of-string-gadgets.md) call.
```
Checkbox Gadgets

```c
    The keyboard equivalent should toggle the state of the checkbox.  Use
    [GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md) and the [GTCB_Checked](libraries/15-the-kinds-of-gadtools-gadgets-checkbox-gadgets.md) tag.
```
Mutually-Exclusive Gadgets

```c
    The unshifted keystroke should activate the next choice, wrapping
    around from the last to the first.  The shifted keystroke should
    activate the previous choice, wrapping around from the first to the
    last.  Use [GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md) and the [GTMX_Active](libraries/15-the-kinds-of-gadtools-gadgets-mutually-exclusive-gadgets.md) tag.
```
Cycle Gadgets

```c
    The unshifted keystroke should activate the next choice, wrapping
    around from the last to the first.  The shifted keystroke should
    activate the previous choice, wrapping around from the first to the
    last.  Use [GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md) and the [GTCY_Active](libraries/15-the-kinds-of-gadtools-gadgets-cycle-gadgets.md) tag.
```
Slider Gadgets

```c
    The unshifted keystroke should increase the slider's level by one,
    stopping at the maximum, while the shifted keystroke should decrease
    the level by one, stopping at the minimum.  Use [GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md)
    and the [GTSL_Level](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md) tag.
```
Scroller Gadgets

```c
    The unshifted keystroke should increase the scroller's top by one,
    stopping at the maximum, while the shifted keystroke should decrease
    the scroller's top by one, stopping at the minimum.  Use
    [GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md) and the [GTSC_Top](libraries/15-the-kinds-of-gadtools-gadgets-scroller-gadgets.md) tag.
```
Listview Gadgets

```c
    The unshifted keystroke should cause the next entry in the list to
    become the selected one, stopping at the last entry, while the
    shifted keystroke should cause the previous entry in the list to
    become the selected one, stopping at the first entry.  Use
    [GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md) and the [GTLV_Top](libraries/15-the-kinds-of-gadtools-gadgets-listview-gadgets.md) and [GTLV_Selected](libraries/15-the-kinds-of-gadtools-gadgets-listview-gadgets.md) tags.
```
Palette Gadgets

```c
    The unshifted keystroke should select the next color, wrapping around
    from the last to the first.  The shifted keystroke should activate
    the previous color, wrapping around from the first to the last.  Use
    [GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md) and the [GTPA_Color](libraries/15-the-kinds-of-gadtools-gadgets-palette-gadgets.md) tag.
```
Text-Display and Number-Display Gadgets

    These kinds of GadTools gadget have no keyboard equivalents since
    they are not selectable.
Generic Gadgets

    Define appropriate keyboard functions based on the kinds of keyboard
    behavior defined for other GadTools kinds.

---

## See Also

- [ActivateGadget — intuition.library](../autodocs/intuition.library.md#activategadget)
