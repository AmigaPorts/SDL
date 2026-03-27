---
title: 7 / Collision Detection / How To Interpret the Collision Data
manual: hardware
chapter: hardware
section: 7-collision-detection-how-to-interpret-the-collision-data
functions: []
libraries: []
---

# 7 / Collision Detection / How To Interpret the Collision Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The collision data register, CLXDAT, is read-only, and its contents are
automatically cleared to 0 after it is read.  Its bits are as shown in
Table 7-3.



```c
                Table 7-3: CLXDAT Bits


          Bit Number      Collisions Registered
          ----------      ---------------------
              15      not used
              14      Sprite 4 (or 5) to sprite 6 (or 7)
              13      Sprite 2 (or 3) to sprite 6 (or 7)
              12      Sprite 2 (or 3) to sprite 4 (or 5)
              11      Sprite 0 (or 1) to sprite 6 (or 7)
              10      Sprite 0 (or 1) to sprite 4 (or 5)
              9       Sprite 0 (or 1) to sprite 2 (or 3)
              8       Even bitplanes to sprite 6 (or 7)
              7       Even bitplanes to sprite 4 (or 5)
              6       Even bitplanes to sprite 2 (or 3)
              5       Even bitplanes to sprite 0 (or 1)
              4       Odd  bitplanes to sprite 6 (or 7)
              3       Odd  bitplanes to sprite 4 (or 5)
              2       Odd  bitplanes to sprite 2 (or 3)
              1       Odd  bitplanes to sprite 0 (or 1)
              0       Even bitplanes to odd bitplanes
```
   About odd-numbered sprites.
   ---------------------------
   The numbers in parentheses in Table 7-3 refer to collisions that will
   register only if you want them to show up. The
```c
    [collision control register](hardware/7-collision-detection-how-collision-detection-is-controlled.md)  described below lets you either ignore or
```
   include the odd-numbered sprites in the collision detection.


Notice that in this table, collision detection does not change when you
select either single- or dual-playfield mode. Collision detection depends
only on the actual bits present in the odd-numbered or even-numbered
bitplanes. The  [collision control register](hardware/7-collision-detection-how-collision-detection-is-controlled.md)  specifies how to handle the
bitplanes during collision detect.

