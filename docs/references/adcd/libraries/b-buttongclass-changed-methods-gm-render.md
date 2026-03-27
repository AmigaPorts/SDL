---
title: B / buttongclass / Changed Methods: GM_RENDER
manual: libraries
chapter: libraries
section: b-buttongclass-changed-methods-gm-render
functions: []
libraries: []
---

# B / buttongclass / Changed Methods: GM_RENDER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All rendering is passed along to the [GadgetRender.Image](libraries/5-intuition-gadgets-gadget-structure.md) (the [GA_Image](libraries/b-buttongclass-attributes-ga-image-is.md)
attribute).  This method can tell its image to render in any of four image
states: [IDS_INACTIVESELECTED](libraries/b-imageclass-new-methods-im-draw.md), [IDS_INACTIVENORMAL](libraries/b-imageclass-new-methods-im-draw.md), [IDS_SELECTED](libraries/b-imageclass-new-methods-im-draw.md), or
[IDS_NORMAL](libraries/b-imageclass-new-methods-im-draw.md).

