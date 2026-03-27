---
title: 28 / / Types Of GELs / AnimObs
manual: libraries
chapter: libraries
section: 28-types-of-gels-animobs
functions: []
libraries: []
---

# 28 / / Types Of GELs / AnimObs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The AnimOb (Animation Object) is a data structure that is used to group
one or more AnimComps for convenient movement.  For example, an AnimOb
could be created that consists of two AnimComps, one that looks like a
planet and another containing a sequence that describes orbiting moons.
By moving just the AnimOb the image of the planet can be moved across the
display and the moons will travel along with it, orbiting the planet the
entire time.  The system automatically manages the movement of all the
AnimComps associated with the AnimOb.

