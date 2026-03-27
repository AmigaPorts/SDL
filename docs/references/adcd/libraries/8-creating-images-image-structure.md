---
title: 8 / Creating Images / Image Structure
manual: libraries
chapter: libraries
section: 8-creating-images-image-structure
functions: [DrawImage]
libraries: [intuition.library]
---

# 8 / Creating Images / Image Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For images, the application must create one or more instances of the [Image](autodocs-2.0/includes-intuition-intuition-h.md)
structure.


```c
    struct Image
        {
        WORD LeftEdge;
        WORD TopEdge;
        WORD Width;
        WORD Height;
        WORD Depth;
        UWORD *ImageData;
        UBYTE PlanePick, PlaneOnOff;
        struct Image *NextImage;
        };
```
The meanings of the fields in the Image structure are:

LeftEdge, TopEdge

```c
    The location of the image relative to its base position when it is
    drawn.  These offsets are added to the base position to determine the
    final location of the image data.

    The base position for images rendered with [DrawImage()](libraries/8-creating-images-directly-drawing-the-image.md) is taken from
    arguments passed in the function call.  For gadgets and menus, the
    base position is always the upper, left corner of the select box.
    For requesters the base position is always the upper, left corner of
    the requester.

    Negative values of LeftEdge and TopEdge move the position up and to
    the left of the base position.  Positive values move down and to the
    right.
```
Width, Height

    The width and height of the image.  Width contains the actual width
    of the image in pixels.  Height specifies the height of the image in
    pixels.

    The Width field of the Image structure contains the actual width in
    pixels of the widest part of the image, not how many pixels are
    contained in the words that define the image.
Depth

    The depth of the image, or the number of bitplanes used to define it.
    This is not the depth of the screen or window in which the image will
    be displayed, it is the actual number of bitplanes that are defined
    in the ImageData.
ImageData

```c
    This is a pointer to the bits that define the image and determine the
    colors of each pixel.  Image data must be placed in Chip memory.  The
    data is organized as an array of 16 bit words whose size can be
    computed as follows:

        WordWidth = ((Width + 16) / 16);
        NumImageWords = WordWidth * Height * Depth;

    The width of the image is rounded up to the nearest word (16 bits)
    and extra trailing bits are ignored.  Each line of each bitplane must
    have enough words to contain the image width, with extra bits at the
    end of each line set to zero.  For example, an image 7 bits wide
    requires one word for each line in the bitplane, whereas an image 17
    bits wide requires two words for each line in the bitplane.
```
PlanePick

```c
    PlanePick tells which planes of the target [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) are to receive
    planes of image data.  This field is a bit-wise representation of
    bitplane numbers.  For each bit set in PlanePick, there should be a
    corresponding bitplane in the image data.
```
PlaneOnOff

```c
    PlaneOnOff tells whether to set or clear bits in the planes in the
    target [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) that receive no image data.  This field is a bit-wise
    representation of bitplane numbers.
```
NextImage

    This field is a pointer to another instance of an Image structure.
    Set this field to NULL if this is the last Image structure in the
    linked list.

---

## See Also

- [DrawImage — intuition.library](../autodocs/intuition.library.md#drawimage)
