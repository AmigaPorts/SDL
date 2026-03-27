---
title: 14 / / Icon Library Data Structures / The Gadget Structure
manual: libraries
chapter: libraries
section: 14-icon-library-data-structures-the-gadget-structure
functions: []
libraries: []
---

# 14 / / Icon Library Data Structures / The Gadget Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To hold the icon's image, Workbench uses an Intuition [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure,
defined in <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>.  Workbench restricts some of the
values of the gadget.  All unused fields should be set to 0 or NULL.  The
Intuition gadget structure members that Workbench icons use are listed
below.


```c
    Gadget Names in Assembly Language Are Different.
    ------------------------------------------------
    The assembly language version of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure has leading
    "gg_" for each variable name.
```
[Width](libraries/5-intuition-gadgets-gadget-structure.md)

```c
    This is the width (in pixels) of the icon's active region.  Any mouse
    button press within this range will be interpreted as having selected
    this icon.
```
[Height](libraries/5-intuition-gadgets-gadget-structure.md)

```c
    This is the height (in pixels) of the icon's active region.  Any
    mouse button press within this range will be interpreted as having
    selected this icon.
```
[Flags](libraries/5-intuition-gadgets-gadget-structure.md)

```c
    The gadget must be of type [GADGIMAGE](libraries/5-gadget-structure-gadget-flags.md).  Three highlight modes are
    supported:   [GADGHCOMP](libraries/5-gadget-structure-gadget-flags.md), [GADGHIMAGE](libraries/5-gadget-structure-gadget-flags.md), and GADGBACKFILL.  GADGHCOMP
    complements everything within the area defined by [CurrentX](libraries/14-icon-library-data-structures-the-diskobject-structure.md), [CurrentY](libraries/14-icon-library-data-structures-the-diskobject-structure.md),
    Width, Height.  GADGHIMAGE uses an alternate selection image.
    GADGBACKFILL is similar to GADGHCOMP, but ensures that there is no
    "ring" around the selected image.  It does this by first
    complementing the image, and then flooding all color 3 pixels that
    are on the border of the image to color 0.  All other flag bits
    should be 0.
```
[Activation](libraries/5-intuition-gadgets-gadget-structure.md)

```c
    The activation should have only [RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) and [GADGIMMEDIATE](libraries/5-gadget-structure-gadget-activation-flags.md) set.
```
[Type](libraries/5-intuition-gadgets-gadget-structure.md)

```c
    The gadget type should be [BOOLGADGET](libraries/5-intuition-gadgets-gadget-structure.md).
```
[GadgetRender](libraries/5-intuition-gadgets-gadget-structure.md)

```c
    Set this to an appropriate [Image](libraries/8-creating-images-image-structure.md) structure.
```
[SelectRender](libraries/5-intuition-gadgets-gadget-structure.md)

```c
    Set this to an appropriate alternate Image structure if and only if
    the highlight mode is [GADGHIMAGE](libraries/5-gadget-structure-gadget-flags.md).
```
The [Image](libraries/8-creating-images-image-structure.md) structure is typically the same size as the gadget, except that
[Height](libraries/8-creating-images-image-structure.md) is often one pixel less than the gadget height. This allows a blank
line between the icon image and the icon name. The image depth must be 2;
[PlanePick](libraries/8-creating-images-image-structure.md) must be 3; and [PlaneOnOff](libraries/8-creating-images-image-structure.md) should be 0. The [NextImage](libraries/8-creating-images-image-structure.md) field
should be null.

