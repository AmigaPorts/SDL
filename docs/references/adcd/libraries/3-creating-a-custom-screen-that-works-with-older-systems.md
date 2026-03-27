---
title: 3 / / / Creating A Custom Screen that Works With Older Systems
manual: libraries
chapter: libraries
section: 3-creating-a-custom-screen-that-works-with-older-systems
functions: [OpenScreen, OpenScreenTagList]
libraries: [intuition.library]
---

# 3 / / / Creating A Custom Screen that Works With Older Systems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's an example of how to use the old [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) call with an
[ExtNewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure to make a new, [custom screen](libraries/3-intuition-screens-custom-screen-functions.md) under any version of
the Amiga operating system.  If the version is V36 or later, additional
Release 2 features specified via tags, in this case the new 3D look of
Intuition, will be incorporated in the window.


```c
     [screen34to37.c](libraries/lib-examples-screen34to37-c.md) 
```
As you can see from the examples above, there are many ways to create a
new, [custom screen](libraries/3-intuition-screens-custom-screen-functions.md).  Further references to "[OpenScreenTagList()](libraries/3-intuition-screens-custom-screen-functions.md)" in this
manual are referring to any one of the three calls: OpenScreenTagList(),
[OpenScreenTags()](libraries/3-intuition-screens-custom-screen-functions.md), or [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) used with tags in an [ExtNewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md) as
shown above.

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
