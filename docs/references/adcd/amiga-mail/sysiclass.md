---
title: sysiclass
manual: amiga-mail
chapter: amiga-mail
section: sysiclass
functions: []
libraries: []
---

# sysiclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  sysiclass
Superclass:             imageclass
Description:            Class for system and standard application images.
Include File:           <intuition/imageclass.h>


New Methods:
------------

None.


Changed Methods:
----------------

OM_NEW - Executes a drawing commands list to create a fast-rendering
image object.  The glyph of the object is defined by the attribute
SYSIA_Which.  The SYSIA_DrawInfo parameter is required at
initialization, as is IA_Height.  Image size defaults are established by
SYSIA_Size, but some images  (title bar gadget images) require
IA_Height.  Images are scaled to their dimensions.


Attributes:
-----------

SYSIA_DrawInfo                  (IS)

This attribute must be passed to OM_NEW and OM_SET to allow the image to
be generated into a bitmap cache.


SYSIA_Which                     (I)

Identifies which of the system image glyphs the caller wants.  It can be
one of the following:



    DEPTHIMAGE     Window depth arrangement image.
    ZOOMIMAGE      Window Zoom image.
    SIZEIMAGE      Window Sizing image.
    CLOSEIMAGE     Window close image.
    SDEPTHIMAGE    Screen depth arrangement image.
    LEFTIMAGE      Left arrow image.
    UPIMAGE        Up arrow image.
    RIGHTIMAGE     Right arrow image.
    DOWNIMAGE      Down arrow image.
    CHECKIMAGE     Checkmark image.
    MXIMAGE        Radio button image.
SYSIA_Size                      (I)

Identifies which default dimensions to use for the object.  This
generalizes Intuition's older concept of two different system image
dimensions.  The system currently uses SYSISIZE_MEDRES as the default,
SYSISIZE_HIRES for screens with title bars greater than 22 pixels, and
SYSISIZE_LORES for screens with fat pixels.

