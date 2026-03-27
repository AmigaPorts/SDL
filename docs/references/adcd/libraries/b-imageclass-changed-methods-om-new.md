---
title: B / imageclass / Changed Methods: OM_NEW
manual: libraries
chapter: libraries
section: b-imageclass-changed-methods-om-new
functions: []
libraries: []
---

# B / imageclass / Changed Methods: OM_NEW

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The instance data for [imageclass](libraries/b-boopsi-class-reference-imageclass.md) contains an [Image](libraries/8-creating-images-image-structure.md) structure, and its
[Depth](libraries/8-creating-images-image-structure.md) field is initialized to CUSTOMIMAGEDEPTH, which identifies such
images to Intuition.  The Image's [Width](libraries/8-creating-images-image-structure.md) and [Height](libraries/8-creating-images-image-structure.md) fields default to
arbitrary positive numbers for safety, but an imageclass subclass or an
application should set these attributes to something meaningful.

