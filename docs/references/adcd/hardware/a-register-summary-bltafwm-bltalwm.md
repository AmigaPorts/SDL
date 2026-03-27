---
title: A Register Summary / BLTAFWM, BLTALWM
manual: hardware
chapter: hardware
section: a-register-summary-bltafwm-bltalwm
functions: []
libraries: []
---

# A Register Summary / BLTAFWM, BLTALWM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
BLTAFWM    044      W       A      Blitter first-word mask for source A
BLTALWM    046      W       A      Blitter last-word mask for source A


                 The patterns in these two registers are ANDed with
                 the first and last words of each line of data from
                 source A into the blitter. A zero in any bit
                 overrides data from source A.  These registers
                 should be set to all 1s for fill mode or for
                 line-drawing mode.
