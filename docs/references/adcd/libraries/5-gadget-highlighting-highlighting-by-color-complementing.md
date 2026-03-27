---
title: 5 / Gadget Highlighting / Highlighting by Color Complementing
manual: libraries
chapter: libraries
section: 5-gadget-highlighting-highlighting-by-color-complementing
functions: []
libraries: []
---

# 5 / Gadget Highlighting / Highlighting by Color Complementing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Highlighting may be accomplished by complementing all of the colors in the
gadget's select box. In this context, complementing means the complement
of the binary number used to represent a particular color register.  For
example, if the color in color register 2 is used (binary 10) in a
specific pixel of the gadget, the complemented value of that pixel will be
the color in color register 1 (binary 01).

To use this highlighting method, set the [GFLG_GADGHCOMP](libraries/5-gadget-structure-gadget-flags.md) flag.

Only the select box of the gadget is complemented; any portion of the
text, image, or border which is outside of the select box is not
disturbed. See the chapter "[Intuition Images, Line Drawing, and Text](libraries/8-creating-images-picking-bitplanes-for-image-display.md)," for
more information about complementing and about color in general.

