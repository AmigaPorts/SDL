---
title: itexticlass
manual: amiga-mail
chapter: amiga-mail
section: itexticlass
functions: []
libraries: []
---

# itexticlass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  itexticlass
Superclass:             imageclass
Description:            IntuiText equivalent with attribute override.
Include File:           <intuition/imageclass.h>


New Methods:
------------

None.


Changed Methods:
----------------

IM_DRAW - Draws IntuiText specified as IA_Data overriding the attributes
specified in the IntuiText structure.  The Mode used is JAM1, the color
as specified as IA_FGPen.  The position of the itexticlass object is
added to the position of the IntuiText.

This class was defined to make new-looking AutoRequesters without
changing the IntuiText structures passed to it.


Attributes:
-----------

IA_Data                         (ISG)

Processed blindly by superclass, must be a pointer to a normal IntuiText
structure.


IA_FGPen                        (ISG)

Processed by superclass, used as APen when drawing text.


IA_Left, IA_Top                 (ISG)

Added to IntuiText offsets.

