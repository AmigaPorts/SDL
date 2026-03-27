---
title: 5 Intuition Gadgets / Gadget Structure
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-gadget-structure
functions: []
libraries: []
---

# 5 Intuition Gadgets / Gadget Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here is the specification for the Gadget structure defined in
<intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>.  You create an instance of this structure for
each gadget you place in a window or requester:


```c
    struct Gadget
        {
        struct Gadget *NextGadget;
        WORD LeftEdge, TopEdge;
        WORD Width, Height;
        UWORD Flags;
        UWORD Activation;
        UWORD GadgetType;
        APTR GadgetRender;
        APTR SelectRender;
        struct IntuiText *GadgetText;
        LONG MutualExclude;
        APTR SpecialInfo;
        UWORD GadgetID;
        APTR UserData;
        };
```
NextGadget

    Applications may create lists of gadgets that may be added to a
    window or requester with a single instruction.  NextGadget is a
    pointer to the next gadget in the list.  The last gadget in the list
    should have a NextGadget value of NULL.

    When gadgets are added or removed, Intuition will modify the
    appropriate NextGadget fields to maintain a correctly linked list of
    gadgets for that window or requester.  However, removing one or more
    gadgets does not reset the last removed gadget's NextGadget field to
    NULL.
LeftEdge, TopEdge, Width, Height

```c
    These variables describe the location and dimensions of the select
    box of the gadget.  Both location and dimensions can be either
    absolute values or else relative to the edges and size of the window
    or requester that contains the gadget.

    LeftEdge and TopEdge are relative to one of the corners of the
    display element, according to how [GFLG_RELRIGHT](libraries/5-gadget-structure-gadget-flags.md) and [GFLG_RELBOTTOM](libraries/5-gadget-structure-gadget-flags.md)
    are set in the Flags variable (see below).

    Width and Height are either absolute dimensions or a negative
    increment to the width abd height of a requester or a window,
    according to to how the [GFLG_RELWIDTH](libraries/5-gadget-structure-gadget-flags.md) and [GFLG_RELHEIGHT](libraries/5-gadget-structure-gadget-flags.md) flags are
    set (see below).
```
Flags

```c
    The Flags field is shared by the program and Intuition.  See the
    section below on "[Gadget Flags](libraries/5-gadget-structure-gadget-flags.md)" for a complete description of all the
    flag bits.
```
Activation

```c
    This field is used for information about some gadget attributes.  See
    the "[Gadget Activation Flags](libraries/5-gadget-structure-gadget-activation-flags.md)" section below for a description of the
    various flags.
```
GadgetType

```c
    This field contains information about gadget type and in what sort of
    display element the gadget is to be displayed.  One of the following
    flags must be set to specify the type:

    GTYP_BOOLGADGET
        [Boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadget type.

    GTYP_STRGADGET
        [String](libraries/5-intuition-gadgets-string-gadget-type.md) gadget type.  For an [integer](libraries/5-string-gadget-type-integer-gadget-type.md) gadget, also set the
        [GACT_LONGINT](libraries/5-gadget-structure-gadget-activation-flags.md) flag.  See the "[Gadget Activation Flags](libraries/5-gadget-structure-gadget-activation-flags.md)" section
        below.

    GTYP_PROPGADGET
        [Proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget type.

    GTYP_CUSTOMGADGET
        Normally not set by the application.  Used by [custom](libraries/5-string-gadget-type-custom-gadgets.md) BOOPSI
        gadget types, discussed in the "[BOOPSI](libraries/12-boopsi-object-oriented-intuition-boopsi-gadgets.md)" chapter.

    The following gadget types may be set in addition to one of the above
    types.  None of the following types are required:

    GTYP_GZZGADGET
        If the gadget is placed in a [GimmeZeroZero](libraries/4-window-types-gimmezerozero-window-type.md) window, setting this
        flag will place the gadget in the border layer, out of the inner
        window.  If this flag is not set, the gadget will go into the
        inner window.  Do not set this bit if this gadget is not placed
        in a GimmeZeroZero window.

    GTYP_REQGADGET
        Set this bit if this gadget is placed in a requester.
```
GadgetRender

```c
    A pointer to the [Image](libraries/8-creating-images-image-structure.md) or [Border](libraries/8-creating-borders-border-structure-definition.md) structure containing the graphics
    imagery of this gadget.  If this field is set to NULL, no rendering
    will be done.

    If the graphics of this gadget are implemented with an [Image](libraries/8-creating-images-image-structure.md)
    structure, this field should contain a pointer to that structure and
    the [GFLG_GADGIMAGE](libraries/5-gadget-structure-gadget-flags.md) flag must be set.  If a [Border](libraries/8-creating-borders-border-structure-definition.md) structure is used,
    this field should contain a pointer to the Border structure, and the
    GFLG_GADGIMAGE bit must be cleared.
```
SelectRender

```c
    If the application does not use an alternate image for highlighting,
    set this field to NULL.  Otherwise, if the flag [GFLG_GADGHIMAGE](libraries/5-gadget-structure-gadget-flags.md) is
    set, this field must contain a pointer to an [Image](libraries/8-creating-images-image-structure.md) or [Border](libraries/8-creating-borders-border-structure-definition.md)
    structure.  The [GFLG_GADGIMAGE](libraries/5-gadget-structure-gadget-flags.md) flag determines the type of the
    rendering. Provide a pointer to an [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure to include a
    text component to the gadget.  Multiple IntuiText structures may be
    chained.  Set this field to NULL if the gadget has no associated text.
```
GadgetText

```c
    Provide a pointer to an [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure to include a text
    component to the gadget.  Multiple IntuiText structures may be
    chained.  Set this field to NULL if the gadget has no associated text.

    The offsets in the [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure are relative to the top left
    of the gadget's select box.
```
MutualExclude

```c
    This field is currently ignored by Intuition, but is reserved. Do not
    store information here. Starting with V36, if the GadgetType is
    GTYP_CUSTOMGADGET this field is used to point to a Hook for the
    [custom](libraries/5-string-gadget-type-custom-gadgets.md) gadget.
```
SpecialInfo

```c
    SpecialInfo contains a pointer to an extension structure which
    contains the special information needed by the gadget.

    If this is a [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget, this variable must contain a
    pointer to an instance of a [PropInfo](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) data structure. If this is a
    [string](libraries/5-intuition-gadgets-string-gadget-type.md) or [integer](libraries/5-string-gadget-type-integer-gadget-type.md) gadget, this variable must contain a pointer to an
    instance of a [StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md) data structure. If this is a [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadget
    with [GACT_BOOLEXTEND](libraries/5-gadget-structure-gadget-activation-flags.md) activation, this variable must contain a pointer
    to an instance of a [BoolInfo](libraries/5-boolean-gadget-type-boolinfo-structure.md) data structure. Otherwise, this variable
    is ignored.
```
GadgetID

    This variable is for application use and may contain any value.  It
    is often used to identify the specific gadget within an event
    processing loop.  This variable is ignored by Intuition.
UserData

    This variable is for application use and may contain any value.  It
    is often used as a pointer to a data block specific to the
    application or gadget.  This variable is ignored by Intuition.
 [Gadget Flags](libraries/5-gadget-structure-gadget-flags.md)    [Gadget Activation Flags](libraries/5-gadget-structure-gadget-activation-flags.md) 

