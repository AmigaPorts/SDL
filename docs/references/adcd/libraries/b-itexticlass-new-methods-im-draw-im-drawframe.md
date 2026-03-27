---
title: B / itexticlass / New Methods: IM_DRAW/IM_DRAWFRAME
manual: libraries
chapter: libraries
section: b-itexticlass-new-methods-im-draw-im-drawframe
functions: []
libraries: []
---

# B / itexticlass / New Methods: IM_DRAW/IM_DRAWFRAME

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These methods ask an [itexticlass](libraries/b-boopsi-class-reference-itexticlass.md) object to render its [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure,
which it gets from the [imageclass](libraries/b-boopsi-class-reference-imageclass.md) [IA_Data](libraries/b-imageclass-attributes-ia-data-isg.md) attribute.  An itexticlass
object renders its IntuiText relative to the [IA_Left](libraries/b-imageclass-attributes-ia-left-ia-top-ia-width-ia-height.md) and [IA_Top](libraries/b-imageclass-attributes-ia-left-ia-top-ia-width-ia-height.md) attributes
it inherits from imageclass.  This method uses the JAM1 drawing mode and
the [IA_FGPen](libraries/b-imageclass-attributes-ia-fgpen-ia-bgpen-isg.md) to render the text.  See the imageclass description of
[IM_DRAW](libraries/b-imageclass-new-methods-im-draw.md)/[IM_DRAWFRAME](libraries/b-imageclass-new-methods-im-drawframe.md) for more details.

