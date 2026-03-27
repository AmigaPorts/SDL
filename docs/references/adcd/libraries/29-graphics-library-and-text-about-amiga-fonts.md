---
title: 29 Graphics Library and Text / About Amiga Fonts
manual: libraries
chapter: libraries
section: 29-graphics-library-and-text-about-amiga-fonts
functions: []
libraries: []
---

# 29 Graphics Library and Text / About Amiga Fonts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In order to render text, the Amiga needs to have a graphical
representation for each symbol or text character.  These individual images
are known as glyphs.  The Amiga gets each glyph from a font in the system
font list.  At present, the fonts in the system list contain a bitmap of a
specific point size for all the characters and symbols of the font.

Fonts are broken up into different font families.  For example, the
Amiga's Topaz is a font family.  Each font family shares a basic look but
can have a variety of styles and point sizes.

The style of a font refers to a minor alteration in the way the plain
version of the font's characters are rendered.  Currently, the Amiga
supports three font styles: bold, italics and underline (the font's style
may also be considered plain when it does not have any of these styles).
Although these styles can be inherent to a font, they are normally added
algorithmically as text is rendered.

On the Amiga, the point size of a font normally refers to the height of
the font in pixels.  For example, Topaz-8 is 8 pixels high.  Because the
size of Amiga pixels varies between display modes, the appearance of a
font will also vary between display modes.  Future versions of the Amiga
OS may measure font size in other units.  For example, the standard point
in the PostScript page description language normally refers to a point as
being a square dot that is 1/72 of an inch on a side.  Using a standard
measuring unit such as the PostScript point makes it possible to create a
WYSIWYG (What You See Is What You Get) display that exactly matches
printer or other device output.

When the Amiga first starts up, the only fonts in the system font list are
Topaz-8 and Topaz-9, both of which are in ROM.  Any other fonts must be
loaded from disk or generated somehow.  In Amiga operating systems prior
to Release 2, additional fonts have to be loaded from disk (usually from
the FONTS: directory) using the diskfont.library.  For each font size of
each font family there is a corresponding bitmap file on disk.  If there
is no bitmap on disk or in ROM for a specific font size, that font size is
not available (if the operating system is 1.3 or earlier).

 [System Fonts In Release 2](libraries/29-about-amiga-fonts-system-fonts-in-release-2.md) 

