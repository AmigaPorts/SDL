---
title: 5 / / Mutual Exclude / Gadget Highlighting for Mutual Exclusion
manual: libraries
chapter: libraries
section: 5-mutual-exclude-gadget-highlighting-for-mutual-exclusion
functions: []
libraries: []
---

# 5 / / Mutual Exclude / Gadget Highlighting for Mutual Exclusion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When using complement mode highlighting, the image supplied must be at
least the size of the complemented area (the gadget select box).  An
extended [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadget with a mask may be used to constrain the area that
is highlighted.

Alternate image highlighting may be used provided the two images have
exactly the same size and position.  Likewise, a border and alternate
border may be used provided the two borders are identical in shape and
position, differing only in color.

Do not use other combinations for mutual exclude gadgets such as a gadget
with a border that uses complement mode highlighting or a gadget which
uses highlighting by drawing a box.  See the section on
"[Updating a Gadget's Imagery](libraries/5-gadget-refreshing-by-the-program-updating-a-gadget-s.md)" for more information.

