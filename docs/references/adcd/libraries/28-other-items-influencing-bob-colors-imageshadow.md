---
title: 28 / / Other Items Influencing Bob Colors / ImageShadow
manual: libraries
chapter: libraries
section: 28-other-items-influencing-bob-colors-imageshadow
functions: []
libraries: []
---

# 28 / / Other Items Influencing Bob Colors / ImageShadow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [ImageShadow](libraries/28-using-bobs-the-bob-structure.md) member is a pointer to the shadow mask of a Bob. A shadow
mask is the logical or of all bitplanes of a Bob image. The system uses
the shadow mask in conjunction with [PlaneOnOff](libraries/28-other-items-influencing-bob-colors-planeonoff.md), discussed below, for color
selection. It also uses the shadow mask to "cookie cut" the bits that will
be overwritten by this Bob, to save and later restore the background.

The following figure shows the shadow mask of the image described above.




    mem + 0    1111 1111 1111 1111    Shadow mask for line 1
    mem + 1    0011 1100 0011 1100    Shadow mask for line 2
    mem + 2    0000 1111 1111 0000    Shadow mask for line 3
    mem + 3    0000 0011 1100 0000    Shadow mask for line 4
    mem + 4    0000 0001 1000 0000    Shadow mask for line 5
Space for the [ImageShadow](libraries/28-using-bobs-the-bob-structure.md) must be provided and this pointer initialized to
point to it.  The amount of memory needed is equivalent to one plane of
the image:


```c
    shadow_size = myBob->BobVSprite->Height * myBob->BobVSprite->Width;
```
The example image is 5 high and 1 word wide, so, 5 words must be made
available.


```c
    Note:
    -----
    The [ImageShadow](libraries/28-using-bobs-the-bob-structure.md) memory must be allocated from Chip memory
    ([MEMF_CHIP](libraries/20-memory-functions-memory-attributes.md)).
```
