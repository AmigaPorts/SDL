---
title: 28 / / / Using Sequenced Drawing and Motion Control
manual: libraries
chapter: libraries
section: 28-using-sequenced-drawing-and-motion-control
functions: []
libraries: []
---

# 28 / / / Using Sequenced Drawing and Motion Control

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you are using Ring Motion Control, you will probably set the velocity
and acceleration variables to zero.  For instance, consider the example of
a person walking.  With Ring Motion Control, as each foot falls it is
positioned on the ground exactly where originally drawn.  If you included
a velocity value, the person's foot would not be stationary with respect
to the ground, and the person would appear to "skate" rather than walk.
If you set the velocity and acceleration variables at zero, you avoid this
problem.

When the system activates a new [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md), it checks the [Flags](libraries/28-animation-with-gels-animation-data-structures.md) field to see
if the [RINGTRIGGER](libraries/28-specifying-animation-object-setting-up-ring-motion.md) bit is set.  If so, the system adds [RingYTrans](libraries/28-graphics-sprites-bobs-and-animation-about-the-gels-system.md) and
[RingXTrans](libraries/28-animation-with-gels-animation-data-structures.md) to [AnY and AnX](libraries/28-specifying-the-animation-object-position-of-an-animob.md) respectively.

