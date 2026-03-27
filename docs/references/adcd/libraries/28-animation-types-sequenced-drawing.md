---
title: 28 / / Animation Types / Sequenced Drawing
manual: libraries
chapter: libraries
section: 28-animation-types-sequenced-drawing
functions: []
libraries: []
---

# 28 / / Animation Types / Sequenced Drawing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To make the ball appear to rotate is a little more complex.  To produce
apparent movement within the image, sequencing is used.  This is done by
having a stack of [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md)'s that are laid down one after the other, a
frame at a time.  The stack can be arranged in a circular list for
repeating movement.  So, when you combine a sequence of drawings using
AnimComps with simple motion control using an [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md), you can perform more
complex animations such as having a rotating ball bounce around.

