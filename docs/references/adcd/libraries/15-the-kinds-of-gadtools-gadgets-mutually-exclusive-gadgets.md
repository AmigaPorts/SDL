---
title: 15 / / The Kinds of GadTools Gadgets / Mutually-Exclusive Gadgets
manual: libraries
chapter: libraries
section: 15-the-kinds-of-gadtools-gadgets-mutually-exclusive-gadgets
functions: []
libraries: []
---

# 15 / / The Kinds of GadTools Gadgets / Mutually-Exclusive Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Use mutually exclusive gadgets (MX_KIND), or radio buttons, when the user
must choose only one option from a short list of possibilities.  Mutually
exclusive gadgets are appropriate when there are a small number of
choices, perhaps eight or less.

A set of mutually exclusive gadgets consists of a list of labels and
beside each label, a small raised oval that looks like a button.  Exactly
one of the ovals is recessed and highlighted, to indicate the selected
choice.  The user can pick another choice by clicking on any of the raised
ovals.  This choice will become active and the previously selected choice
will become inactive.  That is, the selected oval will become recessed
while the previous one will pop out, like the buttons on a car radio.

Mutually exclusive gadgets recognize these tags:

GTMX_Labels (STRPTR *)

```c
    A NULL-pointer-terminated array of strings which are to be the labels
    beside each choice in the set of mutually exclusive gadgets.  This
    array determines how many buttons are created.  This array must be
    supplied to [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md) and may not be changed.  The strings
    themselves must remain valid for the lifetime of the gadget.  (Create
    only.)
```
GTMX_Active (UWORD)

```c
    The ordinal number, counting from zero, of the active choice of the
    set of mutually exclusive gadgets.  The default is zero.  (Create and
    set.)
```
GTMX_Spacing (UWORD)

```c
    The amount of space, in pixels, that will be placed between
    successive choices in a set of mutually exclusive gadgets.  The
    default is one.  (Create only.)
```
When the user selects a new choice from a set of mutually exclusive
gadgets, the program will receive an [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) IntuiMessage. Look
in the [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)'s [Code](libraries/9-using-the-idcmp-intuimessages.md) field for the ordinal number of the new active
selection.

The [ng_GadgetText](libraries/15-gadtools-gadgets-the-newgadget-structure.md) field of the [NewGadget](libraries/15-gadtools-gadgets-the-newgadget-structure.md) structure is ignored for mutually
exclusive gadgets.  The text position specified in [ng_Flags](libraries/15-gadtools-gadgets-the-newgadget-structure.md)  determines
whether the item labels are placed to the left or the right of the radio
buttons themselves.  By default, the labels appear on the left.  Do not
specify PLACETEXT_ABOVE, PLACETEXT_BELOW or PLACETEXT_IN for this kind of
gadget.

Like the checkbox, the size of the radio button is currently fixed, and
the dimensions supplied in the [NewGadget](libraries/15-gadtools-gadgets-the-newgadget-structure.md) structure are ignored.  If in the
future the buttons are made scalable, it will be done in a compatible
manner.  Currently, mutually exclusive gadgets may not be disabled.

