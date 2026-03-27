---
title: 5 Intuition Gadgets / Gadget Size and Position
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-gadget-size-and-position
functions: []
libraries: []
---

# 5 Intuition Gadgets / Gadget Size and Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The position and dimensions of the gadget's select box are defined in the
[Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.  The [LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md), [TopEdge](libraries/5-intuition-gadgets-gadget-structure.md), [Width](libraries/5-intuition-gadgets-gadget-structure.md) and [Height](libraries/5-intuition-gadgets-gadget-structure.md) values can be
absolute numbers or values relative to the size of the window.  When using
absolute numbers, the values are set once, when the gadget is created.
When using relative numbers, the size and position of the select box are
adjusted dynamically every time the window size changes.

The gadget image is positioned relative to the select box so when the
select box moves the whole gadget moves.  The size of the gadget image,
however, is not usually affected by changes in the select box size
([proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadgets are the exception).  To create a gadget image that
changes size when the select box and window change size, you have to
handle gadget rendering yourself or use a BOOPSI gadget.

 [Select Box Position](libraries/5-gadget-size-and-position-select-box-position.md)     [Positioning Gadgets in Window Borders](libraries/5-gadget-size-and-position-positioning-gadgets-in-window.md) 
 [Select Box Dimension](libraries/5-gadget-size-and-position-select-box-dimension.md) 

