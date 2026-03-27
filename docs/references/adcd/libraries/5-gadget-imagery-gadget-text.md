---
title: 5 / Gadget Imagery / Gadget Text
manual: libraries
chapter: libraries
section: 5-gadget-imagery-gadget-text
functions: []
libraries: []
---

# 5 / Gadget Imagery / Gadget Text

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Gadgets may include text information in the form of a linked list of
[IntuiText](libraries/8-creating-text-intuitext-structure.md) structures.  A pointer to the first IntuiText structure in the
list is placed in the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure's [GadgetText](libraries/5-intuition-gadgets-gadget-structure.md) field.  The text is
positioned relative to the top left corner of the gadget's select box.
For more information on IntuiText, see the
"[Intuition Images, Line Drawing and Text](libraries/8-intuition-images-line-drawing-and-text-creating-text.md)" chapter.

