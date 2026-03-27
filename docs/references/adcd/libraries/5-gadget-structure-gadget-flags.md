---
title: 5 / Gadget Structure / Gadget Flags
manual: libraries
chapter: libraries
section: 5-gadget-structure-gadget-flags
functions: [OffGadget, OnGadget]
libraries: [intuition.library]
---

# 5 / Gadget Structure / Gadget Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are the flags that can be set in the [Flags](libraries/5-intuition-gadgets-gadget-structure.md) variable of the
[Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.  There are four highlighting methods to choose from.
These determine how the gadget imagery will be changed when the gadget is
selected.  One of these four flags must be set.

GFLG_GADGHNONE

    Set this flag for no highlighting.
GFLG_GADGHCOMP

    This flag chooses highlighting by complementing all of the bits
    contained within the gadget's select box.
GFLG_GADGHBOX

    This flag chooses highlighting by drawing a complemented box around
    the gadget's select box.
GFLG_GADGHIMAGE


    Set this flag to indicate highlighting with an alternate image.
In addition to the highlighting flags, these other values may be set in
the [Flags](libraries/5-intuition-gadgets-gadget-structure.md) field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.

GFLG_GADGIMAGE

```c
    If the gadget has a graphic, and it is implemented with an [Image](libraries/8-creating-images-image-structure.md)
    structure, set this bit.  If the graphic is implemented with a [Border](libraries/8-creating-borders-border-structure-definition.md)
    structure, make sure this bit is clear.  This bit is also used by
    [SelectRender](libraries/5-intuition-gadgets-gadget-structure.md) to determine the rendering type.
```
GFLG_RELBOTTOM

```c
    Set this flag if the gadget's [TopEdge](libraries/5-intuition-gadgets-gadget-structure.md) variable describes an offset
    relative to the bottom of the display element (window or requester)
    containing it.  A GFLG_RELBOTTOM gadget moves automatically as its
    window is made taller or shorter.  Clear this flag if TopEdge is
    relative to the top of the display element.  If GFLG_RELBOTTOM is
    set, TopEdge should contain a negative value, which will position it
    up from the bottom of the display element.
```
GFLG_RELRIGHT

```c
    Set this flag if the gadget's [LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md) variable describes an offset
    relative to the right edge of the display element containing it.  A
    GFLG_RELRIGHT gadget moves automatically as its window is made wider
    or narrower.  Clear this flag if LeftEdge is relative to the left
    edge of the display element.  If GFLG_RELRIGHT is set, LeftEdge
    should contain a negative value, which will position the gadget left
    of the right edge of the display element.
```
GFLG_RELWIDTH

```c
    Set this flag for "relative gadget width."  If this flag is set, the
    width of the gadget's select box changes automatically whenever the
    width of its window changes.  When using GFLG_RELWIDTH, set the
    gadget's [Width](libraries/5-intuition-gadgets-gadget-structure.md) to a negative value.  This value will be added to the
    width of the gadget's display element (window or requester) to
    determine the actual width of the gadget's select box.
```
GFLG_RELHEIGHT

```c
    Set this flag for "relative gadget height."  If this flag is set, the
    height of the gadget's select box changes automatically whenever the
    height of its window changes.  When using GFLG_RELHEIGHT, set the
    gadget's [Height](libraries/5-intuition-gadgets-gadget-structure.md) to a negative value.  This value will be added to the
    height of the gadget's display element (window or requester) to
    determine the actual height of the gadget's select box.
```
GFLG_SELECTED

```c
    Use this flag to preset the on/off selected state for a toggle-select
    [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadget (see the discussion of the [GACT_TOGGLESELCT](libraries/5-gadget-structure-gadget-activation-flags.md) flag
    below).  If the flag is set, the gadget is initially selected and is
    highlighted.  If the flag is clear, the gadget starts off in the
    unselected state.  To change the selection state of one or more
    gadgets, change their GFLG_SELECTED bits as appropriate, add them
    back and refresh them.  However, see the section on
    "[Updating a Gadget's Imagery](libraries/5-gadget-refreshing-by-the-program-updating-a-gadget-s.md)" for important details.
```
GFLG_DISABLED

```c
    If this flag is set, this gadget is disabled. To enable or disable a
    gadget after the gadget has been added to the system, call the
    routines [OnGadget()](libraries/5-intuition-gadgets-gadget-enabling-and-disabling.md) and [OffGadget()](libraries/5-intuition-gadgets-gadget-enabling-and-disabling.md).  The GFLG_DISABLED flag can be
    programmatically altered in much the same way as GFLG_SELECTED above.
    See the section on "[Updating a Gadget's Imagery](libraries/5-gadget-refreshing-by-the-program-updating-a-gadget-s.md)" for important
    details.
```
GFLG_STRINGEXTEND

```c
    The [StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md) [Extension](libraries/5-string-gadget-type-stringinfo-structure.md) field points to a valid [StringExtend](libraries/5-string-gadget-type-extended-string-gadgets.md)
    structure.  Use of this structure is described later in the
    "[String Gadget Type](libraries/5-string-gadget-type-stringinfo-structure.md)" section of this chapter.  This flag is ignored
    prior to V37, see [GACT_STRINGEXTEND](libraries/5-gadget-structure-gadget-activation-flags.md) for the same functionality under
    V36.  Note that GACT_STRINGEXTEND is not ignored prior to V36 and
    should only be set in V36 or later systems.
```
GFLG_TABCYCLE

```c
    This string participates in cycling activation with the tab (or
    shifted tab) key.  If this flag is set, the tab keys will de-activate
    this gadget as if the Return or Enter keys had been pressed, sending
    an [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message to the application, then the next [string](libraries/5-intuition-gadgets-string-gadget-type.md)
    gadget with GFLG_TABCYCLE set will be activated.  Shifted tab
    activates the previous gadget.
```

---

## See Also

- [OffGadget — intuition.library](../autodocs/intuition.library.md#offgadget)
- [OnGadget — intuition.library](../autodocs/intuition.library.md#ongadget)
