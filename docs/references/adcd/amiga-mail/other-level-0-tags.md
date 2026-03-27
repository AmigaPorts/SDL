---
title: Other Level 0 Tags
manual: amiga-mail
chapter: amiga-mail
section: other-level-0-tags
functions: []
libraries: []
---

# Other Level 0 Tags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are several other Level 0 tags:

OT_DotSize
----------
This tag specifies the X and Y size of the target device's dots.  The
X and Y DPI imply a dot size.  For example, at 300 X and 300 Y DPI,
the resolution implied dot size is 1/300 inches by 1/300 inches.  For
some devices (like some dot matrix printers), the size of the output
dot does not match its resolution implied size.  To a degree, the
IntelliFont engine can account for this.  The dot size is represented
as a percentage of the dot's resolution implied size.  The X
percentage is in the tag value's upper word, and the Y percentage is
in the tag value's lower word.

OT_SetFactor
------------
This tag distorts the width of a typeface by changing the width of
the em square.  The scaling engine changes the em width to this tag's
value.  The value is a fixed point binary fraction.

OT_EmboldenX/OT_EmboldenY
-------------------------
These tags specify the algorithmic emboldening factor in the X and Y
direction, respectively.  The tag values are fixed point two's
complement binary numbers.  The units are measured in ems.
Emboldening values above zero embolden the typeface.  Emboldening
values below zero lighten the typeface.  By default, both values are
zero.

OT_GlyphWidth
-------------
This tag's value specifies a width for the current typeface.  It is a
fraction of an em represented as a fixed point binary number.  If
this value is set to something besides 0.0, all glyphs will have this
width.  To turn off the constant width, set OT_GlyphMap back to 0.0
(its default value).

