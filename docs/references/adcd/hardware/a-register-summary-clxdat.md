---
title: A Register Summary / CLXDAT
manual: hardware
chapter: hardware
section: a-register-summary-clxdat
functions: []
libraries: []
---

# A Register Summary / CLXDAT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
CLXDAT     00E      R       D     Collision data register (read and clear)


```c
                 This address reads (and clears) the collision
                 detection register. The bit assignments are below.

                 NOTE: Playfield 1 is all odd-numbered enabled
                       bitplanes.  Playfield 2 is all even-numbered
                       enabled bitplanes

                 BIT#   COLLISIONS REGISTERED
                 -----  --------------------------
                 15     not used
                 14     Sprite 4 (or 5) to sprite 6 (or 7)
                 13     Sprite 2 (or 3) to sprite 6 (or 7)
                 12     Sprite 2 (or 3) to sprite 4 (or 5)
                 11     Sprite 0 (or 1) to sprite 6 (or 7)
                 10     Sprite 0 (or 1) to sprite 4 (or 5)
                 09     Sprite 0 (or 1) to sprite 2 (or 3)
                 08     Playfield 2 to sprite 6 (or 7)
                 07     Playfield 2 to sprite 4 (or 5)
                 06     Playfield 2 to sprite 2 (or 3)
                 05     Playfield 2 to sprite 0 (or 1)
                 04     Playfield 1 to sprite 6 (or 7)
                 03     Playfield 1 to sprite 4 (or 5)
                 02     Playfield 1 to sprite 2 (or 3)
                 01     Playfield 1 to sprite 0 (or 1)
                 00     Playfield 1 to playfield 2
```
