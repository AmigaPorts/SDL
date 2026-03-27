---
title: 27 / Display Routines and Structures / Viewport Size Specifications
manual: libraries
chapter: libraries
section: 27-display-routines-and-structures-viewport-size
functions: []
libraries: []
---

# 27 / Display Routines and Structures / Viewport Size Specifications

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following figure illustrates that the variables [DHeight](libraries/27-viewport-size-specifications-viewport-height.md), and [DWidth](libraries/27-viewport-size-specifications-viewport-width.md)
specify the size of a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).




```c
                     DISPLAY BIT-PLANES
                  _________________________
                 |                         |
                 |  _____________________  |
                 | |                     | |
                 | |                     | |
                 | |                     | |
                 | |                     | |
                 | |                     | |
                 | |_____________________| |
                 |   __________________ _ _|_ _ _ _ _ _
                 |  |                  |   |       |
                 |  |                  |   |       |
                 |  |                  |   |
                 |  |                  |   |   DHeight = how
                 |  |                  |   |  many lines tall
                 |  |                  |   |
                 |  |                  |   |       |
                 |  |__________________|_ _|_ _ _ _|_ _
                 |                         |
                 |__|__________________|___|

                    |                  |

                    |-- DWidth = how --|
                      many pixels wide
                    |                  |

         Figure 27-11: Size Definition for a ViewPort
```
 [ViewPort Height](libraries/27-viewport-size-specifications-viewport-height.md)    [ViewPort Width](libraries/27-viewport-size-specifications-viewport-width.md) 

