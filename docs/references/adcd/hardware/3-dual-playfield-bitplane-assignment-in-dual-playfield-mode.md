---
title: 3 / Dual-playfield / Bitplane Assignment in Dual-Playfield Mode
manual: hardware
chapter: hardware
section: 3-dual-playfield-bitplane-assignment-in-dual-playfield-mode
functions: []
libraries: []
---

# 3 / Dual-playfield / Bitplane Assignment in Dual-Playfield Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The three odd-numbered bitplanes (1, 3, and 5) are grouped together by the
hardware and may be used in playfield 1. Likewise, the three even-numbered
bitplanes (2, 4, and 6) are grouped together and may be used in playfield
2. The bitplanes are assigned alternately to each playfield, as shown in
Figure 3-13.

   About dual-playfield bitplanes.
   -------------------------------
   In high resolution mode, you can have up to two bitplanes in each
   playfield -- bitplanes 1 and 3 in playfield 1 and bitplanes 2 and 4
   in playfield 2.



        Number of
        Bitplanes
       "turned on."     Plafield 1 *            Playfield 2 *
       ------------------------------------------------------
            0              none                     none
                       ____________
                      |            |
            1         | 1          |
                      |            |
                      |____________|
                       ____________            ____________
                      |            |          |            |
            2         | 1          |          | 2          |
                      |            |          |            |
                      |____________|          |____________|
                       ____________            ____________
                      |            |          |            |
            3         | 1 _________|__        | 2          |
                      |  |            |       |            |
                      |__| 3          |       |____________|
                         |            |
                         |____________|
                       ____________            ____________
                      |            |          |            |
            4         | 1 _________|__        | 2 _________|__
                      |  |            |       |  |            |
                      |__| 3          |       |__| 4          |
                         |            |          |            |
                         |____________|          |____________|
                       ____________            ____________
                      |            |          |            |
            5         | 1 _________|__        | 2 _________|__
                      |  |            |       |  |            |
                      |__| 3 _________|__     |__| 4          |
                         |  |            |       |            |
                         |__| 5          |       |____________|
                            |            |
                            |____________|
                       ____________            ____________
                      |            |          |            |
            6         | 1 _________|__        | 2 _________|__
                      |  |            |       |  |            |
                      |__| 3 _________|__     |__| 4 _________|__
                         |  |            |       |  |            |
                         |__| 5          |       |__| 6          |
                            |            |          |            |
                            |____________|          |____________|


                    * Note: Either playfield may be placed "in front of"
                            or "behind" the other using the "swap-bit."


        Figure 3-13: How Bitplanes Are Assigned to Dual Playfields
