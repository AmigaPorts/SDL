---
title: 5 / Gadget Imagery / Line Drawn Gadgets
manual: libraries
chapter: libraries
section: 5-gadget-imagery-line-drawn-gadgets
functions: []
libraries: []
---

# 5 / Gadget Imagery / Line Drawn Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Gadget imagery can also be created by specifying a series of lines to be
drawn.  These lines can go around or through the select box of the gadget,
and can be drawn using any color pen and draw mode.  Multiple groups of
lines may be specified, each with its own pen and draw mode.

The [Border](libraries/8-creating-borders-border-structure-definition.md) structure is used to describe the lines to be drawn.  The
Border structure is incorporated into the gadget by clearing the
[GFLG_GADGIMAGE](libraries/5-gadget-structure-gadget-flags.md) flag in the gadget's [Flags](libraries/5-intuition-gadgets-gadget-structure.md) field.  The address of the
Border structure is placed into the gadget's [GadgetRender](libraries/5-intuition-gadgets-gadget-structure.md) field.  The
border imagery will be positioned relative to the gadget's select box.
For more information about creating a Border structure, see the chapter
"[Intuition Images, Line Drawing, and Text](libraries/8-intuition-images-line-drawing-and-text-creating-borders.md)."

