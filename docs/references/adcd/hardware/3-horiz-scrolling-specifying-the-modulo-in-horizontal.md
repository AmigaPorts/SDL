---
title: 3 / / Horiz. Scrolling / Specifying the Modulo in Horizontal Scrolling
manual: hardware
chapter: hardware
section: 3-horiz-scrolling-specifying-the-modulo-in-horizontal
functions: []
libraries: []
---

# 3 / / Horiz. Scrolling / Specifying the Modulo in Horizontal Scrolling

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As always, the modulo is two counts less than the difference between the
address of the next word you want to fetch and the address of the last
word that was fetched. As an example for horizontal scrolling, let us
assume a 40-byte display in an 80-byte "big picture." Because horizontal
scrolling requires a data fetch of two extra bytes, the data for each line
will be 42 bytes long.



       START                     START+38                    START+78
          __________________________|___________________________
         |                          |                           |
         |                          |                           |
         |<--DISPLAY WINDOW width-->|                           |
         |                          |                           |
         |                          |                           |
         |                          |                           |
         |                          |                           |
         |<----------------MEMORY PICTURE width---------------->|
         |                          |                           |
         |                          |                           |

        Figure 3-25: Memory Picture Larger Than the Display Window
  _______________________________________________________________________
 |                                                                       |
 |   Data for line 1:                                                    |
 |                                                                       |
 | Location:     START        START+2      START+4    ...     START+40   |
 |               -----        -------      -------            --------   |
 |              leftmost     next word    next word         last display |
 |            display word                                      word     |
 |_______________________________________________________________________|



           Figure 3-26: Data for Line 1 - Horizontal Scrolling
At this point, the bitplane pointers contain the value START+42. Adding
the modulo of 38 gives the correct starting point for the next line.

  _______________________________________________________________________
 |                                                                       |
 |   Data for line 2:                                                    |
 |                                                                       |
 | Location:    START+80     START+82     START+84    ...     START+120  |
 |              --------     --------     --------            ---------  |
 |              leftmost     next word    next word         last display |
 |            display word                                      word     |
 |_______________________________________________________________________|



           Figure 3-27: Data for Line 2 -- Horizontal Scrolling
In the  [BPLxMOD](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  registers you set the modulo for each bitplane used.

