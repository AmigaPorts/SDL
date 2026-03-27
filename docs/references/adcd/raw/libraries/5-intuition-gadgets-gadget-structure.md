# 5 Intuition Gadgets / Gadget Structure


Here is the specification for the Gadget structure defined in
<intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line215)>.  You create an instance of this structure for
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
    display element, according to how [GFLG_RELRIGHT](../Libraries_Manual_guide/node014A.html#line38) and [GFLG_RELBOTTOM](../Libraries_Manual_guide/node014A.html#line29)
    are set in the Flags variable (see below).

    Width and Height are either absolute dimensions or a negative
    increment to the width abd height of a requester or a window,
    according to to how the [GFLG_RELWIDTH](../Libraries_Manual_guide/node014A.html#line47) and [GFLG_RELHEIGHT](../Libraries_Manual_guide/node014A.html#line55) flags are
    set (see below).
```
Flags

```c
    The Flags field is shared by the program and Intuition.  See the
    section below on "[Gadget Flags](../Libraries_Manual_guide/node014A.html)" for a complete description of all the
    flag bits.
```
Activation

```c
    This field is used for information about some gadget attributes.  See
    the "[Gadget Activation Flags](../Libraries_Manual_guide/node014B.html)" section below for a description of the
    various flags.
```
GadgetType

```c
    This field contains information about gadget type and in what sort of
    display element the gadget is to be displayed.  One of the following
    flags must be set to specify the type:

    GTYP_BOOLGADGET
        [Boolean](../Libraries_Manual_guide/node014C.html) gadget type.

    GTYP_STRGADGET
        [String](../Libraries_Manual_guide/node0164.html) gadget type.  For an [integer](../Libraries_Manual_guide/node0165.html) gadget, also set the
        [GACT_LONGINT](../Libraries_Manual_guide/node014B.html#line91) flag.  See the "[Gadget Activation Flags](../Libraries_Manual_guide/node014B.html)" section
        below.

    GTYP_PROPGADGET
        [Proportional](../Libraries_Manual_guide/node0153.html) gadget type.

    GTYP_CUSTOMGADGET
        Normally not set by the application.  Used by [custom](../Libraries_Manual_guide/node0176.html) BOOPSI
        gadget types, discussed in the "[BOOPSI](../Libraries_Manual_guide/node0218.html)" chapter.

    The following gadget types may be set in addition to one of the above
    types.  None of the following types are required:

    GTYP_GZZGADGET
        If the gadget is placed in a [GimmeZeroZero](../Libraries_Manual_guide/node0116.html) window, setting this
        flag will place the gadget in the border layer, out of the inner
        window.  If this flag is not set, the gadget will go into the
        inner window.  Do not set this bit if this gadget is not placed
        in a GimmeZeroZero window.

    GTYP_REQGADGET
        Set this bit if this gadget is placed in a requester.
```
GadgetRender

```c
    A pointer to the [Image](../Libraries_Manual_guide/node01BA.html) or [Border](../Libraries_Manual_guide/node01C1.html) structure containing the graphics
    imagery of this gadget.  If this field is set to NULL, no rendering
    will be done.

    If the graphics of this gadget are implemented with an [Image](../Libraries_Manual_guide/node01BA.html)
    structure, this field should contain a pointer to that structure and
    the [GFLG_GADGIMAGE](../Libraries_Manual_guide/node014A.html#line23) flag must be set.  If a [Border](../Libraries_Manual_guide/node01C1.html) structure is used,
    this field should contain a pointer to the Border structure, and the
    GFLG_GADGIMAGE bit must be cleared.
```
SelectRender

```c
    If the application does not use an alternate image for highlighting,
    set this field to NULL.  Otherwise, if the flag [GFLG_GADGHIMAGE](../Libraries_Manual_guide/node014A.html#line16) is
    set, this field must contain a pointer to an [Image](../Libraries_Manual_guide/node01BA.html) or [Border](../Libraries_Manual_guide/node01C1.html)
    structure.  The [GFLG_GADGIMAGE](../Libraries_Manual_guide/node014A.html#line23) flag determines the type of the
    rendering. Provide a pointer to an [IntuiText](../Libraries_Manual_guide/node01C7.html) structure to include a
    text component to the gadget.  Multiple IntuiText structures may be
    chained.  Set this field to NULL if the gadget has no associated text.
```
GadgetText

```c
    Provide a pointer to an [IntuiText](../Libraries_Manual_guide/node01C7.html) structure to include a text
    component to the gadget.  Multiple IntuiText structures may be
    chained.  Set this field to NULL if the gadget has no associated text.

    The offsets in the [IntuiText](../Libraries_Manual_guide/node01C7.html) structure are relative to the top left
    of the gadget's select box.
```
MutualExclude

```c
    This field is currently ignored by Intuition, but is reserved. Do not
    store information here. Starting with V36, if the GadgetType is
    GTYP_CUSTOMGADGET this field is used to point to a Hook for the
    [custom](../Libraries_Manual_guide/node0176.html) gadget.
```
SpecialInfo

```c
    SpecialInfo contains a pointer to an extension structure which
    contains the special information needed by the gadget.

    If this is a [proportional](../Libraries_Manual_guide/node0153.html) gadget, this variable must contain a
    pointer to an instance of a [PropInfo](../Libraries_Manual_guide/node0161.html) data structure. If this is a
    [string](../Libraries_Manual_guide/node0164.html) or [integer](../Libraries_Manual_guide/node0165.html) gadget, this variable must contain a pointer to an
    instance of a [StringInfo](../Libraries_Manual_guide/node016B.html) data structure. If this is a [boolean](../Libraries_Manual_guide/node014C.html) gadget
    with [GACT_BOOLEXTEND](../Libraries_Manual_guide/node014B.html#line102) activation, this variable must contain a pointer
    to an instance of a [BoolInfo](../Libraries_Manual_guide/node014E.html) data structure. Otherwise, this variable
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
 [Gadget Flags](../Libraries_Manual_guide/node014A.html)    [Gadget Activation Flags](../Libraries_Manual_guide/node014B.html) 

