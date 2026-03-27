---
title: A Register Summary / SPRxDATA, SPRxDATB
manual: hardware
chapter: hardware
section: a-register-summary-sprxdata-sprxdatb
functions: []
libraries: []
---

# A Register Summary / SPRxDATA, SPRxDATB

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
SPRxDATA   144      W       D     Sprite x image data register A
SPRxDATB   146      W       D     Sprite x image data register B


```c
                 These registers buffer the sprite image data. They are
                 usually loaded by the sprite DMA channel but may be
                 loaded by either processor at any time.  When a
                 horizontal comparison occurs, the buffers are dumped
                 into shift registers and serially outputted to the
                 display, MSB first on the left.

                 NOTE: Writing to the A buffer enables (arms) the sprite.
                 Writing to the SPRxCTL register disables the sprite.
                 If enabled, data in the A and B buffers will be outputted
                 whenever the beam counter equals the sprite horizontal
                 position value in the  [SPRxPOS](hardware/a-register-summary-sprxctl-sprxpos.md)  register.
```
