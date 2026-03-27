---
title: 3 / Custom Screen Functions / Creating A New Custom Screen
manual: libraries
chapter: libraries
section: 3-custom-screen-functions-creating-a-new-custom-screen
functions: [OpenScreen, OpenScreenTagList]
libraries: [intuition.library]
---

# 3 / Custom Screen Functions / Creating A New Custom Screen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are three functions you can use to open a [custom screen](libraries/3-intuition-screens-custom-screen-functions.md):
[OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md), [OpenScreenTags()](libraries/3-intuition-screens-custom-screen-functions.md) or [OpenScreenTagList()](libraries/3-intuition-screens-custom-screen-functions.md).  Prior to Release 2
(V36), OpenScreen() was used to create a new screen.  With V36 and later
versions of the operating system, this call is superseded by
OpenScreenTagList() and OpenScreenTags().

   struct Screen *OpenScreen( struct NewScreen *)
   struct Screen *OpenScreenTagList( struct NewScreen * , struct TagItem *)
   struct Screen *OpenScreenTags( struct NewScreen *, ULONG, ULONG, ... )

The old [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) call relied on a fixed size data structure
([NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md)) which made little allowance for extensions and growth.  The
new calls are tag based, allowing for the addition of new features without
modification of existing structures and applications.  The
"[Screen Attributes](libraries/3-custom-screen-functions-screen-attributes.md)" section below contains a complete list of all the tag
options available for setting up an Intuition screen.  For a general
description of tag items, see the "[Utility Library](libraries/37-utility-library-tags.md)" chapter.

 [A Custom Screen Example](libraries/3-creating-a-new-custom-screen-a-custom-screen-example.md) 
 [Creating A Custom Screen that Works With Older Systems](libraries/3-creating-a-custom-screen-that-works-with-older-systems.md) 
 [Return Values from OpenScreenTagList()](libraries/3-creating-custom-screen-return-values-from.md) 
 [Closing the Screen](libraries/3-creating-a-new-custom-screen-closing-the-screen.md) 

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
