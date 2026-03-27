---
title: 27 / / Viewport Display Modes / Single- vs. Dual-playfield Mode
manual: libraries
chapter: libraries
section: 27-viewport-display-modes-single-vs-dual-playfield-mode
functions: []
libraries: []
---

# 27 / / Viewport Display Modes / Single- vs. Dual-playfield Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When you specify single-playfield mode you are asking that the system
treat all bitplanes as part of the definition of a single playfield image.
Each of the bitplanes defined as part of this [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) contributes data
bits that determine the color of the pixels in a single playfield.


```c
     [Figure 27-12: A Single-playfield Display](libraries/lib-pics-27-12-pic.md) 
```
If you use dual-playfield mode, you can define two independent, separately
controllable playfield areas as shown on the next page.


```c
     [Figure 27-13: A Dual-playfield Display](libraries/lib-pics-27-13-pic.md) 
```
In the previous figure, [PFBA](libraries/27-display-routines-and-structures-viewport-display-modes.md) was included in the display mode.  If PFBA
had not been included, the relative priorities would have been reversed;
playfield 2 would have appeared to be behind playfield 1.

