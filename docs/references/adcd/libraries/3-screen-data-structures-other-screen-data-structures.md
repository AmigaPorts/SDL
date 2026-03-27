---
title: 3 / Screen Data Structures / Other Screen Data Structures
manual: libraries
chapter: libraries
section: 3-screen-data-structures-other-screen-data-structures
functions: []
libraries: []
---

# 3 / Screen Data Structures / Other Screen Data Structures

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In addition to the Screen structure, Intuition uses some other supporting
structures defined in the include file <intuition/[screens.h](autodocs-2.0/includes-intuition-screens-h.md)> and in
<utility/[tagitems.h](autodocs-2.0/includes-utility-tagitem-h.md)>.  (See the Amiga ROM Kernel Reference Manual:
Includes and Autodocs for a complete listing.)




      Table 3-2: Data Structures Used with Intuition Screens
  Structure Name  Description                    Defined in Include File
  --------------  -----------                    -----------------------
  [Screen](libraries/3-screen-data-structures-the-intuition-screen-data-structure.md)          Main Intuition structure that   <intuition/[screens.h](autodocs-2.0/includes-intuition-screens-h.md)>

```c
                  defines a screen (see above)
```
  [DrawInfo](libraries/3-intuition-screens-drawinfo-and-the-3d-look.md)        Holds the screen's pen, font    <intuition/[screens.h](autodocs-2.0/includes-intuition-screens-h.md)>

                  and aspect data for Intuition
  [TagItem](libraries/37-tags-tag-functions-and-structures.md)         General purpose parameter        <utility/[tagitem.h](autodocs-2.0/includes-utility-tagitem-h.md)>

                  structure used to set up
                  screens in V36
  NewScreen       Parameter structure used to     <intuition/[screens.h](autodocs-2.0/includes-intuition-screens-h.md)>

                  create a screen in V34
  ExtNewScreen    An extension to the NewScreen   <intuition/[screens.h](autodocs-2.0/includes-intuition-screens-h.md)>


                  structure used in V37 for
                  backward compatibility with
                  older systems
As [previously mentioned](libraries/3-intuition-screens-screen-data-structures.md), there is an Intuition Screen structure (and a
corresponding graphics [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md)) for every screen in memory.  Under
Release 2, whenever a new screen is created, Intuition also creates an
auxiliary data structure called a DrawInfo.

The [DrawInfo](libraries/3-intuition-screens-drawinfo-and-the-3d-look.md) structure is similar to a [RastPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) in that it holds drawing
information.  But where a RastPort is used at the lower graphics level,
the DrawInfo structure is used at the higher Intuition level.
Specifically, DrawInfo contains data needed to support the New Look of
Intuition in Release 2.  (For more information see the section below,
"[DrawInfo and the 3D Look](libraries/3-intuition-screens-drawinfo-and-the-3d-look.md)".)

Another new feature of Release 2 is [tag](libraries/37-utility-library-tags.md) items.  A [TagItem](libraries/37-tags-tag-functions-and-structures.md) is a general
purpose parameter structure used to pass arguments to many of the
functions in the Release 2 system software.  Each tag consists of a LONG
tag ID ([ti_Tag](libraries/37-tags-tag-functions-and-structures.md)) and a LONG tag data value ([ti_Data](libraries/37-tags-tag-functions-and-structures.md)).  With screens, tag
items are used to describe the attributes an application wants for a new,
[custom screen](libraries/3-intuition-screens-custom-screen-functions.md).  Tag items replace the NewScreen structure, the set of
parameters used in older versions of the OS to set up a screen.

Applications may wish to use tag items to set up a new screen instead of
the [NewScreen](autodocs-2.0/includes-intuition-screens-h.md) structure since tag items are often more convenient.  For
the sake of backwards compatibility, the [ExtNewScreen](autodocs-2.0/includes-intuition-screens-h.md) structure is
available.  ExtNewScreen combines the NewScreen method used to define
screens in older versions of the OS with the tag item method used in
Release 2.  The [examples](libraries/3-creating-a-new-custom-screen-a-custom-screen-example.md) listed in the next section show how these various
data structures can be used to set up a new screen.

