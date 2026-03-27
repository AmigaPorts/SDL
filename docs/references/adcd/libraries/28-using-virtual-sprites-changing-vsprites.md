---
title: 28 / Using Virtual Sprites / Changing VSprites
manual: libraries
chapter: libraries
section: 28-using-virtual-sprites-changing-vsprites
functions: []
libraries: []
---

# 28 / Using Virtual Sprites / Changing VSprites

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once the VSprite has been added to the GELs list and is in the display,
some of its characteristics can be changed dynamically by:


```c
    * Changing y, x to a new VSprite position

    * Changing [ImageData](libraries/28-using-virtual-sprites-vsprite-image-data.md) to point to a new VSprite image

    * Changing [SprColors](libraries/28-using-virtual-sprites-specifying-the-colors-of-a-vsprite.md) to point to a new VSprite color set
```
Study the next two sections to find out how to reserve hardware Sprites
for use outside the VSprite system and how to assign the VSprites.

