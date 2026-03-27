---
title: 12 / / The Public Classes / The Imageclass Subclasses
manual: libraries
chapter: libraries
section: 12-the-public-classes-the-imageclass-subclasses
functions: []
libraries: []
---

# 12 / / The Public Classes / The Imageclass Subclasses

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Normally, an application does not create an [imageclass](libraries/b-boopsi-class-reference-imageclass.md) object. Instead, it
will use a subclass of imageclass.  Currently, there are four subclasses:
frameiclass, sysiclass, fillrectclass, and itexticlass.

[frameiclass](libraries/b-boopsi-class-reference-frameiclass.md)

```c
    An embossed or recessed rectangular frame image, that renders itself
    using the proper [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) pens.  This class is intelligent enough to
    bound or center its contents.
```
[sysiclass](libraries/b-boopsi-class-reference-sysiclass.md)

    The class of system images.  The class includes the images for the
    system and GadTools gadgets.
[fillrectclass](libraries/b-boopsi-class-reference-fillrectclass.md)

    A class of rectangle images that have frame and patternfill support.
[itexticlass](libraries/b-boopsi-class-reference-itexticlass.md)

    A specialized image class used for rendering text.
For more information on these classes see the Boopsi Class Reference in
the [Appendix B](libraries/b-boopsi-class-reference.md) of this manual.  It describes all of the existing public
classes, their methods, and their attributes.

 [The Gadgetclass Subclasses](libraries/12-the-public-classes-the-imageclass-subclasses.md) 

