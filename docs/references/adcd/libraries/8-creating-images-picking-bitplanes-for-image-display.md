---
title: 8 / Creating Images / Picking Bitplanes for Image Display
manual: libraries
chapter: libraries
section: 8-creating-images-picking-bitplanes-for-image-display
functions: []
libraries: []
---

# 8 / Creating Images / Picking Bitplanes for Image Display

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A single image may be displayed in different colors without changing the
underlying image data.  This is done by selecting which of the target
bitplanes are to receive the image data, and what to do with the target
bitplanes that do not receive any image data.

[PlanePick](libraries/8-creating-images-image-structure.md) and [PlaneOnOff](libraries/8-creating-images-image-structure.md) are used to control the bitplane rendering of the
image.  The bits in each of these variables have a direct correspondence
to the bitplanes of the target bitmap.  The lowest bit position
corresponds to the lowest numbered bitplane, the next highest bit position
corresponds to the next bitplane, etc.

For example, for a window or screen with three bitplanes (consisting of
planes 0, 1, and 2), all the possible values for [PlanePick](libraries/8-creating-images-image-structure.md) or [PlaneOnOff](libraries/8-creating-images-image-structure.md)
and the planes picked are as follows:



                 __________________________________
                |                                  |
                | PlanePick or                     |
                |  PlaneOnOff   Planes Picked      |
                | ------------  -------------      |
                |     000       No planes          |
                |     001       Plane 0            |
                |     010       Plane 1            |
                |     011       Planes 0 and 1     |
                |     100       Plane 2            |
                |     101       Planes 0 and 2     |
                |     110       Planes 1 and 2     |
                |     111       Planes 0, 1, and 2 |
                |__________________________________|
[PlanePick](libraries/8-creating-images-image-structure.md) picks the bitplanes of the containing [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) that will receive
the bitplanes of the image.  For each plane that is picked to receive
data, the next successive plane of image data is drawn there.  For
example, if an image with two bitplanes is drawn into a window with four
bitplanes with a PlanePick of binary 1010, the first bitplane of the image
will be drawn into the second bitplane of the window and the second
bitplane of the image will be drawn into the fourth bitplane of the
window.  Do not set more bits in PlanePick than there are bitplanes in the
image data.

[PlaneOnOff](libraries/8-creating-images-image-structure.md) specifies what to do with the bitplanes that are not picked to
receive image data.  If the PlaneOnOff bit is zero, then the associated
bitplane will be filled with zeros.  If the PlaneOnOff bit is one, then
the associated bitplane will be filled with ones.  Of course, only bits
that fall within the rectangle defined by the image are affected by this
manipulation.

Only the bits not set in [PlanePick](libraries/8-creating-images-image-structure.md) are used in [PlaneOnOff](libraries/8-creating-images-image-structure.md), that is,
PlaneOnOff only applies to those bitplanes not picked to receive image
data.  For example, if PlanePick is 1010 and PlaneOnOff is 1100, then
PlaneOnOff may be viewed as x1x0 (where the x positions are not taken into
consideration).  In this case, planes two and four would receive image
data and planes one and three would be set by PlaneOnOff.  Each bit in
plane one would be set to zero and each bit in plane three would be set to
one.

[PlaneOnOff](libraries/8-creating-images-image-structure.md) is only useful where an entire bitplane of an image may be set
to the same value.  If the bitplane is not all set to the same value, even
for just a few bits, then image data must be specified for that plane.

A simple trick to create a filled rectangle of any color may be used by
supplying no image data, where the color is controlled by [PlaneOnOff](libraries/8-creating-images-image-structure.md).  The
[Depth](libraries/8-creating-images-image-structure.md) of such an image is set to zero, the size of the rectangle is
specified in the [Width](libraries/8-creating-images-image-structure.md) and [Height](libraries/8-creating-images-image-structure.md) fields and the [ImageData](libraries/8-creating-images-image-structure.md) pointer may be
NULL.  PlanePick should be set to zero, as there are no planes of image
data to pick.  PlaneOnOff is then set to the color register which contains
the desired color for the rectangle.

