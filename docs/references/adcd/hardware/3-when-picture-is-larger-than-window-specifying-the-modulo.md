---
title: 3 / / When Picture is Larger than Window / Specifying the Modulo
manual: hardware
chapter: hardware
section: 3-when-picture-is-larger-than-window-specifying-the-modulo
functions: []
libraries: []
---

# 3 / / When Picture is Larger than Window / Specifying the Modulo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For a memory picture wider than the display window, you need to respecify
the modulo so that the correct data words are fetched for each line of the
display. As an example, assume the display window is the standard 320
pixels wide, so 40 bytes are to be displayed on each line. The big picture
in memory, however, is exactly twice as wide as the display window, or 80
bytes wide. Also, assume that you wish to display the left half of the big
picture. Figure 3-14 shows the relationship between the big picture and
the picture to be displayed.




       START                                                 START+78
          __________________________|___________________________
         |                          |                           |
         |<-------------------------+-------------------------->|
         |       Width of the bit-plane defined in RAM          |
         |                          |                           |
         |<------------------------>|                           |
         | Width of defined screen  |                           |
         | on which bit-plane data  |                           |
         |      is to appear        |                           |
         |                          |                           |
         |                          |                           |

           Figure 3-14: Memory Picture Larger than the Display
Because 40 bytes are to be fetched for each line, the data fetch for line
1 is as shown in Figure 3-15.

  _______________________________________________________________________
 |                                                                       |
 |   Data for line 1:                                                    |
 |                                                                       |
 | Location:     START      START+2       START+4    ...      START+38   |
 |               -----      -------       -------             --------   |
 |              leftmost   next word     next word          last display |
 |            display word                                      word     |
 |                                                                       |
 |                                                               /|\     |
 |                       Screen data fetch stops ( [DDFSTOP](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) ) for  |      |
 |                       each horizontal line after the last      |      |
 |                       word on the line has been fetched________|      |
 |_______________________________________________________________________|



```c
        Figure 3-15: Data Fetch for the First Line When Modulo = 40
```
At this point,  [BPLxPTH and BPLxPTL](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  contain the value START+40. The
modulo, which is 40, is added to the current value of the pointer so that
when it begins the data fetch for the next line, it fetches the data that
you intend for that line. The data fetch for line 2 is shown in Figure
3-16.

  _______________________________________________________________________
 |                                                                       |
 |   Data for line 2:                                                    |
 |                                                                       |
 | Location:    START+80     START+82     START+84    ...     START+118  |
 |              --------     --------     --------            ---------  |
 |              leftmost     next word    next word         last display |
 |            display word                                      word     |
 |_______________________________________________________________________|



```c
        Figure 3-16: Data Fetch for the Second Line When Modulo = 40
```
To display the right half of the big picture, you set up
 [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  routine to start the bitplane pointers at location
START+40 rather than START with the modulo remaining at 40. The data
layout is shown in Figures 3-17 and 3-18.

  _______________________________________________________________________
 |                                                                       |
 |   Data for line 1:                                                    |
 |                                                                       |
 | Location:    START+40     START+42     START+44    ...     START+78   |
 |              --------     --------     --------            --------   |
 |              leftmost     next word    next word         last display |
 |            display word                                      word     |
 |_______________________________________________________________________|



    Figure 3-17: Data Layout for First Line -- Right Half of Big Picture
Now, the bitplane pointers contain the value START+80. The modulo (40) is
added to the pointers so that when they begin the data fetch for the
second line, the correct data is fetched.

  _______________________________________________________________________
 |                                                                       |
 |   Data for line 2:                                                    |
 |                                                                       |
 | Location:    START+120    START+122    START+124    ...    START+158  |
 |              ---------    ---------    ---------           ---------  |
 |              leftmost     next word    next word         last display |
 |            display word                                      word     |
 |_______________________________________________________________________|



    Figure 3-18: Data Layout for Second Line -- Right Half of Big Picture
Remember, in high resolution mode, you need to fetch twice as many bytes
as in low resolution mode. For a normal-sized display, you fetch 80 bytes
for each horizontal line instead of 40.

