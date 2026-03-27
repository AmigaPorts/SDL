---
title: 6 Blitter Hardware / Line Mode
manual: hardware
chapter: hardware
section: 6-blitter-hardware-line-mode
functions: []
libraries: []
---

# 6 Blitter Hardware / Line Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In addition to all of the functions described above, the blitter can draw
patterned lines.  The line draw mode is selected by setting bit 0
(LINEMODE) of  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md) , which changes the meaning of some other bits in
[BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md)  and  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md) .  In line draw mode, the blitter can draw lines up
to 1024 pixels long, it can draw them in a variety of modes, with a
variety of textures, and can even draw them in a special way for simple
 [area fill](hardware/6-blitter-hardware-area-fill-mode.md) .

Many of the blitter registers serve other purposes in line-drawing mode.
Consult  [Appendix A](hardware/amiga-hardware-reference-manual-a-register-summary.md)  for more detailed descriptions of the use of these
registers and control bits.  You should also see Appendix C for the
 [new limits](hardware/c-ecs-hardware-and-the-graphics-library-big-blits.md)  on line-drawing mode in the Enhanced Chip Set (ECS).

In line mode, the blitter draws a line from one point to another, which
can be viewed as a vector.  The direction of the vector can lie in any of
the following eight octants.  (In the following diagram, the standard
Amiga convention is used, with x increasing towards the right and y
increasing down.) The number in parenthesis is the octant numbering; the
other number represents the value that should be placed in bits 4 through
2 of  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md) .



```c
                               |
                               |
                      \   (2)  |  (1)   /
                       \       |       /
                        \   3  |  1   /
                         \     |     /
                          \    |    /
                     (3)   \   |   /   (0)
                            \  |  /
                        7    \ | /    6
                              \|/
                  -------------*-------------
                              /|\
                        5    / | \    4
                            /  |  \
                     (4)   /   |   \   (7)
                          /    |    \
                         /     |     \
                        /   2  |  0   \
                       /       |       \
                      /   (5)  |  (6)   \
                               |
                               |

              Figure 6-8: Octants for Line Drawing
```
Line drawing based on octants is a simplification that takes advantage of
symmetries between x and -x, y and -y. The following Table lists the
octant number and corresponding values:




```c
      Table 6-3:  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  Code Bits for Octant Line Drawing


                [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  Code Bits      Octant #
               -------------------       --------
                     4  3  2
                     -  -  -
                     1  1  0               0
                     0  0  1               1
                     0  1  1               2
                     1  1  1               3
                     1  0  1               4
                     0  1  0               5
                     0  0  0               6
                     1  0  0               7
```
We initialize  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  bits 4 through 2 according to the above Table.
Now, we introduce the variables dx and dy and set them to the absolute
values of the difference between the x coordinates and the y coordinates
of the endpoints of the line, respectively.

dx = abs(x2 - x1) ;
dy = abs(y2 - y1) ;

Now, we rearrange them if necessary so dx is greater than dy.

if (dx < dy)

```c
        {
        temp = dx ;
        dx = dy ;
        dy = temp ;
        }
```
Alternately, set dx and dy as follows:

dx = max(abs(x2 - x1), abs(y2 - y1)) ;
dy = min(abs(x2 - x1), abs(y2 - y1)) ;

These calculations have the effect of "normalizing" our line into octant
0; since we have already informed the blitter of the real octant to use,
it has no difficulty drawing the line.

We initialize the A  [pointer register](hardware/6-blitter-hardware-dma-channels.md)  to 4 * dy - 2 * dx. If this value
is negative, we set the sign bit (SIGNFLAG in  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md) ), otherwise we
clear it.  We set the A   [modulo register](hardware/6-blitter-hardware-dma-channels.md)  to 4 * (dy - dx) and the B
 [modulo register](hardware/6-blitter-hardware-dma-channels.md)  to 4 * dy.

The A  [data register](hardware/6-blitter-hardware-dma-channels.md)  should be preloaded with $8000. Both word  [masks](hardware/6-blitter-hardware-shifts-and-masks.md) 
should be set to $FFFF. The A  [shift](hardware/6-blitter-hardware-shifts-and-masks.md)  value should be set to the x
coordinate of the first point (x1) modulo 15.

The B  [data register](hardware/6-blitter-hardware-dma-channels.md)  should be initialized with the line texture pattern,
if any, or $FFFF for a solid line. The B  [shift](hardware/6-blitter-hardware-shifts-and-masks.md)  value should be set to
the bit number at which to start the line texture (zero means the last
significant bit.)

The C and D  [pointer registers](hardware/6-blitter-hardware-dma-channels.md)  should be initialized to the word
containing the first pixel of the line; the C and D  [modulo registers](hardware/6-blitter-hardware-dma-channels.md) 
should be set to the width of the bitplane in bytes.

The SRCA, SRCC, and DEST bits of  [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md)  should be set to one, and the
SRCB flag should be set to zero.  The OVFLAG should be cleared. If only a
single bit per horizontal row is desired, the ONEDOT bit of  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md) 
should be set; otherwise it should be cleared.

The logic function remains.  The C  [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  represents the original
source, the A channel the bit to set in the line, and the B channel the
pattern to draw.  Thus, to draw a line, the function
        _
   AB + A

is the most common.  To draw the line using exclusive-or mode, so it can
be easily erased by drawing it again, the function
     _   _
   ABC + AC

can be used.

We set the blit height to the length of the line, which is dx + 1. The
width must be set to two for all line drawing.  (Of course, the  [BLTSIZE](hardware/6-blitter-hardware-dma-channels.md) 
register should not be written until the very end, when all other
registers have been filled.)

 [Register Summary for Line Mode](hardware/6-line-mode-register-summary-for-line-mode.md) 

