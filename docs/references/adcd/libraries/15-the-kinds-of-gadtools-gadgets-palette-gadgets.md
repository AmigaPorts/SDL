---
title: 15 / / The Kinds of GadTools Gadgets / Palette Gadgets
manual: libraries
chapter: libraries
section: 15-the-kinds-of-gadtools-gadgets-palette-gadgets
functions: []
libraries: []
---

# 15 / / The Kinds of GadTools Gadgets / Palette Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Palette gadgets (PALETTE_KIND) let the user pick a color from a set of
several.  A palette gadget consists of a number of colored squares, one
for each color available.  There may also be an optional indicator square
which is filled with the currently selected color.  To create a color
editor, a palette gadget would be combined with some sliders to control
red, green and blue components, for example.

Palette gadgets use the following tags:

GTPA_Depth (UWORD)

```c
    The number of bitplanes that the palette represents.  There will be 1
    << depth squares in the palette gadget.  The default is one.  (Create
    only.)
```
GTPA_Color (UBYTE)

```c
    The selected color of the palette.  The default is one.  (Create and
    set.)
```
GTPA_ColorOffset (UBYTE)

```c
    The first color to use in the palette.  For example, if GTPA_Depth is
    two and GTPA_ColorOffset is four, then the palette will have squares
    for colors four, five, six and seven.  The default is zero.  (Create
    only.)
```
GTPA_IndicatorWidth (UWORD)

```c
    The desired width of the current-color indicator.  By specifying this
    tag, the application is asking for an indicator to be placed to the
    left of the color selection squares.  The indicator will be as tall
    as the gadget itself.  By default there is no indicator.  (Create
    only.)
```
GTPA_IndicatorHeight (UWORD)

```c
    The desired height of the current-color indicator.  By specifying
    this tag, the application is asking for an indicator to be placed
    above the color selection squares.  The indicator will be as wide as
    the gadget itself.  By default there is no indicator.  (Create only.)
```
GA_Disabled (BOOL)

```c
    Set this attribute to TRUE to disable the palette gadget, to FALSE
    otherwise.  The default is FALSE.  (Create and set.)
```
An [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) will be received when the user selects a
color from the palette.  The current-color indicator is recessed,
indicating that clicking on it has no effect.

If the palette is wide and not tall, use the GTPA_IndicatorWidth tag to
put the indicator on the left.  If the palette is tall and narrow, put the
indicator on top using GTPA_IndicatorHeight.

By default, the gadget's label will go above the palette gadget, unless
GTPA_IndicatorWidth is specified, in which case the label will go on the
left.  In either case, the default may be overridden by setting the
appropriate flag in the [NewGadget](libraries/15-gadtools-gadgets-the-newgadget-structure.md)'s [ng_Flags](libraries/15-gadtools-gadgets-the-newgadget-structure.md) field.

The size specified for the palette gadget will determine how the area is
subdivided to make the individual color squares.  The actual size of the
palette gadget will be no bigger than the size given, but it can be
smaller in order to make the color squares all exactly the same size.

