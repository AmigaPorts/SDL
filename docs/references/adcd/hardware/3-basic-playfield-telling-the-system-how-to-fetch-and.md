---
title: 3 / Basic Playfield / Telling the System How to Fetch and Display Data
manual: hardware
chapter: hardware
section: 3-basic-playfield-telling-the-system-how-to-fetch-and
functions: []
libraries: []
---

# 3 / Basic Playfield / Telling the System How to Fetch and Display Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After defining the size and position of the display window, you need to
give the system the on-screen location for data fetched from memory. To do
this, you describe the horizontal positions where each line starts and
stops and write these positions to the data-fetch registers. The
data-fetch registers have a four-pixel resolution (unlike the display
window registers, which have a one-pixel resolution). Each position
specified is four pixels from the last one. Pixel 0 is position 0; pixel 4
is position 1, and so on.

The data-fetch start and display window starting positions interact with
each other. It is recommended that data-fetch start values be restricted
to a programming resolution of 16 pixels (8 clocks in low resolution mode,
4 clocks in high resolution mode). The hardware requires some time after
the first data fetch before it can actually display the data. As a result,
there is a difference between the value of window start and data-fetch
start of 4.5  [color clocks](hardware/6-blitter-hardware-blitter-operations-and-system-dma.md).

   The normal low resolution DDFSTRT is ($0038).
   The normal high resolution DDFSTRT is ($003C).

Recall that the hardware resolution of display window start and stop is
twice the hardware resolution of data fetch:


```c
          $81
          ---  - 8.5 = $38
           2

          $81
          ---  - 4.5 = $3C
           2
```
The relationship between data-fetch start and stop is

   DDFSTRT = DDFSTOP - (8 * (word count - 1)) for low resolution
   DDFSTRT = DDFSTOP - (4 * (word count - 2)) for high resolution

The normal low resolution DDFSTOP is ($00D0). The normal high resolution
DDFSTOP is ($00D4).

The following example sets data-fetch start to $0038 and data-fetch stop
to $00D0 for a basic playfield.


```c
        LEA     CUSTOM,a0               ; Point to base hardware address
        MOVE.W  #$0038,DDFSTRT(a0)      ; Write to DDFSTRT
        MOVE.W  #$00D0,DDFSTOP(a0)      ; Write to DDFSTOP
```
You also need to tell the system exactly which bytes in memory belong on
each horizontal line of the display. To do this, you specify the modulo
value. Modulo refers to the number of bytes in memory between the last
word on one horizontal line and the beginning of the first word on the
next line. Thus, the modulo enables the system to convert bitplane data
stored in linear form (each data byte at a sequentially increasing memory
address) into rectangular form (one "line" of sequential data followed by
another line). For the basic playfield, where the playfield in memory is
the same size as the display window, the modulo is zero because the memory
area contains exactly the same number of bytes as you want to display on
the screen. Figures 3-10 and 3-11 show the basic bitplane layout in memory
and how to make sure the correct data is retrieved.

The bitplane address pointers ( [BPLxPTH and BPLxPTL](hardware/3-allocating-memory-for-bitplanes-ntsc-example-of-bitplane.md) ) are used by the
system to fetch the data to the screen. These pointers are dynamic; once
the data fetch begins, the pointers are continuously incremented to point
to the next word to be fetched (data is fetched two bytes at a time). When
the end-of-line condition is reached (defined by the data-fetch register,
DDFSTOP) the modulo is added to the bitplane pointers, adjusting the
pointer to the first word to be fetched for the next horizontal line.

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
 |                       Screen data fetch stops (DDFSTOP) for    |      |
 |                       each horizontal line after the last      |      |
 |                       word on the line has been fetched________|      |
 |_______________________________________________________________________|



```c
        Figure 3-10: Data Fetched for the First Line When Modulo = 0
```
After the first line is fetched, the bitplane pointers
 [BPLxPTH and BPLxPTL](hardware/3-allocating-memory-for-bitplanes-ntsc-example-of-bitplane.md)  contain the value START+40. The modulo (in this
case, 0) is added to the current value of the pointer, so when the pointer
begins the data fetch for the next line, it fetches the data you want on
that line. The data for the next line begins at memory location START+40.

  _______________________________________________________________________
 |                                                                       |
 |   Data for line 2:                                                    |
 |                                                                       |
 | Location:    START+40     START+42     START+44    ...     START+78   |
 |              --------     --------     --------            --------   |
 |              leftmost     next word    next word         last display |
 |            display word                                      word     |
 |_______________________________________________________________________|



```c
       Figure 3-11: Data Fetched for the Second Line When Modulo = 0
```
Note that the pointers always contain an even number, because data is
fetched from the display a word at a time.

There are two modulo registers -- BPL1MOD for the odd-numbered bitplanes
and BPL2MOD for the even-numbered bitplanes. This allows for differing
modulos for each playfield in  [dual-playfield mode](hardware/3-playfield-hardware-forming-a-dual-playfield-display.md) . For normal
applications, both BPL1MOD and BPL2MOD will be the same.

The following example sets the modulo to 0 for a low resolution playfield
with one bitplane. The bitplane is odd-numbered.



```c
        MOVE.W  #0,BPL1MOD+CUSTOM       ; Set modulo to 0
```
 [Data Fetch in High resolution Mode](hardware/3-how-to-fetch-and-display-data-in-high-resolution-mode.md) 
 [Modulo in Interlaced Mode](hardware/3-how-to-fetch-and-display-data-modulo-in-interlaced-mode.md) 

