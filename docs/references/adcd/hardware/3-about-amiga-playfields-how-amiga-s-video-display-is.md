---
title: 3 / About Amiga Playfields / How Amiga's Video Display is Produced
manual: hardware
chapter: hardware
section: 3-about-amiga-playfields-how-amiga-s-video-display-is
functions: []
libraries: []
---

# 3 / About Amiga Playfields / How Amiga's Video Display is Produced

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga produces its video displays with raster display techniques. The
picture you see on the screen is made up of a series of horizontal video
lines displayed one after the other.  Each horizontal video line is made
up of a series of pixels.  You create a graphic display by defining one or
more bitplanes in memory and filling them with "1"s and "0"s.  The
combination of the "1"s and "0"s will determine the colors in your display.

        _________________________
    |  |                         |
    |  | ->->->->->->->->->->->- |
    |  | ----------------------- |  Each line represents one sweep of an
    |  | ----------------------- |  electron beam which is "painting" the
    |  |         -------         |  picture as it goes along.
    |  |         -------         |
    |  |      Video Picture      |  The video beam produces each line by
    |  |         -------         |  sweeping from left to right.  It
    |  |         -------         |  produces the full screen by sweeping
    |  | ----------------------- |  the beam from the top to the bottom,
    |  | ----------------------- |  one line at a time.
    |  | ----------------------- |
   \|/ |_________________________|




          Figure 3-1: How the Video Display Picture Is Produced
The video beam produces about 262 video lines from top to bottom, of which
200 normally are visible on the screen with an NTSC system.  With a PAL
system, the beam produces 312 lines, of which 256 are normally visible.
Each complete set of lines (262/NTSC or 312/PAL) is called a display
field. The field time, i.e. the time required for a complete display field
to be produced, is approximately 1/60th of a second for an NTSC system and
approximately 1/50th of a second for PAL. Between display fields, the
video beam traverses the lines that are not visible on the screen and
returns to the top of the screen to produce another display field.

The display area is defined as a grid of pixels.  A pixel is a single
picture element, the smallest addressable part of a screen display.  The
drawings below show what a pixel is and how pixels form displays.



        _________________________
       |                         |
       |                         |
       |    ‘<- - - - - - - - - -|- The picture is formed from many
       |                         |  elements.  Each element is called
       |                         |  a pixel.
       |                         |
       |                         |
       |                         |
       |               ‘         |
       |              ‘‘‘<- - - -|- Pixels are used together to build
       |               ‘         |  larger graphic objects.
       |                         |
       |_________________________|

        _________________________      _________________________
       |                         |    |                         |
       |      _                  |    |                         |
       |<- - |_| - - - - - - - ->|    |<- - - ‘ - - - - - - - ->|
       |                         |    |                         |
       |  320 pixels             |    |   640 pixels            |
       |                         |    |                         |
       |                         |    |                         |
       |                         |    |                         |
       |                         |    |                         |
       |                         |    |                         |
       |                         |    |                         |
       |                         |    |                         |
       |_________________________|    |_________________________|

     In normal resolution mode, 320   In high resolution mode, 640
     pixels fill a horizontal line.   pixels fill a horizontal line.


                     Figure 3-2: What Is a Pixel?
The Amiga offers a choice in both horizontal and vertical resolutions.
Horizontal resolution can be adjusted to operate in low resolution or high
resolution mode. Vertical resolution can be adjusted to operate in
interlaced or non-interlaced mode.

*  In low resolution mode, the normal playfield has a width of 320
   pixels.

*  High resolution mode gives finer horizontal resolution -- 640 pixels
   in the same physical display area.

*  In non-interlaced mode, the normal NTSC playfield has a height of 200
   video lines.   The normal PAL screen has a height of 256 video lines.

*  Interlaced mode gives finer vertical resolution -- lines in the same
   physical display area in NTSC and 512 for PAL.

These modes can be combined, so you can have, for instance, an interlaced,
high resolution display.

Note that the dimensions referred to as "normal" in the previous paragraph
are nominal dimensions and represent the normal values you should expect
to use.  Actually, you can display larger playfields; the
 [maximum dimensions](hardware/3-bitplanes-and-windows-of-all-sizes-maximum-display-window.md)  are given in the section called
 [Bitplanes and Playfields of All Sizes](hardware/3-playfield-hardware-bitplanes-and-display-windows-of-all.md) . Also, the dimensions of the
playfield in memory are often larger than the playfield displayed on the
screen. You choose which part of this larger memory picture to display by
specifying a different size for the display window.

A playfield taller than the screen can be scrolled, or moved smoothly, up
or down.  A playfield wider than the screen can be scrolled horizontally,
from left to right or right to left.  Scrolling is described in the
section called  [Moving (Scrolling) Playfields](hardware/3-playfield-hardware-moving-scrolling-playfields.md) .

In the Amiga graphics system, you can have up to thirty-two different
colors in a single playfield, using normal display methods. You can
control the color of each individual pixel in the playfield display by
setting the bit or bits that control each pixel. A display formed in this
way is called a bitmapped display.

For instance, in a two-color display, the color of each pixel is
determined by whether a single bit is on or off. If the bit is 0, the
pixel is one user-defined color; if the bit is 1, the pixel is another
color. For a four-color display, you build two bitplanes in memory. When
the playfield is displayed, the two bitplanes are overlapped, which means
that each pixel is now two bits deep. You can combine up to five bitplanes
in this way. Displays made up of three, four, or five bitplanes allow a
choice of eight, sixteen, or thirty-two colors, respectively.

The color of a pixel is always determined by the binary combination of the
bits that define it. When the system combines bitplanes for display, the
combination of bits formed for each pixel corresponds to the number of a
color register. This method of coloring pixels is called color
indirection. The Amiga has thirty-two color registers, each containing
bits defining a user-selected color (from a total of 4,096 possible
colors).

Figure 3-3 shows how the combination of up to five bitplanes forms a code
that selects which one of the thirty-two registers to use to display the
color of a playfield pixel.



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


           Figure 3-3: How Bitplanes Select a Color
Values in the highest numbered bitplane have the highest significance in
the binary number. As shown in Figure 3-4, the value in each pixel in the
highest-numbered bitplane forms the leftmost digit of the number. The
value in the next highest-numbered bitplane forms the next bit, and so on.




     SAMPLE DATA FOR
       FOUR PIXELS

      1   1   0   0          Data in bitplane 5 -- most significant
      1   0   1   0          Data in bitplane 4
      1   0   0   1          Data in bitplane 3
      0   1   1   1          Data in bitplane 2
      0   0   1   0          Data in bitplane 1 -- least significant

      |   |   |   |
      |   |   |   |
      |   |   |   |_________________ Value 6 -- COLOR6
      |   |   |_____________________ Value 11 -- COLOR11
      |   |_________________________ Value 18 -- COLOR18
      |_____________________________ Value 28 -- COLOR28


     Figure 3-4: Significance of Bitplane Data in Selecting Colors
You also have the choice of defining two separate playfields, each formed
from up to three bitplanes. Each of the two playfields uses a separate set
of eight different colors. This is called  [dual-playfield mode](hardware/3-playfield-hardware-forming-a-dual-playfield-display.md) .

