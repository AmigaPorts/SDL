---
title: 5 / / Initialization of Proportional Gadget / of the Gadget Structure
manual: libraries
chapter: libraries
section: 5-initialization-of-proportional-gadget-of-the-gadget
functions: []
libraries: []
---

# 5 / / Initialization of Proportional Gadget / of the Gadget Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure, set the [GadgetType](libraries/5-intuition-gadgets-gadget-structure.md) field to [GTYP_PROPGADGET](libraries/5-intuition-gadgets-gadget-structure.md) and
place the address of the [PropInfo](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) structure in the [SpecialInfo](libraries/5-intuition-gadgets-gadget-structure.md) field.

When using [AUTOKNOB](libraries/5-initialization-of-proportional-gadget-the-propinfo.md), the [GadgetRender](libraries/5-intuition-gadgets-gadget-structure.md) field must point to an [Image](libraries/8-creating-images-image-structure.md)
structure. The Image need not be initialized when using AUTOKNOB, but the
structure must be provided. These Image structures may not be shared
between gadgets, each must have its own.

To use application imagery for the [knob](libraries/5-proportional-gadget-components-the-knob.md), set [GadgetRender](libraries/5-intuition-gadgets-gadget-structure.md) to point to an
initialized [Image](libraries/8-creating-images-image-structure.md) structure. If the knob highlighting is done by alternate
image ([GFLG_GADGHIMAGE](libraries/5-gadget-structure-gadget-flags.md)), the alternate image must be the same size and
type as the normal knob image.

