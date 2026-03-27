---
title: 29 / About Amiga Fonts / System Fonts In Release 2
manual: libraries
chapter: libraries
section: 29-about-amiga-fonts-system-fonts-in-release-2
functions: []
libraries: []
---

# 29 / About Amiga Fonts / System Fonts In Release 2

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Under Release 2 and later versions of the OS, the system has additional
font sources at its disposal.  If an application asks the diskfont.library
to load a font of a size that has no corresponding bitmap on disk, the
library can generate that size font.  If diskfont.library can find a
smaller or larger version of the font requested, it can scale that font's
bitmap to the size needed.  Of course, because the library is scaling a
bitmap, the quality of the bitmap can degenerate in the scaling process.

A more significant improvement to the diskfont.library is that contains
AGFA's Intellifont® engine.  As of Release 2.04 (V37) the diskfont.library
can utilize AGFA Compugraphic font outlines.  The Compugraphic fonts (CG
fonts) are mathematical outlines that describe what the font's characters
look like.  The advantage of the outline fonts is that they can be scaled
to any point size without the loss of resolution inherent in bitmap
scaling.  From the programmers point of view, no extra information is
necessary for using the CG fonts, the diskfont.library takes care of all
the scaling.  Future releases of the OS may bring finer control over the
font scaling engine which will allow an application to rotate and shear
glyphs.

