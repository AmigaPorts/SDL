---
title: Shearing
manual: amiga-mail
chapter: amiga-mail
section: shearing
functions: []
libraries: []
---

# Shearing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Like baseline rotation, glyph shearing (also known as italicizing) is
a matter of setting some Level 0 tags.  The shearing tags,
OT_ShearSin and OT_ShearCos, specify the shearing angle, or the angle
at which the typeface is italicized.  This angle refers to the angle
that results from rotating the vertical axis clockwise.  The angle
can range from -45 to 45 degrees (inclusive).  Like the rotation
angle, the shearing angle is represented as a sine and cosine value
that must correspond to the same angle and must fall into normal
bounds for sine and cosine values.  Also like the rotation angle sine
and cosine tags, an application must set both the OT_ShearSin and
OT_ShearCos tags, in that order.  By default, the shearing value is
zero degrees meaning there is no shearing (OT_ShearSin = 0x00000000,
OT_ShearCos = 0x00010000).

