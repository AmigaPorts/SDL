---
title: 28 / / Animation Types / Simple Motion Control
manual: libraries
chapter: libraries
section: 28-animation-types-simple-motion-control
functions: []
libraries: []
---

# 28 / / Animation Types / Simple Motion Control

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To produce motion of a simple object, such as a ball, the object is simply
moved relative to a background display, a little at a time.  This is
simple motion control, and can be accomplished with one [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) and one
[AnimOb](libraries/28-animation-with-gels-animation-data-structures.md), by simply changing the AnimOb's position every N video frames.
The apparent speed of the object is a combination of how often it is moved
(every frame, every other frame, etc.) and how far it is moved (how much
the AnimOb's [AnX and AnY](libraries/28-specifying-the-animation-object-position-of-an-animob.md) are changed).

