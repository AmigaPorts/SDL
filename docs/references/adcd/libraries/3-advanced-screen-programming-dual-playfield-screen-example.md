---
title: 3 / Advanced Screen Programming / Dual-Playfield Screen Example
manual: libraries
chapter: libraries
section: 3-advanced-screen-programming-dual-playfield-screen-example
functions: [MakeScreen, OpenScreen, RethinkDisplay]
libraries: [intuition.library]
---

# 3 / Advanced Screen Programming / Dual-Playfield Screen Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This example shows how to create a dual-playfield display.  Note that this
technique is only valid for screen modes which support dual-playfield, do
not try to convert other modes.

Setting up dual playfield mode in the [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) call is not the best
method of obtaining a dual playfield viewport for a screen.  It is better
to open a standard screen, passing to Intuition (or letting Intuition
create) only one of the playfield bitmaps (the front one).  Next allocate
and set up a second bitmap, its bitplanes, and a [RasInfo](libraries/27-forming-a-basic-display-preparing-the-rasinfo-structure.md) structure
installing these into the new screen's viewport.  Update the viewport
modes to include DUALPF and call [MakeScreen()](libraries/3-screen-functions-that-integrate-intuition-and-graphics.md) and [RethinkDisplay()](libraries/3-screen-functions-that-integrate-intuition-and-graphics.md).  This
method, shown in the example below, keeps Intuition rendering (gadgets,
menus, windows) in a single playfield.


```c
     [dualplayfield.c](libraries/lib-examples-dualplayfield-c.md) 
```

---

## See Also

- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
