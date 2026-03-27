---
title: 4 / / Screen Position / Horizontal Position
manual: hardware
chapter: hardware
section: 4-screen-position-horizontal-position
functions: []
libraries: []
---

# 4 / / Screen Position / Horizontal Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A sprite's horizontal position (X value) can be at any pixel on the screen
from 0 to 447. To be visible, however, an object must be within the
boundaries of the  [playfield display window](hardware/3-forming-basic-playfield-defining-the-size-of-the-display.md) . In the examples in this
chapter, a window with horizontal positions from pixel 64 to pixel 383 is
used (that is, each line is 320 pixels long).  [Larger or smaller windows](hardware/3-playfield-hardware-bitplanes-and-display-windows-of-all.md) 
can be defined as required, but it is recommended that you read the
"Playfield Hardware chapter" before attempting to do so. A larger area is
actually scanned by the video beam but is not usually visible on the
screen.

If you specify an X value for a sprite that takes it outside the display
window, then part or all of the sprite may not appear on the screen. This
is sometimes desirable; such a sprite is said to be " [clipped](hardware/4-screen-position-clipped-sprites.md) ."

To make a sprite appear in its correct on-screen horizontal position in
the display window, simply add its left offset to the desired X value. In
the example given above, this would involve adding 64 to the X value. For
example, to make the upper leftmost pixel of a sprite appear at a position
94 pixels from the left edge of the screen, you would perform this
calculation:

 Desired X position + horizontal-offset of display window ~= 94 + 64 = 158

Thus, 158 becomes the X value, which will be written into the
 [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md) .

   Counting Pixels.
   ----------------
   The X position represents the location of the very first (leftmost)
   pixel in the full 16-bit wide sprite. This is always the case, even
   if the leftmost pixels are specified as transparent and do not appear
   on the screen.

If the sprite shown in Figure 4-2 were located at an X value of 158, the
actual image would begin on-screen four pixels later at 162.  The first
four pixels in this sprite are transparent and allow the background to
show through.



                |-- 4 --|
                |pixels |
                 _______________________________
                |_|_|_|_|_|_|_|#|_|_|_|_|_|_|_|_|
                |_|_|_|_|_|_|o|#|o|_|_|_|_|_|_|_|
                |_|_|_|_|_|o|o|#|o|o|_|_|_|_|_|_|
                |_|_|_|_|#|#|#|_|#|#|#|_|_|_|_|_|
                |_|_|_|_|_|o|o|#|o|o|_|_|_|_|_|_|
                |_|_|_|_|_|_|o|#|o|_|_|_|_|_|_|_|
                |_|_|_|_|_|_|_|#|_|_|_|_|_|_|_|_|
                |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|

                |                               |
                |--------- 16 pixels -----------|


                 Figure 4-2: Position of Sprites
