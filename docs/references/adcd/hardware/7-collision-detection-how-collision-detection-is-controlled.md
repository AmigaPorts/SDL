---
title: 7 / Collision Detection / How Collision Detection is Controlled
manual: hardware
chapter: hardware
section: 7-collision-detection-how-collision-detection-is-controlled
functions: []
libraries: []
---

# 7 / Collision Detection / How Collision Detection is Controlled

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The collision control register, CLXCON, contains the bits that define
certain characteristics of collision detection. Its bits are shown in
Table 7-4.

                  Table 7-4: CLXCON Bits

    Bit
   Number    Name      Function
   ------    ----      --------


```c
     15      ENSP7     Enable sprite 7 (OR with sprite 6)
     14      ENSP5     Enable sprite 5 (OR with sprite 4)
     13      ENSP3     Enable sprite 3 (OR with sprite 2)
     12      ENSP1     Enable sprite 1 (OR with sprite 0)
     11      ENBP6     Enable bitplane 6 (match required for collision)
     10      ENBP5     Enable bitplane 5 (match required for collision)
     9       ENBP4     Enable bitplane 4 (match required for collision)
     8       ENBP3     Enable bitplane 3 (match required for collision)
     7       ENBP2     Enable bitplane 2 (match required for collision)
     6       ENBP1     Enable bitplane 1 (match required for collision)
     5       MVBP6     Match value for bitplane 6 collision
     4       MVBP5     Match value for bitplane 5 collision
     3       MVBP4     Match value for bitplane 4 collision
     2       MVBP3     Match value for bitplane 3 collision
     1       MVBP2     Match value for bitplane 2 collision
     0       MVBP1     Match value for bitplane 1 collision
```
Bits 15-12 let you specify that collisions with a sprite pair are to
include the odd-numbered sprite of a pair of sprites.  The even-numbered
sprites always are included in the collision detection. Bits 11-6 let you
specify whether to include or exclude specific bitplanes from the
collision detection. Bits 5-0 let you specify the polarity (true-false
condition) of bits that will cause a collision. For example, you may wish
to register collisions only when the object collides with "something
green" or "something blue." This feature, along with the collision enable
bits, allows you to  specify the exact bits, and their polarity, for the
collision to be registered.

   NOTE:
   -----
   This register is write-only. If all bitplanes are excluded
   (disabled), then a bitplane collision will always be detected.

