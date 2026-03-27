# 5 / Gadget Structure / Gadget Activation Flags


These flags may be set in the [Activation](../Libraries_Manual_guide/node0149.html#line53) field of the [Gadget](../Libraries_Manual_guide/node0149.html) structure.

GACT_TOGGLESELECT

```c
    This flag applies only to [boolean](../Libraries_Manual_guide/node014C.html) gadgets, and tells Intuition that
    this is to be a toggle-select gadget, not a hit-select one.  Preset
    the selection state with the gadget flag [GFLG_SELECTED](../Libraries_Manual_guide/node014A.html#line63) (see above).
    The program may check if the gadget is in the selected state by
    examining the GFLG_SELECTED flag at any time.
```
GACT_IMMEDIATE

```c
    If this bit is set, the program will be sent an [IDCMP_GADGETDOWN](../Libraries_Manual_guide/node01DD.html)
    message when the gadget is first picked.  The message will be sent
    when the user presses the mouse select button.
```
GACT_RELVERIFY

```c
    This is short for "release verify."  If this bit is set, the program
    will be sent an [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) message when the gadget is
    deactivated.  IDCMP_GADGETUP will be sent for [boolean](../Libraries_Manual_guide/node014C.html) gadgets when
    the user releases the mouse select button while the pointer is over
    the select box, for [proportional](../Libraries_Manual_guide/node0153.html) gadgets whenever the user releases
    the mouse select button (regardless of the pointer position), and for
    [string](../Libraries_Manual_guide/node0164.html) and [integer](../Libraries_Manual_guide/node0165.html) gadgets when the user completes the text entry by
    pressing return or tabbing to the next gadget (where supported).

    For [boolean](../Libraries_Manual_guide/node014C.html) gadgets, if the user releases the mouse button while the
    pointer is outside of the gadget's select box [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) will not
    be generated.  Instead, the program will receive an
    [IDCMP_MOUSEBUTTONS](../Libraries_Manual_guide/node01DC.html) event with the SELECTUP code set.  For [string](../Libraries_Manual_guide/node0164.html)
    gadgets, if the user deactivates the gadget by clicking elsewhere, it
    may not be possible to detect.
```
GACT_ENDGADGET

```c
    This flag pertains only to gadgets attached to requesters.  If a
    gadget with the GACT_ENDGADGET flag set is chosen by the user the
    requester will be terminated as if the application had called the
    [EndRequest()](../Libraries_Manual_guide/node01A2.html#line24) function.

    See the chapter "[Intuition Requesters and Alerts](../Libraries_Manual_guide/node01A7.html)," for more
    information about requester gadget considerations.
```
GACT_FOLLOWMOUSE


```c
    These flags may be set in the [Activation](../Libraries_Manual_guide/node0149.html#line53) field of the [Gadget](../Libraries_Manual_guide/node0149.html)
    structure. As long as a gadget that has this flag set is active, the
    program will receive mouse position messages for each change of mouse
    position.  For [GTYP_BOOLGADGET](../Libraries_Manual_guide/node0149.html#line63) gadgets, GACT_RELVERIFY must also be
    set for the program to receive mouse events.
```
The following flags are used to place application gadgets into a specified
window border.  Intuition will adjust the size of a window's borders
appropriately provided these gadgets are set up with a call to
[OpenWindow()](../Libraries_Manual_guide/node0103.html), [OpenWindowTags()](../Libraries_Manual_guide/node0103.html) or [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html).  Intuition knows to
refresh gadgets marked with these flags when the window border is changed,
e.g., when the window is activated.  For [GimmeZeroZero](../Libraries_Manual_guide/node0116.html) windows, the
[GTYP_GZZGADGET](../Libraries_Manual_guide/node0149.html#line81) flag must also be set for border gadgets.

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
The following flags apply only to [string](../Libraries_Manual_guide/node0164.html) gadgets:

GACT_STRINGCENTER

```c
    If this flag is set, the text in a [string](../Libraries_Manual_guide/node0164.html) gadget is centered within
    the select box.
```
GACT_STRINGRIGHT

```c
    If this flag is set, the text in a [string](../Libraries_Manual_guide/node0164.html) gadget is right justified
    within the select box.
```
GACT_STRINGLEFT

```c
    This "flag" has a value of zero.  By default, the text in a [string](../Libraries_Manual_guide/node0164.html)
    gadget is left justified within the select box.
```
GACT_LONGINT

```c
    If this flag is set, the user can construct a 32-bit signed integer
    value in a normal [string](../Libraries_Manual_guide/node0164.html) gadget. The input buffer of the string
    gadget must be initialized with an ASCII representation of the
    starting integer value.
```
GACT_ALTKEYMAP

```c
    These flags may be set in the [Activation](../Libraries_Manual_guide/node0149.html#line53) field of the [Gadget](../Libraries_Manual_guide/node0149.html)
    structure.  A pointer to the keymap must be placed in the [StringInfo](../Libraries_Manual_guide/node016B.html)
    structure variable [AltKeyMap](../Libraries_Manual_guide/node016C.html).
```
GACT_BOOLEXTEND

```c
    This flag applies only to [boolean](../Libraries_Manual_guide/node014C.html) gadgets.  If this flag is set, then
    the boolean gadget has a [BoolInfo](../Libraries_Manual_guide/node014E.html) structure associated with it.  A
    pointer to the BoolInfo structure must be placed in the [SpecialInfo](../Libraries_Manual_guide/node0149.html#line125)
    field of the [Gadget](../Libraries_Manual_guide/node0149.html) structure.
```
GACT_STRINGEXTEND

```c
    This is an obsolete flag originally defined in V36.  It applies only
    to [string](../Libraries_Manual_guide/node0164.html) gadgets and indicates that [StringInfo.Extension](../Libraries_Manual_guide/node016B.html#line76) points to a
    valid [StringExtend](../Libraries_Manual_guide/node016D.html) structure.  Although this flag works, it is not
    ignored prior to V36 as it should be in order to be backward
    compatible.  This flag is replaced by [GFLG_STRINGEXTEND](../Libraries_Manual_guide/node014A.html#line81) in V37.
    GFLG_STRINGEXTEND performs the same function and is properly ignored
    on systems prior to V36.
```
