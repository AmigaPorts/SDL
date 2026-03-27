---
title: 33 / / FORM ILBM / Other ILBM Notes
manual: libraries
chapter: libraries
section: 33-form-ilbm-other-ilbm-notes
functions: []
libraries: []
---

# 33 / / FORM ILBM / Other ILBM Notes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Amiga [ILBM](libraries/33-iffparse-library-iff-form-specifications.md)s images must be stored as an even number of bytes in width.
However, the [ILBM BMHD](libraries/33-form-ilbm-interpreting-ilbms.md) field w (width) should describe the actual image
width, not the rounded up width as stored.

[ILBM](libraries/33-iffparse-library-iff-form-specifications.md)s created with Electronic Arts IBM or Amiga Deluxe Paint II packages
are compatible (though you may have to use a `.lbm' filename extension on
an IBM).  The ILBM graphic files may be transferred between the machines
(or between the Amiga and IBM sides your Amiga if you have a CBM
Bridgeboard card installed) and loaded into either package.

