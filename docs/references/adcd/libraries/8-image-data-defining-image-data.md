---
title: 8 / / Image Data / Defining Image Data
manual: libraries
chapter: libraries
section: 8-image-data-defining-image-data
functions: []
libraries: []
---

# 8 / / Image Data / Defining Image Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Image data consists of binary data organized into a series of 16-bit
words.  The words must be sequential, where each successive word
represents bits that are displayed later in the image.  The image is
defined as follows:

  * The image is broken down into bitplanes.  Each bitplane is considered

    separately.
  * Within a single bitplane, each row of pixels is taken separately.

```c
    First, round the number of pixels up to the next even multiple of 16.
    This determines the number of words used to represent a single row of
    data.  For instance, an image that is 17 bits wide will require two
    16-bit words to represent each row.

    The leftmost 16 pixel values are placed in the first word, followed
    by the next 16 pixel values, and so on.  Any extra pixels at the end
    of the last word of the [ImageData](libraries/8-creating-images-image-structure.md) should be set to zero.
```
  * The first row of data is the topmost row of the low order bitplane.

    This is immediately followed by the second row, then the third, until
    all rows in the bitplane have been represented.
  * The data for the low order bitplane is followed immediately by the

    next to lowest, then the next, etc.
The color of each pixel in the image is directly related to the value in
one or more memory bits, depending upon how many bitplanes there are in
the image data and in which bitplanes of the screen or window the display
is displayed.

The color for a single pixel may be determined by combining the bits taken
from the same relative position within each of the bitplanes used to
define the image.  For each pixel, the system combines all the bits in the
same position to create a binary value that corresponds to one of the
system color registers.  This method of determining pixel color is called
color indirection, because the actual color value is not in the display
memory.  Instead, it is in color registers that are located somewhere else
in memory.

In many situations, the image and display will have different number of
bitplanes, which complicates the determination of the color value for a
given pixel.  For now, assume that the image and display have the same
number of bitplanes.  The more complex example will be covered below, in
the section "[Image Example](libraries/8-creating-images-image-example.md)".

If an image consists of only one bitplane and is displayed in a one
bitplane display, then wherever there is a 0 bit in the image data, the
color in color register zero is displayed and wherever there is a 1 bit,
the color in color register one is displayed.

In an image composed of two bitplanes, the color of each pixel is obtained
from a binary number formed by the values in two bits, one from the first
bitplane and one from the second bitplane.  If the bit in the first
bitplane is a 1 and the bit in the second bitplane is a 0, then the color
of that pixel will be taken from color register two (since 10 in binary is
two in decimal).  Again, the first bitplane describes all of the low order
bits for each pixel.  The second bitplane describes the next higher bit,
and so on.  This can be extended to any number of bitplanes.



```c
               Image Data           Hexadecimal Representation

    ************************········    F F F F    F F 0 0
    **····················**········    C 0 0 0    0 3 0 0
    **····················**········    C 0 0 0    0 3 0 0
    **····················**········    C 0 0 0    0 3 0 0
    **····················**········    C 0 0 0    0 3 0 0
    **····················**········    C 0 0 0    0 3 0 0
    **····················**········    C 0 0 0    0 3 0 0
    **····················**········    C 0 0 0    0 3 0 0
    **····················**········    C 0 0 0    0 3 0 0
    ************************········    F F F F    F F 0 0


     Figure 8-1: Rendering of the Following Example Image


     [simpleimage.c](libraries/lib-examples-simpleimage-c.md) 
```
