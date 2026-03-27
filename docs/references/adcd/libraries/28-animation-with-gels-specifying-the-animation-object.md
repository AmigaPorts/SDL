---
title: 28 / Animation with GELs / Specifying the Animation Object
manual: libraries
chapter: libraries
section: 28-animation-with-gels-specifying-the-animation-object
functions: []
libraries: []
---

# 28 / Animation with GELs / Specifying the Animation Object

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For each [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md), you initially specify:


```c
      * The starting position of this object

      * Its velocity and acceleration (optional).

      * A pointer to the first of its [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md)s.

      * A pointer to a special animation routine related to this object
        (optional).

      * Your own extensions to this structure (optional).
```
 [Linking the AnimComp Sequences to the AnimOb](libraries/28-linking-the-animcomp-sequences-to-the-animob.md) 
 [Position of an AnimOb](libraries/28-specifying-the-animation-object-position-of-an-animob.md) 
 [Setting Up Simple Motion Control](libraries/28-specifying-animation-object-setting-up-simple-motion.md) 
 [Setting Up Ring Motion Control](libraries/28-specifying-animation-object-setting-up-ring-motion.md) 
 [Using Sequenced Drawing and Motion Control](libraries/28-using-sequenced-drawing-and-motion-control.md) 

