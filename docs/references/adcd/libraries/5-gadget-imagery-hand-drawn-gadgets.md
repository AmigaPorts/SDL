---
title: 5 / Gadget Imagery / Hand Drawn Gadgets
manual: libraries
chapter: libraries
section: 5-gadget-imagery-hand-drawn-gadgets
functions: []
libraries: []
---

# 5 / Gadget Imagery / Hand Drawn Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Bitmap or custom images are used as imagery for a gadget by setting the
[GFLG_GADGIMAGE](libraries/5-gadget-structure-gadget-flags.md) flag in the [Flags](libraries/5-intuition-gadgets-gadget-structure.md) field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.  An [Image](libraries/8-creating-images-image-structure.md)
structure must be set up to manage the bitmap data.  The address of the
Image structure is placed into the gadget's [GadgetRender](libraries/5-intuition-gadgets-gadget-structure.md) field.  The
bitmap image will be positioned relative to the gadget's select box.  For
more information about creating Intuition images, see the chapter
"[Intuition Images, Line Drawing, and Text](libraries/8-intuition-images-line-drawing-and-text-creating-images.md)."  For a listing of the Gadget
structure and all its flags see the "[Gadget Structure](libraries/5-intuition-gadgets-gadget-structure.md)" section later in
this chapter.

