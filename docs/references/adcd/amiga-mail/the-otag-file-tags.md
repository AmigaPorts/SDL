---
title: The Otag File Tags
manual: amiga-mail
chapter: amiga-mail
section: the-otag-file-tags
functions: [AvailFonts]
libraries: [diskfont.library]
---

# The Otag File Tags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Outline Tag (otag) file contains a number of tags that describe a
font outline to the Diskfont library.  The purpose of most of these
tags is to allow Diskfont to attribute styles to a typeface when
loading a font outline as a standard Amiga system font.  Most
applications that use the scaling engine will not need to worry about
the meaning of the majority of these tags, but they are described
below.  The following tags are Level 1 tags and must be present in
every otag file:

OT_FileIdent
------------
Every valid otag file starts with this tag.  Its value is the size of
the file.  It doesn't really have anything to do with the definition
of the typeface, but it does serve as a way to check the validity of
the otag file.

OT_Engine
---------
This tag's value points to a string naming the font scaling engine.
For example, the OT_Engine tag in fonts:CGTimes.otag is ``bullet''.

OT_Family
---------
This tag's value points to a string naming the typefaces font family.
For example, the OT_Family in fonts:CGTimes.otag is ``bullet''.

OT_SymbolSet
------------
This tag's value is a two byte ASCII code for this typeface's symbol
set.  This tells the system which symbol set to use to map the Amiga
character set to the Compugraphic character set. The symbol set for
most CG fonts designed for use with the Amiga is ``L1'', which stands
for Latin1.  The exception is the CG fonts from Gold Disk, Inc.  They
use the ``GD'' (Gold Disk) symbol set.

OT_YSizeFactor
--------------
For traditional Amiga fonts, the font size does not include any
spacing on top or bottom of the typeface--the Amiga doesn't consider
it part of the font.  CG fonts include spacing on the top and bottom
of their typefaces.  This tag's value is a ratio of the point height
of a typeface to its ``black'' height (the point height minus the
space on the typeface's top and bottom).  The high word is the point
height factor and the low word is the black height factor.  Note that
these values form a ratio.  Individually, they do not necessarily
reflect any useful value.

OT_SerifFlag
------------
If this tag's value is TRUE, this typeface has serifs.

OT_StemWeight
-------------
This tag's value can be anywhere from 0 through 255 and indicates a
nominal weight or ``boldness'' to the typeface.  The
<diskfont/diskfonttag.h> include file defines a set of ratings for
this tag's value.  See that file for more details.  When the Diskfont
library opens an outline font, it uses this value to determine if a
typeface is bold.

OT_SlantStyle
-------------
The <diskfont/diskfonttag.h> include file defines a set of three
possible values for this tag's value.  See that file for more
details.  When the Diskfont library opens an outline font, it uses
this value to determine if a typeface is italicized/obliqued.

OT_HorizStyle
-------------
This tag's value can be anywhere from 0 through 255 and indicates a
nominal width rating to the typeface.  The <diskfont/diskfonttag.h>
include file defines a set of ratings for this tag's value.  See that
file for more details.  When the Diskfont library opens an outline
font, it uses this value to determine if a typeface is extended.

OT_AvailSizes
-------------
This tag's value points to a sorted list of UWORDs. The first UWORD
is the number of entries in the sorted list.  The remaining UWORDs
are the font sizes that the Diskfont library lists when calling
AvailFonts().

OT_SpecCount
------------
This tag's value is a number of spec tags that follow it.  A spec tag
is private to the scaling engine.


The following are Level 2 tags.  They may also be in an otag file but
are not required:

OT_BName
--------
This tag points to a string naming the bold variant of this typeface.
For example, the fonts:CGTimes.otag file lists ``CGTimesBold'' as its
bold variant.

OT_IName
--------
This tag points to a string naming the italic variant of this
typeface.

OT_BIName
---------
This tag points to a string naming the bold italic variant of this
typeface.

OT_SpaceWidth
-------------
This tag's value is the width of the space character at 250 points
(where there are 72.307 points in an inch).  The width is in Design
Window Units (DWUs).  One DWU is equal to 1/2540 inches. To convert
to X pixels:



```c
    OT_SpaceWidth   pointsize
    ------------- * --------- *  XDPI = spacewidth in pixels (X dots)
        2540           250
```
OT_IsFixed
----------
If this tag's value is TRUE, every glyph in this
typeface has the same character advance (a fixed width).

OT_InhibitAlgoStyle
-------------------
This tag's value is a bitmask that is compatible with the ta_Style
field of the TextAttr structure (defined in <graphics/text.h>).  This
tag tells which styles cannot be added to a typeface algorithmically.
For example, if the FSF_BOLD bit in OT_InhibitAlgoStyle is set and a
user asks for a bold version of the typeface, the diskfont.library
(or an application) can add that style algorithmically.


At present there are no Level 3 tags.

---

## See Also

- [AvailFonts — diskfont.library](../autodocs/diskfont.library.md#availfonts)
