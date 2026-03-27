---
title: 3 / / Horizontal Scrolling / Specifying Amount of Delay
manual: hardware
chapter: hardware
section: 3-horizontal-scrolling-specifying-amount-of-delay
functions: []
libraries: []
---

# 3 / / Horizontal Scrolling / Specifying Amount of Delay

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The amount of delay in horizontal scrolling is controlled by bits 7-0 in
BPLCON1. You set the delay separately for each playfield; bits 3-0 for
playfield 1 (bitplanes 1, 3, and 5) and bits 7-4 for playfield 2
(bitplanes 2, 4, and 6).

   Warning:
   --------
   Always set all six bits, even if you have only one playfield.  Set
   3-0 and 7-4 to the same value if you are using only one playfield.

The following example sets the horizontal scroll delay to 7 for both
playfields.


        MOVE.W  #$77,BPLCON1+CUSTOM
