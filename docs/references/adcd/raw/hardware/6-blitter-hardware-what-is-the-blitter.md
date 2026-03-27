# 6 Blitter Hardware / What is the Blitter?


The blitter is one of the two coprocessors in the Amiga.  Part of the
Agnus chip, it is used to copy rectangular blocks of memory around and to
draw lines.  When copying memory, it is approximately twice as fast as the
68000, able to move almost four megabytes per second.  It can draw lines
at almost a million pixels per second.

In block move mode, the blitter can perform any logical operation on up to
three source areas, it can  [shift](../Hardware_Manual_guide/node011F.html)  up to two of the source areas by one to
fifteen bits, it can  [fill](../Hardware_Manual_guide/node0122.html)  outlined shapes, and it can  [mask](../Hardware_Manual_guide/node011F.html#line42)  the first
and last words of each raster row.  In  [line mode](../Hardware_Manual_guide/node0128.html) , any pattern can be
imposed on a line, or the line can be drawn such that only one pixel per
horizontal line is set.

The blitter can only access Chip memory -- that portion of memory
accessible by the display hardware.  Attempting to use the blitter to read
or write Fast or other non-Chip memory may result in destruction of the
contents of Chip memory.

A "blit" is a single operation of the blitter -- perhaps the drawing of a
line or movement of a block of memory.  A blit is performed by
initializing the blitter registers with appropriate values and then
starting the blitter by writing the  [BLTSIZE](../Hardware_Manual_guide/node011B.html#line82)  register. As the blitter is
an asynchronous coprocessor, the 680x0 CPU continues to run as the blit is
executing.

