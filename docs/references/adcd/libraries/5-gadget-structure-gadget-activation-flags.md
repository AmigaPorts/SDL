---
title: 5 / Gadget Structure / Gadget Activation Flags
manual: libraries
chapter: libraries
section: 5-gadget-structure-gadget-activation-flags
functions: [EndRequest, OpenWindow, OpenWindowTagList]
libraries: [intuition.library]
---

# 5 / Gadget Structure / Gadget Activation Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These flags may be set in the [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.

GACT_TOGGLESELECT

```c
    This flag applies only to [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets, and tells Intuition that
    this is to be a toggle-select gadget, not a hit-select one.  Preset
    the selection state with the gadget flag [GFLG_SELECTED](libraries/5-gadget-structure-gadget-flags.md) (see above).
    The program may check if the gadget is in the selected state by
    examining the GFLG_SELECTED flag at any time.
```
GACT_IMMEDIATE

```c
    If this bit is set, the program will be sent an [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md)
    message when the gadget is first picked.  The message will be sent
    when the user presses the mouse select button.
```
GACT_RELVERIFY

```c
    This is short for "release verify."  If this bit is set, the program
    will be sent an [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message when the gadget is
    deactivated.  IDCMP_GADGETUP will be sent for [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets when
    the user releases the mouse select button while the pointer is over
    the select box, for [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadgets whenever the user releases
    the mouse select button (regardless of the pointer position), and for
    [string](libraries/5-intuition-gadgets-string-gadget-type.md) and [integer](libraries/5-string-gadget-type-integer-gadget-type.md) gadgets when the user completes the text entry by
    pressing return or tabbing to the next gadget (where supported).

    For [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets, if the user releases the mouse button while the
    pointer is outside of the gadget's select box [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) will not
    be generated.  Instead, the program will receive an
    [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) event with the SELECTUP code set.  For [string](libraries/5-intuition-gadgets-string-gadget-type.md)
    gadgets, if the user deactivates the gadget by clicking elsewhere, it
    may not be possible to detect.
```
GACT_ENDGADGET

```c
    This flag pertains only to gadgets attached to requesters.  If a
    gadget with the GACT_ENDGADGET flag set is chosen by the user the
    requester will be terminated as if the application had called the
    [EndRequest()](libraries/7-true-requesters-creating-application-requesters.md) function.

    See the chapter "[Intuition Requesters and Alerts](libraries/7-true-requesters-gadgets-in-requesters.md)," for more
    information about requester gadget considerations.
```
GACT_FOLLOWMOUSE


```c
    These flags may be set in the [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
    structure. As long as a gadget that has this flag set is active, the
    program will receive mouse position messages for each change of mouse
    position.  For [GTYP_BOOLGADGET](libraries/5-intuition-gadgets-gadget-structure.md) gadgets, GACT_RELVERIFY must also be
    set for the program to receive mouse events.
```
The following flags are used to place application gadgets into a specified
window border.  Intuition will adjust the size of a window's borders
appropriately provided these gadgets are set up with a call to
[OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md), [OpenWindowTags()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) or [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md).  Intuition knows to
refresh gadgets marked with these flags when the window border is changed,
e.g., when the window is activated.  For [GimmeZeroZero](libraries/4-window-types-gimmezerozero-window-type.md) windows, the
[GTYP_GZZGADGET](libraries/5-intuition-gadgets-gadget-structure.md) flag must also be set for border gadgets.

GACT_RIGHTBORDER

    If this flag is set, the gadget is placed in the right border of the
    window and the width and position of this gadget are used in deriving
    the width of the window's right border.
GACT_LEFTBORDER

    If this flag is set, the gadget is placed in the left border of the
    window and the width and position of this gadget are used in deriving
    the width of the window's left border.
GACT_TOPBORDER

    If this flag is set, the gadget is placed in the top border of the
    window and the height and position of this gadget are used in
    deriving the height of the window's top border.
GACT_BOTTOMBORDER


    If this flag is set, the gadget is placed in the bottom border of the
    window and the height and position of this gadget are used in
    deriving the height of the window's bottom border.
The following flags apply only to [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadgets:

GACT_STRINGCENTER

```c
    If this flag is set, the text in a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget is centered within
    the select box.
```
GACT_STRINGRIGHT

```c
    If this flag is set, the text in a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget is right justified
    within the select box.
```
GACT_STRINGLEFT

```c
    This "flag" has a value of zero.  By default, the text in a [string](libraries/5-intuition-gadgets-string-gadget-type.md)
    gadget is left justified within the select box.
```
GACT_LONGINT

```c
    If this flag is set, the user can construct a 32-bit signed integer
    value in a normal [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget. The input buffer of the string
    gadget must be initialized with an ASCII representation of the
    starting integer value.
```
GACT_ALTKEYMAP

```c
    These flags may be set in the [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
    structure.  A pointer to the keymap must be placed in the [StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md)
    structure variable [AltKeyMap](libraries/5-stringinfo-structure-gadget-key-mapping.md).
```
GACT_BOOLEXTEND

```c
    This flag applies only to [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets.  If this flag is set, then
    the boolean gadget has a [BoolInfo](libraries/5-boolean-gadget-type-boolinfo-structure.md) structure associated with it.  A
    pointer to the BoolInfo structure must be placed in the [SpecialInfo](libraries/5-intuition-gadgets-gadget-structure.md)
    field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.
```
GACT_STRINGEXTEND

```c
    This is an obsolete flag originally defined in V36.  It applies only
    to [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadgets and indicates that [StringInfo.Extension](libraries/5-string-gadget-type-stringinfo-structure.md) points to a
    valid [StringExtend](libraries/5-string-gadget-type-extended-string-gadgets.md) structure.  Although this flag works, it is not
    ignored prior to V36 as it should be in order to be backward
    compatible.  This flag is replaced by [GFLG_STRINGEXTEND](libraries/5-gadget-structure-gadget-flags.md) in V37.
    GFLG_STRINGEXTEND performs the same function and is properly ignored
    on systems prior to V36.
```

---

## See Also

- [EndRequest — intuition.library](../autodocs/intuition.library.md#endrequest)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
