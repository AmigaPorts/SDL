---
title: 27 / / Using the Graphics Drawing Routines / Drawing Patterned Lines
manual: libraries
chapter: libraries
section: 27-using-the-graphics-drawing-routines-drawing-patterned
functions: []
libraries: []
---

# 27 / / Using the Graphics Drawing Routines / Drawing Patterned Lines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To turn the example above into a patterned line draw, simply set a drawing
pattern, such as:


```c
    SetDrPt(&rastPort, 0xAAAA);
```
Now all lines drawn appear as dotted lines (0xAAAA = 1010101010101010 in
binary).  To resume drawing solid lines, execute the statement:


```c
    SetDrPt(&rastPort, ~0);
```
Because ~0 is defined as all bits on (11...11) in binary.

