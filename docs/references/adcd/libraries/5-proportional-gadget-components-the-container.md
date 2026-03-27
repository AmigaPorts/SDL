---
title: 5 / / Proportional Gadget Components / The Container
manual: libraries
chapter: libraries
section: 5-proportional-gadget-components-the-container
functions: []
libraries: []
---

# 5 / / Proportional Gadget Components / The Container

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The container is the area in which the [knob](libraries/5-proportional-gadget-components-the-knob.md) can move.  It is actually the
select box of the gadget.  The size of the container, like that of any
other gadget select box, can be relative to the size of the window.  The
position of the container can be relative to any of the Intuition window's
border.

Clicking in the container around the [knob](libraries/5-proportional-gadget-components-the-knob.md) will increment or decrement the
value of the gadget (the [pot variables](libraries/5-proportional-gadget-components-the-pot-variables.md)) by the appropriate amount
(specified in the [body variables](libraries/5-proportional-gadget-components-the-body-variables.md)).  The knob will move towards the point
clicked when action is taken.

