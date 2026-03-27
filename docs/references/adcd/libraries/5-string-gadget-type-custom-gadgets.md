---
title: 5 / String Gadget Type / Custom Gadgets
manual: libraries
chapter: libraries
section: 5-string-gadget-type-custom-gadgets
functions: []
libraries: []
---

# 5 / String Gadget Type / Custom Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Intuition also supports custom gadgets, where the application can supply
to Intuition its own code to manage gadgets.  This allows the creation of
gadgets with behavior quite different from standard [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md), [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md),
or [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadgets.  For example, it would be possible to create a dial
gadget, where the user could rotate the [knob](libraries/5-proportional-gadget-components-the-knob.md) of a gadget.  The code for a
custom gadget needs to respond to various commands and requests from
Intuition, such as "is this pixel in your hit-area?", "please go active"
and "please go inactive".

Intuition has an object-oriented creation and delegation method called
BOOPSI, that allows custom gadgets to be easily created, deleted,
specialized from existing classes of custom gadget, and so on.  See the
Intuition chapter "[BOOPSI](libraries/12-boopsi-object-oriented-intuition-boopsi-gadgets.md)" for details.

