---
title: 5 / Gadget Highlighting / With an Alternate Image or Alternate Border
manual: libraries
chapter: libraries
section: 5-gadget-highlighting-with-an-alternate-image-or-alternate
functions: []
libraries: []
---

# 5 / Gadget Highlighting / With an Alternate Image or Alternate Border

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An alternate image may be supplied as highlighting for gadgets that use
image rendering, similarly an alternate border may be supplied for gadgets
that use border rendering.  When the gadget is active or selected, the
alternate image or border is displayed in place of the default image or
border.  For this highlighting method, set the [SelectRender](libraries/5-intuition-gadgets-gadget-structure.md) field of the
[Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure to point to the [Image](libraries/8-creating-images-image-structure.md) structure or [Border](libraries/8-creating-borders-border-structure-definition.md) structure for
the alternate display.

Specify that highlighting is to be done with alternate imagery by setting
the [GFLG_GADGHIMAGE](libraries/5-gadget-structure-gadget-flags.md) flag in the [Flags](libraries/5-intuition-gadgets-gadget-structure.md) field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.  When
using GFLG_GADGHIMAGE, remember to set the [GFLG_GADGIMAGE](libraries/5-gadget-structure-gadget-flags.md) flag for images,
clear it for borders.

When using alternate images and borders for highlighting, gadgets rendered
with images must highlight with another image and gadgets rendered with
borders must highlight with another border.  For information about how to
create an [Image](libraries/8-intuition-images-line-drawing-and-text-creating-images.md) or [Border](libraries/8-intuition-images-line-drawing-and-text-creating-borders.md) structure, see the chapter "Intuition Images,
Line Drawing, and Text."

