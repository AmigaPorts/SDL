---
title: 28 / / Animation Types / Ring Motion Control
manual: libraries
chapter: libraries
section: 28-animation-types-ring-motion-control
functions: []
libraries: []
---

# 28 / / Animation Types / Ring Motion Control

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Making a worm appear to crawl is similar to the rotating ball.  There is
still a stack of [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md)s that are sequenced automatically, and one
controlling [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md).  But each AnimComp image is drawn so that it appears
to move relative to an internal point that remains stationary throughout
the stack.  So instead of the AnimOb's common reference point moving in
each frame, you tell the system how far to move only at the end of each
AnimComp sequence.


```c
     [Figure 28-5: Ring Motion Control](libraries/lib-pics-28-5-pic.md) 
```
As illustrated in the figure at left, the sequence of events for Ring
Motion Control look like this:


    Draw AnimComp1, Draw AnimComp2, Draw AnimComp3, Move AnimOb,
    Draw AnimComp1, Draw AnimComp2, Draw AnimComp3, Move AnimOb,
    Draw AnimComp1...
