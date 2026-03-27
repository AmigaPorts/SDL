---
title: 28 / / Animation Components / Specifying Time for Each Image
manual: libraries
chapter: libraries
section: 28-animation-components-specifying-time-for-each-image
functions: []
libraries: []
---

# 28 / / Animation Components / Specifying Time for Each Image

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) members [Timer](autodocs-2.0/includes-graphics-gels-h.md) and [TimeSet](autodocs-2.0/includes-graphics-gels-h.md) are used to specify how long the
system should keep each sequential image on the screen.

When the system makes an animation component active, it copies the value
you have put in the [TimeSet](autodocs-2.0/includes-graphics-gels-h.md) member into the [Timer](autodocs-2.0/includes-graphics-gels-h.md) member.  As the
animation proceeds, the system decrements Timer; as long as it is greater
than zero, then that [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) remains active.  When the Timer value
reaches zero, the system makes the next AnimComp in the sequence active,
and the process repeats.

If you initialize the value in [TimeSet](autodocs-2.0/includes-graphics-gels-h.md) to zero, the system will not
sequence this component at all (and Timer will remain zero).

