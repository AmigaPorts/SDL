---
title: 29 Graphics Library and Text / Composition of a Bitmap Font on Disk
manual: libraries
chapter: libraries
section: 29-graphics-library-and-text-composition-of-a-bitmap-font
functions: [LoadSeg]
libraries: [dos.library]
---

# 29 Graphics Library and Text / Composition of a Bitmap Font on Disk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For each Amiga bitmap font stored on disk (normally in the FONTS: assign
directory), there is a corresponding ".font" file, a directory, and within
that directory, a series of files bearing numeric names.  For example, for
the font Sapphire, within FONTS:, there is a file called sapphire.font, a
directory called Sapphire, and within the directory Sapphire are the files
14 and 19.

For a bitmap font (including color fonts), the ".font" file is a
[FontContentsHeader](libraries/includes-diskfont-diskfont-h.md) structure:


```c
    struct FontContentsHeader {
        UWORD   fch_FileID;     /* FCH_ID */
        UWORD   fch_NumEntries; /* the number of FontContents elements */
        struct FontContents fch_FC[];
                                /* or struct TFontContents fch_TFC[];  */
    };

    #define MAXFONTPATH 256
```
Where the fch_FileID field can be be either:


    FCH_ID    0x0f00    This FontContentsHeader uses FontContents
                        structures to describe the available sizes of
                        this font.


    TFCH_ID   0x0f02    This FontContentsHeader uses TFontContents
                        structures to describe the available sizes of
                        this font.
The fch_FileID can also be equal to 0x0f03, but that is only for scalable
outline fonts.

The [FontContents](libraries/includes-diskfont-diskfont-h.md) structure:


```c
    struct FontContents {
        char    fc_FileName[MAXFONTPATH];
        UWORD   fc_YSize;
        UBYTE   fc_Style;
        UBYTE   fc_Flags;
    };
```
describes one of the sizes of this font that is available to the system as
a designed font size.  For each FontContents structure, there should be a
corresponding font descriptor file in this font's directory that contains
data for this size font.  The FontContents fields correspond to the
similarly named field in the [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md) structure.

The [TFontContents](libraries/includes-diskfont-diskfont-h.md) structure is almost the same as the FontContents
structure except that it allows the OS to store tag value pairs in the
extra space not used by the file name.  Currently, this allows the OS to
preserve the X and Y DPI ([TA_DeviceDPI](libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md)) values for a font.


```c
    struct TFontContents {
        char    tfc_FileName[MAXFONTPATH-2];
        UWORD   tfc_TagCount;       /* including the TAG_DONE tag */
        /*
         *  if tfc_TagCount is non-zero, tfc_FileName is overlaid with
         *  Text Tags starting at:  (struct TagItem *)
         *      &tfc_FileName[MAXFONTPATH-(tfc_TagCount*sizeof
         *                                 (struct TagItem))]
         */
        UWORD   tfc_YSize;
        UBYTE   tfc_Style;
        UBYTE   tfc_Flags;
    };
```
The fch_NumEntries contains the number of font sizes (and the number of
FontContents or TFontContents structures) that this ".font" file
describes.  The fch_FC[] is the array of FontContents or TFontContents
structures that describe this font.

For each font size described in a FontContents (or TFontContents)
structure, there is a corresponding file in that font's directory whose
name is its size.  For example, for the font size Sapphire-19, there is a
file in the Sapphire directory called 19.  That file is basically a
[DiskFontHeader](libraries/includes-diskfont-diskfont-h.md) disguised as a loadable DOS hunk and is known as a font
descriptor file.  This allows the diskfont.library to use the dos.library
to load the module just like it was a hunk of relocatable 680x0
instructions.  It even contains two instructions before the real
DiskFontHeader structure that will cause the 680x0 to stop running the
DiskFontHeader if it does inadvertently get executed.


```c
    #define  MAXFONTNAME    32      /* font name including ".font" */

    struct DiskFontHeader {
        /* the following 8 bytes are not actually considered a part of */
        /* the DiskFontHeader, but immediately precede it. The         */
        /* NextSegment is supplied by the linker/loader, and the       */
        /* ReturnCode is the code at the beginning of the font in case */
        /* someone runs it...                                          */
        /*   ULONG dfh_NextSegment;               actually a BPTR      */
        /*   ULONG dfh_ReturnCode;                MOVEQ #0,D0 : RTS    */
        /* here then is the official start of the DiskFontHeader...    */
        struct Node dfh_DF;            /* node to link disk fonts */
        UWORD dfh_FileID;            /* DFH_ID */
        UWORD dfh_Revision;          /* the font revision */
        LONG  dfh_Segment;           /* the segment address when loaded */
        char  dfh_Name[MAXFONTNAME]; /* the font name (null terminated) */
        struct TextFont dfh_TF;        /* loaded TextFont structure */
    };

    /* unfortunately, this needs to be explicitly typed */
    /* used only if dfh_TF.tf_Style FSB_TAGGED bit is set */
    #define dfh_TagList     dfh_Segment     /* destroyed during loading */
```
The dfh_DF field is an Exec [Node](libraries/23-list-structure-node-structure-definition.md) structure that the diskfont library uses
to link together the fonts it has loaded.  The dfh_FileID field contains
the file type, which currently is DFH_ID (defined in
<libraries/[diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md)>).  The dfh_Revision field contains a revision
number for this font.  The dfh_Segment field will contain the segment
address when the font is loaded.  The dfh_FontName field will contain the
font's name after the font descriptor is [LoadSeg()](autodocs-2.0/dos-library-loadseg.md)'ed.  The last field,
dfh_TextFont is a [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md) structure (or [ColorTextFont](libraries/29-graphics-library-and-text-but-what-about-color-fonts.md) structure) as
described in the previous section.  The following is a complete example of
a proportional, bitmap font.


```c
     [suites8.asm](libraries/lib-examples-suits8-asm.md) 
```

---

## See Also

- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
