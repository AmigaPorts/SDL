---
title: 6 / Function Generator / Designing the LF Control Byte with Minterms
manual: hardware
chapter: hardware
section: 6-function-generator-designing-the-lf-control-byte-with
functions: []
libraries: []
---

# 6 / Function Generator / Designing the LF Control Byte with Minterms

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One approach to designing the LF control byte uses logic equations. Each
of the rows in the  [truth table](hardware/6-blitter-hardware-function-generator.md)  corresponds to a "minterm", which is a
particular assignment of values to the A, B, and C bits.  For instance,
the first minterm is usually written:

     ___
     ABC
or "not A and not B and not C".  The last is written as ABC.

   Blitter logic.
   --------------
   Two terms that are adjacent are AND'ed, and two terms that are
   separated by "+" are OR'ed. AND has a higher precedence, so AB + BC
   is equal to (AB) + (BC).

Any function can be written as a sum of minterms.  If we wanted to
calculate the function where D is one when the A bit is set and the C bit
is clear, or when the B bit is set, we can write that as:

      _
     AC + B
or "A and not C or B".  Since "1 and A" is "A":
```c
          _
     D = AC + B
             _
     D = A(1)C + (1)B(1)
                  _                  _
```
Since either A or A is true (1 = A + A), and similarly for B, and C; we
can expand the above equation further:

```c
             _
     D = A(1)C + (1)B(1)
               _ _        _       _
     D = A(B + B)C + (A + A)B(C + C)
           _    __          _    _      _
     D = ABC + ABC + AB(C + C) + AB(C + C)
           _    __           _   _     _ _
     D = ABC + ABC + ABC + ABC + ABC + ABC
```
After eliminating duplicates, we end up with the five minterms:

```c
      _         _    __         _     _ _
     AC + B = ABC + ABC + ABC + ABC + ABC
```
These correspond to  [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md)  bit positions of 6, 4, 7, 3, and 2,
according to our  [truth table](hardware/6-blitter-hardware-function-generator.md) , which we would then set, and clear the
rest.

The wide range of logic operations allow some sophisticated graphics
techniques.  For instance, you can move the image of a car across some
pre-existing building images with a few blits. Producing this effect
requires predrawn images of the car, the buildings (or background), and a
car "mask" that contains bits set wherever the car image is not
transparent.  This mask can be visualized as the shadow of the car from a
light source at the same position as the viewer.

   About mask bitplanes.
   ---------------------
   The mask for the car need only be a single bitplane regardless of the
   depth of the background bitplane. This mask can be used in turn on
   each of the background bitplanes.

To animate the car, first save the background image where the car will be
placed. Next copy the car to its first location with another blit.  Your
image is now ready for display.  To create the next image, restore the old
background, save the next portion of the background where the car will be,
and redraw the car, using three separate blits. (This technique works best
with beam-synchronized blits or double buffering.)

To temporarily save the background, copy a rectangle of the background
(from the A channel, for instance) to some backup buffer (using the D
channel). In this case, the function we would use is "A", the standard
copy function.  From Table 6-1, we note that the corresponding LF code has
a value of $F0.

To draw the car, we might use the A  [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  to fetch the car mask,
the B  [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  to fetch the actual car data, the C DMA channel to
fetch the background, and the D [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  to write out the new image.

   Warning:
   --------
   We must fetch the destination background before we write it, as only
   a portion of a destination word might need to be modified, and there
   is no way to do a write to only a portion of a word.

When blitting the car to the background we would want to use a function
that, whenever the car mask (fetched with  [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  A) had a bit set,
we would pass through the car data from B, and whenever A did not have a
bit set, we would pass through the original background from C.  The
corresponding function, commonly referred to as the cookie-cut function,
      _
is AB+AC, which works out to an LF code value of $CA.

To restore the background and prepare for the next frame, we would copy
the information saved in the first step back, with the standard copy
function ($F0).

If you shift the data and the mask to a new location and repeat the above
three steps over and over, the car will appear to move across the
background (the buildings).

   NOTE:
   -----
   This may not be the most effective method of animation, depending on
   the application, but the cookie-cut function will appear often.

Table 6-1 lists some of the most common functions and their values, for
easy reference.



```c
                Table 6-1: Table of Common Minterm Values


          Selected      [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md)             Selected      [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md) 
          Equation      LF Code            Equation      LF Code
          --------      -------            --------      -------
          D = A           $F0              D =  AB         $C0
              _                                  _
          D = A           $0F              D =  AB         $30
                                                _
          D = B           $CC              D =  AB         $0C
              _                                 __
          D = B           $33              D =  AB         $03

          D = C           $AA              D =  BC         $88
              _                                  _
          D = C           $55              D =  BC         $44
                                                _
          D = AC          $A0              D =  BC         $22
               _                                __
          D = AC          $50              D =  AC         $11
              _                                     _
          D = AC          $0A              D =  A + B      $F3
              _                                 _   _
          D = AC          $05              D =  A + B      $3F
                                                    _
          D = A + B       $FC              D =  A + C      $F5
              _                                 _   _
          D = A + B       $CF              D =  A + C      $5F
                                                    _
          D = A + C       $FA              D =  B + C      $DD
              _                                 _   _
          D = A + C       $AF              D =  B + C      $77
                                                     _
          D = B + C       $EE              D =  AB + AC    $CA
              _
          D = B + C       $BB
```
