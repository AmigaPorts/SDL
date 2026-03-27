---
title: 8 Intuition Images, Line Drawing and Text / Intuition Graphic Objects
manual: libraries
chapter: libraries
section: 8-intuition-images-line-drawing-and-text-intuition-graphic
functions: []
libraries: []
---

# 8 Intuition Images, Line Drawing and Text / Intuition Graphic Objects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Intuition graphic objects are easy to create and economical to use.  There
are just three basic types of graphic objects you can use yet these three
types cover most rendering needs:

[Image](libraries/8-creating-images-image-structure.md)

    Images are graphic objects that can contain any imagery.  They
    consist of a rectangular bitmap that can be any size and describes
    each individual pixel to be displayed.
[Border](libraries/8-creating-borders-border-structure-definition.md)

    Borders are connected lines of any length and number, drawn between
    an arbitrary series of points.  They consist of a series of two
    dimensional coordinates that describe the points between which lines
    will be drawn.
[IntuiText](libraries/8-creating-text-intuitext-structure.md)

    IntuiText strings are text strings of any length drawn in any font.
    They consist of a text string and font specification that describes
    the text to be rendered.
Each of these three objects may be chained together with other members of
the same type.  For instance, many lines of text may be rendered as a
single object by linking many instances of [IntuiText](libraries/8-creating-text-intuitext-structure.md) objects together.
Only objects of the same type may be linked.

Any of these types can be rendered into any of the Intuition display
elements (window, requester, menu, etc.).  In fact, the application can
often display the same structure in more than one position or more than
one of the elements at the same time.

 [Displaying Images, Borders and IntuiText](libraries/8-graphic-objects-displaying-images-borders-and-intuitext.md) 
 [Positioning Graphic Objects](libraries/8-intuition-graphic-objects-positioning-graphic-objects.md) 

