---
title: fillrectclass
manual: amiga-mail
chapter: amiga-mail
section: fillrectclass
functions: []
libraries: []
---

# fillrectclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  fillrectclass
Superclass:             imageclass
Description:            Rectangle with frame and pattern support
Include File:           <intuition/imageclass.h>


New Methods:
------------

None.


Changed Methods:
----------------

IM_DRAW - Draws the pattern in its natural (Image) dimensions.


IM_DRAWFRAME - Same as IM_DRAW, but draws pattern to specified exterior
dimensions.


Attributes:
-----------

IA_APattern                     (IS)

Points to the pattern to fill in the Image structure's ImageData field.


IA_APatSize                     (IS)

The pattern's dimension.


IA_Mode                         (IS)

Drawing mode for the pattern.

