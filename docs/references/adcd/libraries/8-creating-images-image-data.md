---
title: 8 / Creating Images / Image Data
manual: libraries
chapter: libraries
section: 8-creating-images-image-data
functions: []
libraries: []
---

# 8 / Creating Images / Image Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Image data must be in Chip memory.  The [Image](libraries/8-creating-images-image-structure.md) structure itself may be in
any memory, but the actual data referenced by [ImageData](libraries/8-creating-images-image-structure.md) field must be in
Chip memory.  This may be done by using compiler specific options, such as
the __chip keyword of SAS/C, or by allocating memory with the [MEMF_CHIP](libraries/20-memory-functions-memory-attributes.md)
attribute and copying the image data to that memory.

 [Defining Image Data](libraries/8-image-data-defining-image-data.md) 

