---
title: 3 / / Creating A New Custom Screen / A Custom Screen Example
manual: libraries
chapter: libraries
section: 3-creating-a-new-custom-screen-a-custom-screen-example
functions: [OpenScreen]
libraries: [intuition.library]
---

# 3 / / Creating A New Custom Screen / A Custom Screen Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are so many tag options available with screens it can be a bit
overwhelming.  Before discussing more details, it may be helpful to look
at a simple example.  The code below opens a new, [custom screen](libraries/3-intuition-screens-custom-screen-functions.md) using the
[OpenScreenTags()](libraries/3-intuition-screens-custom-screen-functions.md) call.  The example uses just two tag items ([SA_Depth](libraries/3-custom-screen-functions-screen-attributes.md) and
[SA_Pens](libraries/3-custom-screen-functions-screen-attributes.md)) which provide the minimum attributes needed to make a screen that
uses the new 3D look of Intuition available in Release 2.  (See the
section on "[DrawInfo and the 3D Look](libraries/3-intuition-screens-drawinfo-and-the-3d-look.md)" below for more information.)


```c
     [newlookscreen.c](libraries/lib-examples-newlookscreen-c.md) 
```
The example above runs only under Release 2 (V36) and later versions of
the OS.  To make a [custom screen](libraries/3-intuition-screens-custom-screen-functions.md) that [works under both](libraries/3-creating-a-custom-screen-that-works-with-older-systems.md) Release 2 and
earlier versions of the operating system, use the original [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md)
function.

The [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure used with [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) has been extended with a
tag list in V36 to form an [ExtNewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md).  This is done by setting the
NS_EXTENDED bit in the Type field of the NewScreen structure and adding a
pointer to an array of tags to the end of the structure.  The NS_EXTENDED
bit is ignored in older versions of the operating system, so the tags can
be transparently added to existing applications and the features will
appear when executed in a system running V36 or greater.  See the
[OpenScreen()](autodocs-2.0/intuition-library-openscreen.md) Autodocs and the include file <intuition/[screens.h](autodocs-2.0/includes-intuition-screens-h.md)> for more
information on NS_EXTENDED and the ExtNewScreen structure.

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
