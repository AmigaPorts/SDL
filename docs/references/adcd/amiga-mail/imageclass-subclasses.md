---
title: Imageclass Subclasses
manual: amiga-mail
chapter: amiga-mail
section: imageclass-subclasses
functions: [NewObject]
libraries: [intuition.library]
---

# Imageclass Subclasses

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An imageclass object contains an Image structure that Intuition uses to
render objects such as gadgets.  Boopsi imageclass objects are organized
so that when NewObject() returns a pointer to an imageclass object, it
points to the actual Image structure.

Normally, an application does not create an imageclass object.  Instead,
it will use a subclass of imageclass.  Currently, there are four
subclasses:  frameiclass, sysiclass, fillrectclass, and itexticlass.

frameiclass - An embossed or recessed rectangular frame, rendered in the
  proper DrawInfo pens, with enough intelligence to bound or center its
  contents.

sysiclass - The class of system images.  The class includes all the
  images for the system gadgets, and the Gadtools check mark and button
  glyphs.

fillrectclass - Rectangle with frame and pattern support.

itexticlass - A specialized image class used for rendering text.  Note
  that you have to calculate itexticlass object's width and height
  yourself.

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
