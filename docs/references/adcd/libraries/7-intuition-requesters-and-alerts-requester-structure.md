---
title: 7 Intuition Requesters and Alerts / Requester Structure
manual: libraries
chapter: libraries
section: 7-intuition-requesters-and-alerts-requester-structure
functions: [InitRequester]
libraries: [intuition.library]
---

# 7 Intuition Requesters and Alerts / Requester Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Unused fields in the Requester structure should be initialized to NULL or
zero before using the structure.  For global data that is pre-initialized,
be sure to set all unused fields to zero.  For dynamically allocated
structures, allocate the storage with the MEMF_CLEAR flag, or call the
[InitRequester()](libraries/7-true-requesters-creating-application-requesters.md) function to clear the structure.


```c
    Requesters are Initialized According to Their Type.
    ---------------------------------------------------
    See "[Rendering Requesters](libraries/7-true-requesters-rendering-requesters.md)" and "[Gadgets in Requesters](libraries/7-true-requesters-gadgets-in-requesters.md)" above for
    information about how the initialization of the structure differs
    according to how the requester is rendered.
```
The specification for a Requester structure, defined in
<intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>, is as follows.


```c
    struct Requester
        {
        struct Requester *OlderRequest;
        WORD LeftEdge, TopEdge;
        WORD Width, Height;
        WORD RelLeft, RelTop;
        struct Gadget *ReqGadget;
        struct Border *ReqBorder;
        struct IntuiText *ReqText;
        UWORD Flags;
        UBYTE BackFill;
        struct Layer *ReqLayer;
        UBYTE ReqPad1[32];
        struct BitMap *ImageBMap;
        struct Window *RWindow;
        struct Image  *ReqImage;
        UBYTE ReqPad2[32];
        };
```
Here are the meanings of the fields in the Requester structure:

OlderRequest

    For system use, initialize to NULL.
LeftEdge, TopEdge

    The location of the requester relative to the upper left corner of
    the window.  These values must be set if the POINTREL flag is not
    set.  Use RelLeft and RelTop for POINTREL requesters.
Width, Height

    These fields describe the size of the entire requester rectangle,
    containing all the text and gadgets.
RelLeft, RelTop

```c
    These values are only used if the POINTREL flag in the requester's
    Flags field is set.

    If the requester is a [double menu](libraries/7-true-requesters-double-menu-requesters.md) requester and POINTREL is set then
    these values contain the relative offset of the requester's upper
    left corner from the current pointer position.

    If the requester is not a [double menu](libraries/7-true-requesters-double-menu-requesters.md) requester and POINTREL is set,
    then these values contain the relative offset of the requester's
    center from the center of the window that the requester is to be
    displayed in.  For example, using POINTREL with a requester which is
    not a double menu requester with RelLeft and RelTop of zero will
    center the requester in the window.  The requester is centered within
    the inner part of the window, that is, within the inside edge of the
    window's borders.

    If the requester is POINTREL and part of the containing box will
    appear out of the window, Intuition will adjust the requester so that
    the upper left corner is visible and as much of the remaining box as
    possible is visible.  The adjustment attempts to maintain the
    requester within the window's borders, not within the window's
    bounding box.
```
ReqGadget

```c
    This field is a pointer to the first in a linked list of [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
    structures.  [GTYP_REQGADGET](libraries/5-intuition-gadgets-gadget-structure.md) must be specified in the [GadgetType](libraries/5-intuition-gadgets-gadget-structure.md)s
    field of all Gadget structures that are used in a requester.  Take
    care not to specify gadgets that extend beyond the Requester
    rectangle specified by the Width and Height fields, as Intuition does
    no boundary checking.

    For requesters with custom imagery, where PREDRAWN is set, ReqGadget
    points to a valid list of gadgets, which are real gadgets in every
    way except that the gadget text and imagery information are ignored
    (and can be NULL).  The select box, highlighting, and gadget type
    data are still used.  Try to maintain a close correspondence between
    the gadgets' select boxes and the supplied imagery.

    String Gadgets and Pre-drawn Requesters.
    ----------------------------------------
    Intuition will not render string gadget text in a predrawn requester.
    The application must use other rendering means than the predrawn
    bitmap if it wishes to use string gadgets with a requester.
```
ReqBorder

