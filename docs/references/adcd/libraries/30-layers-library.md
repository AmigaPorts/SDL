---
title: 30 Layers Library
manual: libraries
chapter: libraries
section: 30-layers-library
functions: [InstallClipRegion]
libraries: [layers.library]
---

# 30 Layers Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This chapter describes the layers library which provides routines that are
used to manage overlapping rectangular drawing areas that share a common
display.  Intuition uses the layers library to manage its system of
windows.

The chapter also describes the use of regions, special structures used to
mask off areas where drawing can take place.  Regions are installed
through the layers library function [InstallClipRegion()](libraries/30-layers-library-regions.md) but the routines
for the creation, disposal and manipulation of regions are part of the
graphics library.

 [Layers](libraries/30-layers-library-layers.md)    [Regions](libraries/30-layers-library-regions.md)    [Function Reference](libraries/30-layers-library-function-reference.md) 

---

## See Also

- [InstallClipRegion — layers.library](../autodocs/layers.library.md#installclipregion)
