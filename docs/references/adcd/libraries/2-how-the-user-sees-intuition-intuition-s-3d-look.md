---
title: 2 / How the User Sees Intuition / Intuition's 3D Look
manual: libraries
chapter: libraries
section: 2-how-the-user-sees-intuition-intuition-s-3d-look
functions: []
libraries: []
---

# 2 / How the User Sees Intuition / Intuition's 3D Look

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga operating system comes in different [versions](libraries/1-programming-in-the-amiga-environment-operating-system.md).  The latest
version, [Release 2](libraries/1-operating-system-versions-about-release-2.md), contains significant improvements in the appearance of
the Intuition graphical user interface, usually referred to as the 3D Look
of Intuition.


```c
     [Figure 2-2: An Example of the 3D Look of Intuition](libraries/lib-pics-2-2-pic.md) 
```
In the new 3D look of Intuition, objects are drawn so that light appears
to come from the upper left of the display with shadows cast to the lower
right.  Using light and shadow gives the illusion of depth so that images
appear to stand out or recede from the display.  By convention, an image
with a raised appearance indicates an object that is available for use or
modifiable.  An image with a recessed appearance indicates an object that
is unmodifiable, or for display purposes only. Applications should follow
the same conventions.

[Release 2](libraries/1-operating-system-versions-about-release-2.md) has other improvements over 1.3 (V34) and earlier [versions](libraries/1-programming-in-the-amiga-environment-operating-system.md) of
the operating system.  Among these are [new display resolutions](libraries/27-resolution-modes-display-modes-colors-and-requirements.md), display
sizes, and [new function libraries](libraries/1-programming-in-the-amiga-environment-libraries-of.md) to support Intuition.  Most of the
[examples](libraries/1-introduction-to-amiga-system-libraries-about-the-examples.md) listed in this book assume Release 2.  Where appropriate, the old
1.3 methods are also described.

