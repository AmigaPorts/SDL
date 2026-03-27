---
title: 28 / / Detecting Gel Collisions / VSprite Collision Mask
manual: libraries
chapter: libraries
section: 28-detecting-gel-collisions-vsprite-collision-mask
functions: []
libraries: []
---

# 28 / / Detecting Gel Collisions / VSprite Collision Mask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [CollMask](autodocs-2.0/includes-graphics-gels-h.md) member of the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) is a pointer to a memory area allocated
for holding the collision mask of that GEL.  This area must be in Chip
memory and its size is the equivalent of one bitplane of the GEL's image.
The collision mask is usually the same as the shadow mask of the GEL,
formed from a logical-OR combination of all planes of the image.  The
following figure shows an example collision mask.




     If this is the        ...and this is the        ...then its
    image in plane 1...    image in plane 2...       CollMask is:

     ···············        ···············        ···············
     ·*************·        ···············        ·*************·
     ··*·········*··        ···············        ··*·········*··
     ···*·······*···        ······***······        ···*··***··*···
     ····*·····*····        ·······*·······        ····*··*··*····
     ·····*···*·····        ···············        ·····*···*·····
     ······*·*······        ···············        ······*·*······
     ·······*·······        ···············        ·······*·······
     ···············        ···············        ···············

                     Figure 28-3: A Collision Mask
Alternatively, you may have a collision mask that is not derived from the
image.  In this case, the actual image isn't relevant.  The system will
not register collisions unless the other objects touch the collision mask.
If the collision mask is smaller than the image, other objects will pass
through the edges without a collision.

