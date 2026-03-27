---
title: D / Errors / Fails only on machines with Fast RAM
manual: libraries
chapter: libraries
section: d-errors-fails-only-on-machines-with-fast-ram
functions: [AllocRaster, OpenScreen]
libraries: [graphics.library, intuition.library]
---

# D / Errors / Fails only on machines with Fast RAM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Data and buffers which will be accessed directly by the custom chips must
be in Chip RAM.  This includes bitplanes (use [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) or
[AllocRaster()](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md)), audio samples, trackdisk buffers, and the graphic image
data for sprites, pointers, bobs, images, gadgets, etc.  Use compiler or
linker flags to force Chip RAM loading of any initialized data needing to
be in Chip RAM, or dynamically allocate Chip RAM and copy any
initialization data there.

---

## See Also

- [AllocRaster — graphics.library](../autodocs/graphics.library.md#allocraster)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
