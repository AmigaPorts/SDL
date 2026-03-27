---
title: 29 Graphics Library and Text / Some Things to Look Out For
manual: libraries
chapter: libraries
section: 29-graphics-library-and-text-some-things-to-look-out-for
functions: [OpenDiskFont]
libraries: [diskfont.library]
---

# 29 Graphics Library and Text / Some Things to Look Out For

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One misleading thing about the [TA_DeviceDPI](libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md) tag is that its name implies
that the diskfont.library is going to scale the font glyphs according to
an actual DPI (dots per inch) value.  As far as scaling is concerned, this
tag serves only as a way to specify the aspect ratio, so the actual values
of the X and Y elements are not important, just the ratio of one to the
other.  A font glyph will look the same if the ratio is 2:1 or 200:100 as
these two ratios are equal.

To makes things a little more complicated, when diskfont.library scales a
bitmap font using an aspect ratio, the X and Y DPI values that the OS
stores in the font's [TextFontExtension](libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md) are identical to the X and Y DPI
values passed in the [TA_DeviceDPI](libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md) tag.  This means the system can
associate an X and Y DPI value to an open font size that is very different
from the font size's actual X and Y DPI.  For this reason, applications
should not use these values as real DPI values.  Instead, only use them to
calculate a ratio.

For the Compugraphic outline fonts, things are a little different.  The X
and Y DPI values are built into the font outline and reflect a true X and
Y DPI.  When the diskfont.library creates a font from an outline, scaling
it according to an application-supplied aspect ratio, diskfont.library
does not change the Y DPI setting.  Instead, it calculates a new X DPI
based on the font's Y DPI value and the aspect ratio passed in the
[TA_DeviceDPI](libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md) tag.  It does this because the Amiga thinks of a font size as
being a height in pixels.  If an application was able to change the true Y
DPI of a font, the diskfont.library would end up creating font sizes that
were much larger or smaller than the YSize the application asked for.  If
an application needs to scale a font according to height as well as width,
the application can adjust the value of the YSize it asks for in the
[TTextAttr](libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md).

As mentioned earlier, almost all of the system standard bitmap fonts do
not have a built in aspect ratio.  This means that if an application loads
one of these bitmap fonts without supplying an aspect ratio, the system
will not put a [TA_DeviceDPI](libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md) tag in the font's [TextFontExtension](libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md): the font
will not have an aspect ratio.  If a font size that is already in the
system font list does not have an associated X and Y DPI, the
diskfont.library cannot create a new font of the same size with a
different aspect ratio.

The reason for this is the diskfont.library cannot tell the difference
between two instances of the same font size where one has an aspect ratio
and the other does not.  Because diskfont.library cannot see this
difference, when an application asks, for example, for Topaz-8 with an
aspect ratio of 2:1, [OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md) first looks through the system list to
see if that font is loaded.  OpenDiskFont() happens to find the ROM font
Topaz-8 in the system font list, which has no X and Y DPI.  Because it
cannot see the difference, diskfont.library thinks it has found what it
was looking for, so it does not create a new Topaz-8 with an aspect ratio
of 2:1, and instead opens the Topaz-8 with no aspect ratio.

This also causes problems for programs that do not ask for a specific
aspect ratio.  When an application asks for a font size without specifying
an aspect ratio, [OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md) will not consider the aspect ratios of
fonts in the system font list when it is looking for a matching font.  If
a font of the same font and style is already in the system font list, even
though it may have a wildly distorted aspect ratio, OpenDiskFont() will
return the font already in the system rather than creating a new one.

 [Font Aspect Ratio Example](libraries/lib-examples-cliptext-c.md) }

---

## See Also

- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
