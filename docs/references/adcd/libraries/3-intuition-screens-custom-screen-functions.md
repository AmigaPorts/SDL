---
title: 3 Intuition Screens / Custom Screen Functions
manual: libraries
chapter: libraries
section: 3-intuition-screens-custom-screen-functions
functions: [CloseScreen, OpenScreen, OpenScreenTagList]
libraries: [intuition.library]
---

# 3 Intuition Screens / Custom Screen Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All applications require a screen to work in.  This can be an existing,
[public screen](libraries/3-intuition-screens-public-screen-functions.md) or a new, custom screen created by the application itself.
To create a new, custom screen to work with, you call OpenScreen() or one
of its variants.


                 Table 3-3: Custom Screen Functions
  _____________________________________________________________________
 |                                                                     |
 |     [OpenScreenTags()](autodocs-2.0/intuition-library-openscreentaglist.md)  Create a new, custom screen from a tag list.  |
 |  [OpenScreenTagList()](autodocs-2.0/intuition-library-openscreentaglist.md)  Use either one of these with Release 2 (V36)  |
 |                       or later versions of the OS.                  |
 |                                                                     |
 |         [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md)  Create a new, custom screen from an           |
 |                       [ExtNewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure.  Use this if your     |
 |                       application must be compatible with 1.3 (V34) |
 |                       or earlier versions of the operating system.  |
 |                                                                     |
 |        [CloseScreen()](libraries/3-creating-a-new-custom-screen-closing-the-screen.md)  Close a custom screen and free the memory     |
 |                       it used.                                      |
 |_____________________________________________________________________|


 [Creating A New Custom Screen](libraries/3-custom-screen-functions-creating-a-new-custom-screen.md)    [Screen Attributes](libraries/3-custom-screen-functions-screen-attributes.md) 

---

## See Also

- [CloseScreen — intuition.library](../autodocs/intuition.library.md#closescreen)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