```c
    This field is a pointer to an optional linked list of [Border](libraries/8-creating-borders-border-structure-definition.md)
    structures for drawing lines around and within the requester.  The
    lines specified in the border may go anywhere in the requester; they
    are not confined to the perimeter of the requester.

    For requesters with custom imagery, where PREDRAWN is set, this
    variable is ignored and may be set to NULL.
```
ReqText

```c
    This field is a pointer to an optional linked list of [IntuiText](libraries/8-creating-text-intuitext-structure.md)
    structures containing text for the requester.  This is for general
    text in the requester.

    For requesters with custom imagery, where PREDRAWN is set, this
    variable is ignored and can be set to NULL.
```
Flags

```c
    The following flags may be specified for the Requester:

    POINTREL
        Specify POINTREL to indicate that the requester is to appear in
        a relative rather than a fixed position.

        For [double menu](libraries/7-true-requesters-double-menu-requesters.md) requesters, the position is relative to the
        pointer. Otherwise, the position of POINTREL requesters is
        relative to the center of the window.

        See the discussion of RelLeft and RelTop, above.

    PREDRAWN
        Specify PREDRAWN if a custom [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure is supplied for
        the requester and ImageBMap points to the structure.

    NOISYREQ
        Normally, when a requester is active, any gadget, menu, mouse
        and keyboard events within the parent window are blocked.
        Specify the NOISYREQ requester flag to allow keyboard and mouse
        button IDCMP events to be posted, even though the requester is
        active in the parent window.

        If the NOISYREQ requester flag is set, the application will
        receive [IDCMP_RAWKEY](libraries/9-event-message-classes-and-flags-other-flags.md), [IDCMP_VANILLAKEY](libraries/9-event-message-classes-and-flags-other-flags.md) and [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md)
        events.  Note that with NOISYREQ set, IDCMP_MOUSEBUTTON events
        will also be sent when the user clicks on any of the blocked
        gadgets in the parent window.

        Although the reporting of mouse button events depends on
        NOISYREQ, mouse movement events do not.  [IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) events
        are reported if the window flag [WFLG_REPORTMOUSE](libraries/4-window-attributes-boolean-window-attribute-tags.md) is set in the
        parent window, or if one of the requester gadgets is down and
        has the [GACT_FOLLOWMOUSE](libraries/5-gadget-structure-gadget-activation-flags.md) flag set.  This is true even if the
        requester is a [double menu](libraries/7-true-requesters-double-menu-requesters.md) requester.

    USEREQIMAGE
        Render the linked list of images pointed to by ReqImage after
        rendering the BackFill color but before gadgets and text.

    NOREQBACKFILL
        Do not backfill the requester with the BackFill pen.

    In addition, Intuition uses these flags in the Requester:

    REQOFFWINDOW
        Set by Intuition if the requester is currently active but is
        positioned off window.

    REQACTIVE
        This flag is set or cleared by Intuition as the requester is
        posted and removed.  The active requester is indicated by the
        value of [Window](libraries/4-intuition-windows-the-window-structure.md).FirstRequest.

    SYSREQUEST
        This flag is set by Intuition if this is a [system](libraries/7-intuition-requesters-and-alerts-system-requesters.md) generated
        requester. Since the system will never create a [true](libraries/7-intuition-requesters-and-alerts-true-requesters.md) requester
        in an application window, the application should not be
        concerned with this flag.
```
BackFill

    BackFill is the pen number to be used to fill the rectangle of the
    requester before any drawing takes place.  For requesters with custom
    imagery, where PREDRAWN is set, or for requesters with NOREQBACKFILL
    set, this variable is ignored.
ReqLayer

```c
    While the requester is active, this contains the address of the [Layer](libraries/30-layers-the-layer-structure.md)
    structure used in rendering the requester.
```
ImageBMap

    A pointer to the custom bitmap for this requester.  If this requester
    is not PREDRAWN, Intuition ignores this variable.

    When a custom bitmap is supplied, the PREDRAWN flag in the
    requester's Flags field must be set.
RWindow

    Reserved for system use.
ReqImage

```c
    A pointer to a list of [Image](libraries/8-creating-images-image-structure.md) structures used to create imagery within
    the requester.  Intuition ignores this field if the flag USEREQIMAGE
    is not set.  This imagery is automatically redrawn by Intuition each
    time the requester needs refreshing.  The images are drawn after
    filling with the BackFill pen, but before the gadgets and text.
```
ReqPad1, ReqPad2

    Reserved for system use.

---

## See Also

- [InitRequester — intuition.library](../autodocs/intuition.library.md#initrequester)
