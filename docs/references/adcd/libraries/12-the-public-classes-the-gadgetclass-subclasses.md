---
title: 12 / / The Public Classes / The Gadgetclass Subclasses
manual: libraries
chapter: libraries
section: 12-the-public-classes-the-gadgetclass-subclasses
functions: []
libraries: []
---

# 12 / / The Public Classes / The Gadgetclass Subclasses

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Like [imageclass](libraries/12-the-public-classes-the-imageclass-subclasses.md), applications do not normally create objects of
[gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md), but instead create objects of its subclasses. Currently,
gadgetclass has four subclasses:

[propgclass](libraries/b-boopsi-class-reference-propgclass.md)

    An easy to implement, horizontal or vertical proportional gadget.
[strgclass](libraries/b-boopsi-class-reference-strgclass.md)

    A string gadget.
[groupgclass](libraries/b-boopsi-class-reference-groupgclass.md)

    A special gadget class that creates one composite gadget out of
    several others.
[buttongclass](libraries/b-boopsi-class-reference-buttongclass.md)

    A button gadget that keeps sending button presses while the user
    holds it down.
buttongclass has a subclass of its own:

[frbuttonclass](libraries/b-boopsi-class-reference-frbuttonclass.md)

    A buttongclass gadget that outlines its imagery with a frame.
For specific information on these classes, see the Boopsi Class Reference
in the [Appendix B](libraries/b-boopsi-class-reference.md) of this manual.

