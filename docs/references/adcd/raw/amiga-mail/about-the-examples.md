# About the Examples


This article contains two code examples.  The first, [Rotate.c](../AmigaMail_Vol2_guide/node01CA.html), rotates
a user-specified glyph around a central point.  By default, it
rotates a 36 point 'A' using the font fonts:CGTimes.font.  If Rotate
finds an AmigaDOS environment variable called "XYDPI", it will use
the X and Y DPI it finds in that variable as the default target
device DPI (see the description of the Level 0 OT_DeviceDPI tag).  If
that variable is not defined, Rotate will use an XDPI of 68 and a
YDPI of 27 which, nominally, is the X and Y DPI of a standard Hires
display.

The second example, [View.c](../AmigaMail_Vol2_guide/node01CB.html), displays a file using the same defaults as
Rotate.  View utilizes kerning pairs to display its glyphs.  Because
View only considers "visible" characters, it ignores characters
that have widths but no glyph.  The result is, View doesn't print any
space characters.  If View were smarter, it would ask the scaling
engine for a width list so it could properly advance the current
pointer when it comes across a space or some other character without
a glyph.

Notice that View uses a slightly modified version of [BulletMain.c](../AmigaMail_Vol2_guide/node01CC.html)
called [BulletMainFile.c](../AmigaMail_Vol2_guide/node01CD.html).  Only BulletMain.c appears in the example
code.  The only significant difference between the two is that
BulletMainFile.c obtains a file name for View to display.

