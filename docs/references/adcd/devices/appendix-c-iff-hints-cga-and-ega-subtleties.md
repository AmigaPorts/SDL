---
title: Appendix C. IFF Hints / CGA and EGA subtleties
manual: devices
chapter: devices
section: appendix-c-iff-hints-cga-and-ega-subtleties
functions: []
libraries: []
---

# Appendix C. IFF Hints / CGA and EGA subtleties

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IBM EGA colors in 350 scan line mode are 2:2:2 bits of R:G:B, stored in
memory as xxR'G'B'RBG.  That's 3 low-order bits followed by 3 high-order
bits.

IBM CGA colors are 4 bits stored in a byte as xxxxIRGB.  (EGA colors in
200 scan line modes are the same as CGA colors, but stored in memory as
xxxIxRGB.) That's 3 high-order bits (one for each of R, G, and B) plus one
low-order " Intensity" bit for all 3 components R, G, and B.  Exception:
IBM monitors show IRGB = 0110 as brown, which is really the EGA color
R:G:B = 2:1:0, not dark yellow 2:2:0.

