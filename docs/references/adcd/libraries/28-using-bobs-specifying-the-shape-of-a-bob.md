---
title: 28 / Using Bobs / Specifying the Shape of a Bob
manual: libraries
chapter: libraries
section: 28-using-bobs-specifying-the-shape-of-a-bob
functions: []
libraries: []
---

# 28 / Using Bobs / Specifying the Shape of a Bob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The layout of the data of a Bob's image is different from that of a
VSprite because of the way the system retrieves data to draw Bobs.
VSprite images are organized in a way convenient to the Sprite hardware;
Bob images are set up for easy blitter manipulation.  The [ImageData](autodocs-2.0/includes-graphics-gels-h.md)
pointer is still initialized to point to the first word of the image
definition.


```c
    Note:
    -----
    As with all image data, a Bob's [ImageData](autodocs-2.0/includes-graphics-gels-h.md) must be in Chip memory
    for access by the blitter.
```
The sample image below shows the same image defined as a VSprite in the
"[Using Virtual Sprites](libraries/28-using-virtual-sprites-vsprite-image-data.md)" section above.  The data here, however, is laid
out for a Bob.  The shape is 2 planes deep and is triangular:



            <first bitplane data>
  mem        1111 1111 1111 1111    Least significant bit of sprite line 1
  mem + 1    0011 1100 0011 1100    Least significant bit of sprite line 2
  mem + 2    0000 1100 0011 0000    Least significant bit of sprite line 3
  mem + 3    0000 0010 0100 0000    Least significant bit of sprite line 4
  mem + 4    0000 0001 1000 0000    Least significant bit of sprite line 5


            <second bitplane data>
  mem + 5    1111 1111 1111 1111    Most significant bit of sprite line 1
  mem + 6    0011 0000 0000 1100    Most significant bit of sprite line 2
  mem + 7    0000 1111 1111 0000    Most significant bit of sprite line 3
  mem + 8    0000 0011 1100 0000    Most significant bit of sprite line 4
  mem + 9    0000 0001 1000 0000    Most significant bit of sprite line 5


            <more bitplanes of data if Bob is deeper>
