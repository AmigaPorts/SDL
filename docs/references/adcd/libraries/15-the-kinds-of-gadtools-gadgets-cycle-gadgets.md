---
title: 15 / / The Kinds of GadTools Gadgets / Cycle Gadgets
manual: libraries
chapter: libraries
section: 15-the-kinds-of-gadtools-gadgets-cycle-gadgets
functions: []
libraries: []
---

# 15 / / The Kinds of GadTools Gadgets / Cycle Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Like mutually exclusive gadgets, cycle gadgets (CYCLE_KIND) allow the user
to choose exactly one option from among several.

The cycle gadget appears as a raised rectangular button with a vertical
divider near the left side.  A circular arrow glyph appears to the left of
the divider, while the current choice appears to the right.  Clicking on
the cycle gadget advances to the next choice, while shift-clicking on it
changes it to the previous choice.

Cycle gadgets are more compact than mutually exclusive gadgets, since only
the current choice is displayed.  They are preferable to mutually
exclusive gadgets when a window needs to have several such gadgets as in
the PrinterGfx Preferences editor, or when there is a medium number of
choices.  If the number of choices is much more than about a dozen, it may
become too frustrating and inefficient for the user to find the desired
choice.  In that case, use a listview (scrolling list) instead.

The tags recognized by cycle gadgets are:

GTCY_Labels (STRPTR *)

```c
    Like [GTMX_Labels](libraries/15-the-kinds-of-gadtools-gadgets-mutually-exclusive-gadgets.md), this tag is associated with a
    NULL-pointer-terminated array of strings which are the choices that
    this gadget allows.  This array must be supplied to [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md),
    and can only be changed starting in V37.  The strings themselves must
    remain valid for the lifetime of the gadget.  (Create only (V36),
    Create and set (V37).)
```
GTCY_Active (UWORD)

```c
    The ordinal number, counting from zero, of the active choice of the
    cycle gadget.  The default is zero.  (Create and set.)
```
GA_Disabled (BOOL)

```c
    (New for V37, ignored by V36.)  Set this attribute to TRUE to disable
    the cycle gadget, to FALSE otherwise.  The default is FALSE.  (Create
    and set.)
```
When the user clicks or shift-clicks on a cycle gadget, the program will
receive an [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) IntuiMessage.  Look in the [Code](libraries/9-using-the-idcmp-intuimessages.md) field of the
[IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) for the ordinal number of the new active selection.

