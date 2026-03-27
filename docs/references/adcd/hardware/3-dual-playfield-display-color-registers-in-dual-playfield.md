---
title: 3 / Dual-playfield Display / Color Registers in Dual-Playfield Mode
manual: hardware
chapter: hardware
section: 3-dual-playfield-display-color-registers-in-dual-playfield
functions: []
libraries: []
---

# 3 / Dual-playfield Display / Color Registers in Dual-Playfield Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When you are using dual playfields, the hardware interprets color numbers
for playfield 1 from the bit combinations of bitplanes 1, 3, and 5.  Bits
from PLANE 5 have the highest significance and form the most significant
digit of the color register number. Bits from PLANE 0 have the lowest
significance. These bit combinations select the first eight color
registers from the color palette as shown in Table 3-10.



                             PLAYFIELD 1

                          Bit          Color
                      Combination     Selected
                      -----------     --------
                          000     Transparent mode
                          001          COLOR1
                          010          COLOR2
                          011          COLOR3
                          100          COLOR4
                          101          COLOR5
                          110          COLOR6
                          111          COLOR7


     Table 3-10: Playfield 1 Color Registers -- Low resolution Mode
The hardware interprets color numbers for playfield 2 from the bit
combinations of bitplanes 2, 4, and 6. Bits from PLANE 6 have the highest
significance. Bits from PLANE 2 have the lowest significance. These bit
combinations select the color registers from the second eight colors in
the color table as shown in Table 3-11.



                             PLAYFIELD 2

                          Bit          Color
                      Combination     Selected
                      -----------     --------
                          000     Transparent mode
                          001          COLOR9
                          010          COLOR10
                          011          COLOR11
                          100          COLOR12
                          101          COLOR13
                          110          COLOR14
                          111          COLOR15


     Table 3-11: Playfield 2 Color Registers -- Low resolution Mode
Combination 000 selects transparent mode, to show the color of whatever
object (the other playfield, a sprite, or the background color) may be
"behind" the playfield.

Table 3-12 shows the color registers for high resolution, dual-playfield
mode.


                             PLAYFIELD 1

                          Bit          Color
                      Combination     Selected
                      -----------     --------
                          00      Transparent mode
                          01           COLOR1
                          10           COLOR2
                          11           COLOR3


                             PLAYFIELD 2

                          Bit          Color
                      Combination     Selected
                      -----------     --------
                          00      Transparent mode
                          01           COLOR9
                          10           COLOR10
                          11           COLOR11


     Table 3-12: Playfields 1 and 2 Color Registers -- High resolution Mode
