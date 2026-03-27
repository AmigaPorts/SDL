---
title: Additional Info / How Amiga HAM mode works
manual: devices
chapter: devices
section: additional-info-how-amiga-ham-mode-works
functions: []
libraries: []
---

# Additional Info / How Amiga HAM mode works

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Amiga HAM (Hold and Modify) mode lets the Amiga display all 4096 RGB
values. In HAM mode, the bits in the two last planes describe an R G or B
modification to the color of the previous pixel on the line to create the
color of the current pixel.  So a 6-plane HAM picture has 4 planes for
specifying absolute color pixels giving up to 16 absolute colors which
would be specified in the ILBM CMAP chunk.  The bits in the last two
planes are color modification bits which cause the Amiga, in HAM mode, to
take the RGB value of the previous pixel (Hold and), substitute the 4 bits
in planes 0-3 for the previous color's R G or B component (Modify) and
display the result for the current pixel.  If the first pixel of a scan
line is a modification pixel, it modifies the RGB value of the border
color (register 0).  The color modification bits in the last two planes
(planes 4 and 5) are interpreted as follows:

   00 - no modification.  Use planes 0-3 as normal color register index
   10 - hold previous, replacing Blue component with bits from planes 0-3
   01 - hold previous, replacing Red component with bits from planes 0-3
   11 - hold previous. replacing Green component with bits from planes 0-3

