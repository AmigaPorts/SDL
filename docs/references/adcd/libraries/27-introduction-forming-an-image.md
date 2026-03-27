---
title: 27 / Introduction / Forming an Image
manual: libraries
chapter: libraries
section: 27-introduction-forming-an-image
functions: []
libraries: []
---

# 27 / Introduction / Forming an Image

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To create an image, you write data (that is, you "draw") into a memory
area in the computer.  From this memory area, the system can retrieve the
image for display.  You tell the system exactly how the memory area is
organized, so that the display is correctly produced.  You use a block of
memory words at sequentially increasing addresses to represent a
rectangular region of data bits.  The following figure shows the contents
of three example memory words: 0 bits are shown as blank rectangles, and
1 bits as filled-in rectangles.




```c
                   Contents of three memory words,
                     all adjacent to each other.
             Note that N is expressed as a byte-address.

                   _______________________________
                  |_|_|_|_|_|_|_|#|#|_|_|_|_|_|_|_|

                      Memory Location N (0x0180)

                   _______________________________
                  |_|_|_|_|_|#|#|#|#|#|#|_|_|_|_|_|

                     Memory Location N+2 (0x07E0)

                   _______________________________
                  |_|_|_|_|_|_|_|#|#|_|_|_|_|_|_|_|

                     Memory Location N+4 (0x0180)


                  Figure 27-5: Sample Memory Words
```
The system software lets you define linear memory as rectangular regions,
called bitplanes.  The figure below shows how the system would organize
three sequential words in memory into a rectangular bitplane with
dimensions of 16 x 3 pixels.



          _______________________________
         |_|_|_|_|_|_|_|#|#|_|_|_|_|_|_|_|  Memory Location N
         |_|_|_|_|_|#|#|#|#|#|#|_|_|_|_|_|  Memory Location N+2
         |_|_|_|_|_|_|_|#|#|_|_|_|_|_|_|_|  Memory Location N+4


       Figure 27-6: A Rectangular Bitplane Made from 3 Memory Words
The following figure shows how 4,000 words (8,000 bytes) of memory can be
organized to provide enough bits to define a single bitplane of a
full-screen, low-resolution video display (320 x 200).

  _______________________________         _______________________________
 |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_| ----> |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|

         Memory Location N                     Memory Location N+38
  _______________________________         _______________________________
 |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_| ----> |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|

       Memory Location N+40          |         Memory Location N+78
                                     |
                                     |
                                    \|/
  _______________________________         _______________________________
 |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_| ----> |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|



      Memory Location N+7960                  Memory Location N+7998


      Figure 27-7: Bitplane for a Full-screen, Low-resolution Display
Each memory data word contains 16 data bits. The color of each pixel on a
video display line is directly related to the value of one or more data
bits in memory, as follows:

  * If you create a display in which each pixel is related to only

    one data bit, you can select from only two possible colors,
    because each bit can have a value of only 0 or 1.
  * If you use two bits per pixel, there is a choice of four

    different colors because there are four possible combinations of
    the values of 0 and 1 from each of the two bits.
  * If you specify three, four, or five bits per pixel, you will

    have eight, sixteen, or thirty-two possible choices of a color
    for a pixel.
  * If you use six bits per pixel, then depending on the video mode

```c
    (EHB or HAM), you will have sixty-four or 4,096 possible choices
    for a pixel.
```
To create multicolored images, you must tell the system how many bits are
to be used per pixel. The number of bits per pixel is the same as the
number of bitplanes used to define the image.

As the video beam sweeps across the screen, the system retrieves one data
bit from each bitplane. Each of the data bits is taken from a different
bitplane, and one or more bitplanes are used to fully define the video
display screen. For each pixel, data-bits in the same x,y position in each
bitplane are combined by the system hardware to create a binary value.
This value determines the color that appears on the video display for that
pixel.



      _______________
     |
     | ‘          bit-plane 5
     | _\_____________
     ||  \
     || ‘ \        bit-plane 4
      | _\_\_____________
      ||  \ \
      || ‘ \ \      bit-plane 3
       | _\_\_\___________                   Bits from
       ||  \ \ \                               planes     Color
       || ‘ \ \ \    bit-plane 2             5,4,3,2,1  Registers
        | _\_\_\_\__________
        ||  \ \ \ \                                     _________
        || ‘ \ \ \ \  bit-plane 1              00000   |_________|
         | ^\ \ \ \ \                          00001   |_________|
         | | \ \ \ \ \                         00010   |_________|
         | |  \ \ \ \ \                        00011   |_________|
           |   \ \ \ \ \  ___  _ _ _ _ _       00100   |_________|
           |    \ \ \ \ \|   |          |        -     |         |
          One    \ \ \ \ | 1 |                   -     |    |    |
         Pixel    \ \ \ \|___|          |        -     |         |
                   \ \ \ \|   |                  -     |    |    |
                    \ \ \ | 1 |         |        -     |         |
                     \ \ \|___|                  -     |   \|/   |
                      \ \ \|   |        |    \   -     |_________|
                       \ \ | 0 |         - - - 11000   |#########|
                        \ \|___|        |    / 11001   |_________|
                         \ \|   |              11010   |_________|
                          \ | 0 |       |      11011   |_________|
                           \|___|              11100   |_________|
                            \|   |      |      11101   |_________|
                             | 0 |             11110   |_________|
                             |___| _ _ _|      11111   |_________|


        Figure 27-8: Bits from Each Bitplane Select Pixel Color
You will find more information showing how the data bits actually select
the color of the displayed pixel in the section below called
"[ViewPort Color Selection](libraries/27-display-routines-and-structures-viewport-color-selection.md)."

