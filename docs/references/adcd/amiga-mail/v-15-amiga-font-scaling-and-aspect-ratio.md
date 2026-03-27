---
title: V-15: Amiga Font Scaling and Aspect Ratio
manual: amiga-mail
chapter: amiga-mail
section: v-15-amiga-font-scaling-and-aspect-ratio
functions: [ExtendFont, OpenDiskFont]
libraries: [diskfont.library, graphics.library]
---

# V-15: Amiga Font Scaling and Aspect Ratio

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by John Orr


[Editor's Note: This article assumes the reader is familiar with how the
Amiga stores and manages bitmap fonts under pre-2.0 Releases of the
operating system.  For more information, see the "Graphics: Text" chapter
of the RKM:Libraries and Devices Manual.]


The Release 2.0 OS offers a significant improvement over the Amiga's
previous font resources: it now has the ability to scale fonts to new
sizes and dimensions.  This means, if the diskfont.library can't find the
font size an application requests, it can create a new bitmap font by
scaling the bitmap of a different size font in the same font family.  The
2.04 release of the OS improved upon the diskfont.library's font scaling
ability so the Amiga now can utilize AGFA/Compugraphic outline fonts,
yielding scalable fonts that don't have the exaggerated jagged edges
inherent in bitmap scaling.

The best thing about the Amiga's font scaling is that its addition to the
system is completely invisible to an application program.  Because the
diskfont.library takes care of all the font scaling, any program that uses
OpenDiskFont() to open a font can have scalable fonts available to it.
For simple scaling, the programming interface is the same using Release
2.0 as it was under 1.3.

However, there is one feature of the 2.0 diskfont.library that the 1.3
programming interface cannot handle.  When scaling a font (either from an
outline or from another bitmap), the 2.0 diskfont.library can adjust the
width of a font's glyphs according to an aspect ratio passed to
OpenDiskFont().  A font glyph is the graphical representations associated
with each symbol or character of a font.

The aspect ratio refers to the shape of the pixels that make up the bitmap
that diskfont.library creates when it scales a font.  This ratio is the
width of a pixel to the height of the pixel (XWidth/YWidth).  The
diskfont.library uses this ratio to figure out how wide to make the font
glyphs so that the look of a font's glyphs will be the same on display
modes with very different aspect ratios.  For more information on Amiga
aspect ratios,  see Carolyn Scheppner's article, ``Finding the Aspect
Ratio'', from the September/October 1991 issue of Amiga Mail.

To add this new feature, several changes to the OS were necessary:


```c
    1) The OS needed to be able to store an aspect ratio for any font
       loaded into the system list,

    2) The structures that diskfont.library uses to store bitmap fonts on
       disk had to be updated so they can store the aspect ratio a font
       was designed for, and,

    3) The way in which an application requests fonts from
       diskfont.library had to be altered so that an application could
       askfor a specific aspect ratio.
```
For the diskfont.library to be able to scale a font to a new aspect ratio,
it needs to know what the font's current aspect ratio is.  The Amiga gets
the aspect ratio of a font currently in the system list from an extension
to the TextFont structure called (oddly enough) TextFontExtension.  Under
2.0, when the system opens a new font (and there is sufficient memory), it
creates this extension.

A font's TextFont structure contains a pointer to its associated
TextFontExtension.  While the font is opened, the TextFont's
tf_Message.mn_ReplyPort field points to a font's TextFontExtension.  The
<graphics/text.h> include file #defines tf_Message.mn_ReplyPort as
tf_Extension.

The TextFontExtension structure contains only one field of interest: a
pointer to a tag list associated with this font:


```c
    struct TagItem *tfe_Tags;   /* Text Tags for the font */
```
If a font has an aspect ratio associated with it, the OS stores the aspect
ratio as a tag/value pair in the tfe_Tags tag list.

The TA_DeviceDPI tag holds a font's aspect ratio.  The data portion of the
TA_DeviceDPI tag contains an X DPI (dots per inch) value in its upper word
and a Y DPI value in its lower word.  These values are unsigned words
(UWORD).  At present, these values do not necessarily reflect the font's
true X and Y DPI, so their specific values are not relevant.  At present,
only the ratio of the X aspect to the Y aspect is important (more on this
later in the article).

Notice that the X and Y DPI values are not aspect values.  The X and Y aspect
values are the reciprocals of the X and Y DPI values, respectively:


```c
    XDPI = 1/XAspect
    YDPI = 1/YAspect
```
so, the aspect ratio is YDPI/XDPI, not XDPI/YDPI.

Before accessing the tag list, an application should make sure that this
font has a corresponding TextFontExtension.  The ExtendFont() function
will return a value of TRUE if this font already has an extension or
ExtendFont() was able to create an extension for this font.

 [Where Do the X and Y DPI values Come From?](amiga-mail/where-do-the-x-and-y-dpi-values-come-from.md) 
 [Some Things to Look Out For](amiga-mail/some-things-to-look-out-for.md) 

---

## See Also

- [ExtendFont — graphics.library](../autodocs/graphics.library.md#extendfont)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
