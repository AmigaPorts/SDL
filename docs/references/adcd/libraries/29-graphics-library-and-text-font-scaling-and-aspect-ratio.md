---
title: 29 Graphics Library and Text / Font Scaling and Aspect Ratio
manual: libraries
chapter: libraries
section: 29-graphics-library-and-text-font-scaling-and-aspect-ratio
functions: [ExtendFont, OpenDiskFont]
libraries: [diskfont.library, graphics.library]
---

# 29 Graphics Library and Text / Font Scaling and Aspect Ratio

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Release 2 OS offers a significant improvement over the Amiga's
previous font resources: it now has the ability to scale fonts to new
sizes and dimensions.  This means, if the diskfont.library can't find the
font size an application requests, it can create a new bitmap font by
scaling the bitmap of a different size font in the same font family.  The
2.04 (V37) release of the OS improved upon the diskfont.library's font
scaling ability so the Amiga now can utilize AGFA Compugraphic outline
fonts, yielding scalable fonts that don't have the exaggerated jagged
edges inherent in bitmap scaling.

The best thing about the Amiga's font scaling is that its addition to the
system is completely invisible to an application program.  Because the
diskfont.library takes care of all the font scaling, any program that uses
[OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md) to open a font can have scalable fonts available to it.
For simple scaling, the programming interface is the same using Release 2
as it was under 1.3.

However, there is one feature of the Release 2 diskfont.library that the
1.3 programming interface cannot handle.  When scaling a font (either from
an outline or from another bitmap), the Release 2 diskfont.library can
adjust the width of a font's glyphs according to an aspect ratio passed to
[OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md).  A font glyph is the graphical representations associated
with each symbol or character of a font.

The aspect ratio refers to the shape of the pixels that make up the bitmap
that diskfont.library creates when it scales a font.  This ratio is the
width of a pixel to the height of the pixel (XWidth/ YWidth).  The
diskfont.library uses this ratio to figure out how wide to make the font
glyphs so that the look of a font's glyphs will be the same on display
modes with very different aspect ratios.

To add this new feature, several changes to the OS were necessary:

 1) The OS needed to be able to store an aspect ratio for any font loaded

    into the system list.
 2) The structures that diskfont.library uses to store bitmap fonts on

    disk had to be updated so they can store the aspect ratio a font was
    designed for.
 3) The way in which an application requests fonts from diskfont.library

    had to be altered so that an application could ask for a specific
    aspect ratio.
For the diskfont.library to be able to scale a font to a new aspect ratio,
it needs to know what the font's current aspect ratio is.  The Amiga gets
the aspect ratio of a font currently in the system list from an extension
to the [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md) structure called (oddly enough) [TextFontExtension](autodocs-2.0/includes-graphics-text-h.md).  Under
Release 2, when the system opens a new font (and there is sufficient
memory), it creates this extension.

A font's [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md) structure contains a pointer to its associated
[TextFontExtension](autodocs-2.0/includes-graphics-text-h.md).  While the font is opened, the TextFont's
tf_Message.mn_ReplyPort field points to a font's TextFontExtension.  The
<graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)> include file #defines tf_Message.mn_ReplyPort as
tf_Extension.

The [TextFontExtension](autodocs-2.0/includes-graphics-text-h.md) structure contains only one field of interest: a
pointer to a tag list associated with this font:


```c
    struct TagItem *tfe_Tags;               /* Text Tags for the font */
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

Notice that the X and Y DPI values are not aspect values.  The X and Y
aspect values are the reciprocals of the X and Y DPI values, respectively:


```c
    XDPI = 1/XAspect
    YDPI = 1/YAspect
```
so, the aspect ratio is YDPI/XDPI, not XDPI/YDPI.

Before accessing the tag list, an application should make sure that this
font has a corresponding [TextFontExtension](autodocs-2.0/includes-graphics-text-h.md).  The [ExtendFont()](autodocs-2.0/graphics-library-extendfont.md) function
will return a value of TRUE if this font already has an extension or
ExtendFont() was able to create an extension for this font.

The Amiga has a place to store a font's X and Y DPI values once the font
is loaded into memory, but where do these X and Y values come from?  A
font's X and Y DPI values can come from several sources.  The X and Y DPI
can come from a font's disk-based representation, or it can be set by the
programmer.

For the traditional Amiga bitmap fonts, in order to store the X and Y DPI
values in a bitmap font's ".font" file, the structures that make up the
".font" file had to be expanded slightly.  See the discussion of the
[FontContentsHeader](libraries/29-graphics-library-and-text-composition-of-a-bitmap-font.md) structure in the "[Composition of a Bitmap Font on Disk](libraries/29-graphics-library-and-text-composition-of-a-bitmap-font.md)"
section later in this chapter for more information.  Currently, out of all
the system standard bitmap fonts (those loaded from bitmaps on disk or
ROM, not scaled from a bitmap or outline), only one has a built in aspect
ratio: Topaz-9.

For the Compugraphic outline fonts, the X and Y DPI values are built into
the font outline.  Because the format of the Compugraphic outline fonts is
proprietary, information about their layout is available only from AGFA
Compugraphic.  For most people, the format of the outline fonts is not
important, as the diskfont.library handles converting the fonts to an
Amiga-usable form.

The other place where a font can get an aspect ratio is an application.
When an application opens a font with [OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md), it can supply the
TA_DeviceDPI tag that the diskfont.library uses to scale (if necessary)
the font according to the aspect ratio.  To do so, an application has to
pass OpenDiskFont() an extended version of the [TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure called
the [TTextAttr](autodocs-2.0/includes-graphics-text-h.md):


```c
    struct TTextAttr {
        STRPTR  tta_Name;           /* name of the font           */
        UWORD   tta_YSize;          /* height of the font         */
        UBYTE   tta_Style;          /* intrinsic font style       */
        UBYTE   tta_Flags;          /* font preferences and flags */
        struct TagItem *tta_Tags;   /* extended attributes        */
    };
```
The [TextAttr](libraries/29-the-text-function-choosing-the-font.md) and the TTextAttr are identical except that the tta_Tags
field points to a tag list where you place your TA_DeviceDPI tag.  To tell
[OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md) that it has a TTextAttr structure rather than a TextAttr
structure, set the FSF_TAGGED bit in the tta_Style field.

For example, to ask for Topaz-9 scaled to an aspect ratio of 75 to 50 the
code might look something like this:


```c
    #define MYXDPI (75L << 16)
    #define MYYDPI (50L)

    struct TTextAttr mytta = {
        "topaz.font", 9,
        FSF_TAGGED,   0, NULL
    };

    struct TagItem tagitem[2];
    struct TextFont *myfont;
    ULONG dpivalue;

     . . .

    tagitem[0].ti_tag = TA_DeviceDPI;
    tagitem[0].ti_Data = MYXDPI | MYYDPI;
    tagitem[1].ti_tag = TAG_END;
    mytta.tta_tags = tagitem;

     . . .

    if (myfont = OpenDiskFont(&mytta))
    {
        dpi = GetTagData(TA_DeviceDPI,
                         OL,
                         ((struct TextFontExtension *)
                          (myfont->tf_Extension))->tfe_Tags);
        if (dpi) printf("XDPI = %d    YDPI = %d\n",
                        ((dpi & 0xFFFF0000)>>16),
                        (dpi & 0x0000FFFF));
              . . .                             /* Blah Blah print blah */

        CloseFont(myfont);
    }
```

---

## See Also

- [ExtendFont — graphics.library](../autodocs/graphics.library.md#extendfont)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
