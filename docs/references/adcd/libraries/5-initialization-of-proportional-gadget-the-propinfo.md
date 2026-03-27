---
title: 5 / / Initialization of Proportional Gadget / the PropInfo Structure
manual: libraries
chapter: libraries
section: 5-initialization-of-proportional-gadget-the-propinfo
functions: [NewModifyProp]
libraries: [intuition.library]
---

# 5 / / Initialization of Proportional Gadget / the PropInfo Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is the special data required by the [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget.


```c
    struct [PropInfo](autodocs-2.0/includes-intuition-intuition-h.md)
        {
        UWORD Flags;
        UWORD HorizPot;
        UWORD VertPot;
        UWORD HorizBody;
        UWORD VertBody;
        UWORD CWidth;
        UWORD CHeight;
        UWORD HPotRes, VPotRes;
        UWORD LeftBorder;
        UWORD TopBorder;
        };
```
Flags

```c
    In the Flags variable, the following flag bits are of interest:

    PROPBORDERLESS
        Set the PROPBORDERLESS flag to create a [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget
        without a border.

    AUTOKNOB
        Set the AUTOKNOB flag in the Flags field to use the [auto-knob](libraries/5-proportional-gadget-components-the-knob.md),
        otherwise the application must provide [knob](libraries/5-proportional-gadget-components-the-knob.md) imagery.

    FREEHORIZ and FREEVERT
        Set the FREEHORIZ flag to create a gadget that adjust
        left-to-right, set the FREEVERT flag for top-to-bottom movement.
        Both flags may be set in a single gadget.

    PROPNEWLOOK
        Set the PROPNEWLOOK flag to create a gadget with the new look.
        If this flag is not set, the gadget will be rendered using a V34
        compatible design.

    KNOBHIT
        The KNOBHIT flag is set by Intuition when this [knob](libraries/5-proportional-gadget-components-the-knob.md) is hit by
        the user.
```
HorizPot and VertPot

```c
    Initialize the [HorizPot](libraries/5-proportional-gadget-components-the-pot-variables.md) and [VertPot](libraries/5-proportional-gadget-components-the-pot-variables.md) variables to their starting
    values before the gadget is added to the system. The variables may be
    read by the application. The gadget must be removed before writing to
    these variables, or they may be modified with [NewModifyProp()](libraries/5-proportional-gadget-type-modifying-an-existing-gadget.md).
```
HorizBody and VertBody

```c
    Set the [HorizBody](libraries/5-proportional-gadget-components-the-body-variables.md) and [VertnBody](libraries/5-proportional-gadget-components-the-body-variables.md) variables to the desired increment. If
    there is no data to show or the total amount displayed is less than
    the area in which to display it, set the [body variables](libraries/5-proportional-gadget-components-the-body-variables.md) to the
    maximum, MAXBODY.
```
The remaining variables and flags are reserved for use by Intuition.

---

## See Also

- [NewModifyProp — intuition.library](../autodocs/intuition.library.md#newmodifyprop)
