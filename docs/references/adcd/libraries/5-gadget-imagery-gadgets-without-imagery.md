---
title: 5 / Gadget Imagery / Gadgets Without Imagery
manual: libraries
chapter: libraries
section: 5-gadget-imagery-gadgets-without-imagery
functions: []
libraries: []
---

# 5 / Gadget Imagery / Gadgets Without Imagery

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Gadgets can be created without any defining imagery.  This type of gadget
may be used where mouse information is required but graphical definition
of the gadget is not, or where the existing graphics sufficiently define
the gadget that no additional imagery is required.  A gadget with no
imagery may be created by clearing the [GFLG_GADGIMAGE](libraries/5-gadget-structure-gadget-flags.md) flag in the gadget's
[Flags](libraries/5-intuition-gadgets-gadget-structure.md) field, and by setting the gadget's [GadgetRender](libraries/5-intuition-gadgets-gadget-structure.md) and [GadgetText](libraries/5-intuition-gadgets-gadget-structure.md)
fields to NULL.

The text display of a word processor is a case where mouse information is
required without any additional graphics.  If a large gadget is placed
over the text display, gadget and mouse event messages may be received at
the IDCMP ([Window.UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md)) when the mouse select button is either pressed
or released.  The mouse information is used to position the pointer in the
text, or to allow the user to mark blocks of text.  The drag bar of a
window is another example of a gadget where existing imagery defines the
gadget such that additional graphics are not required.

