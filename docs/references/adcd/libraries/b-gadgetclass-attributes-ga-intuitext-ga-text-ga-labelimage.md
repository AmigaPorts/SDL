---
title: B / gadgetclass / Attributes:GA_IntuiText, GA_Text, GA_LabelImage (IS)
manual: libraries
chapter: libraries
section: b-gadgetclass-attributes-ga-intuitext-ga-text-ga-labelimage
functions: []
libraries: []
---

# B / gadgetclass / Attributes:GA_IntuiText, GA_Text, GA_LabelImage (IS)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These attributes correspond to one field in the object's embedded [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
structure--the [GadgetText](libraries/5-intuition-gadgets-gadget-structure.md) field.  Setting any of these attributes copies
the attribute's value blindly into the GadgetText field.  In addition,
setting GA_Text also sets the [GFLG_LABELSTRING](autodocs-2.0/includes-intuition-intuition-h.md) flag in [Gadget.Flags](libraries/5-intuition-gadgets-gadget-structure.md) and
setting GA_LabelImage sets the [GFLG_LABELIMAGE](autodocs-2.0/includes-intuition-intuition-h.md) flag in Gadget.Flags.  The
GA_IntuiText attribute must be an [IntuiText](libraries/8-creating-text-intuitext-structure.md) pointer, as with old-style
gadgets.  GA_Text takes a pointer to a NULL- terminated string (UBYTE *).
GA_LabelImage takes a pointer to a (Boopsi) image.  Note that most gadget
classes do not support GA_Text and GA_LabelImage.  See the description of
specific gadget classes for more details.

