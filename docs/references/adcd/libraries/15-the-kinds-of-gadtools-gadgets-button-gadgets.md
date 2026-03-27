---
title: 15 / / The Kinds of GadTools Gadgets / Button Gadgets
manual: libraries
chapter: libraries
section: 15-the-kinds-of-gadtools-gadgets-button-gadgets
functions: []
libraries: []
---

# 15 / / The Kinds of GadTools Gadgets / Button Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Button gadgets (BUTTON_KIND) are perhaps the simplest kind of GadTools
gadget.  Button gadgets may be used for objects like the "OK" and "Cancel"
buttons in requesters.  GadTools will create a hit-select button with a
raised bevelled border.  The label supplied will be centered on the
button's face.  Since the label is not clipped, be sure that the gadget is
large enough to contain the text supplied.

Button gadgets recognize only one tag:

GA_Disabled (BOOL)

```c
    Set this attribute to TRUE to disable or ghost the button gadget, to
    FALSE otherwise.  The default is FALSE. (Create and set.)
```
When the user selects a button gadget, the program will receive an
[IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) event.

If clicking on a button causes a requester to appear, for example a button
that brings up a color requester, then the button text should end in
ellipsis (...), as in "Quit..."

