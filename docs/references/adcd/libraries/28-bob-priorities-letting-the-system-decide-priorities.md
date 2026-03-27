---
title: 28 / / Bob Priorities / Letting the System Decide Priorities
manual: libraries
chapter: libraries
section: 28-bob-priorities-letting-the-system-decide-priorities
functions: []
libraries: []
---

# 28 / / Bob Priorities / Letting the System Decide Priorities

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The priority issue can be ignored and the system will render the Bobs as
it finds them in the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list.  To do this, set the Bob's [Before](libraries/28-bob-priorities-specifying-the-drawing-order.md) and
[After](libraries/28-bob-priorities-specifying-the-drawing-order.md) pointers to NULL.  Since the GelsInfo list is sorted by GEL x, y
values, Bobs that are higher on the display will appear behind the lower
ones, and Bobs that are more to the left on the display will appear behind
Bobs on the right.

As Bobs are moved about the display, their priorities will change.

