---
title: Where Do the X and Y DPI values Come From?
manual: amiga-mail
chapter: amiga-mail
section: where-do-the-x-and-y-dpi-values-come-from
functions: [OpenDiskFont]
libraries: [diskfont.library]
---

# Where Do the X and Y DPI values Come From?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga has a place to store a font's X and Y DPI values once the font
is loaded into memory, but where do these X and Y values come from?  A
font's X and Y DPI values can come from several sources.  The X and YDPI
can come from a font's disk-based representation, or it can be set by the
programmer.

For the traditional Amiga bitmap fonts, in order to store the X and Y DPI
values in a bitmap font's .font file, the structures that make up the
.font file had to be expanded slightly.  There are two changes from the
structures described in the ``Graphics:Text'' chapter of the RKM:
Libraries and Devices manual.  The first is that the fch_FileID in the
FontContentsHeader structure (essentially, the .font file) contains a
different file ID (TFCH_ID from <libraries/diskfont.h>) from the
traditional .font file.  This tells the diskfont.library that this
FontContentsHeader uses a special kind of FontContents structure called a
TFontContents structure.  The difference between these structures is that
the TFontContents structure allows the OS to store tag value pairs in the
extra space set aside for the font's name.


```c
    struct TFontContents {
        char    tfc_FileName[MAXFONTPATH-2];
        UWORD   tfc_TagCount;       /* including the TAG_DONE tag */
        /*
         * if tfc_TagCount is non-zero, tfc_FileName is overlayed with
         * Text Tags starting at:  (struct TagItem *)
         * &tfc_FileName[MAXFONTPATH-(tfc_TagCount*sizeof(struct TagItem))]
         */
        UWORD   tfc_YSize;
        UBYTE   tfc_Style;
        UBYTE   tfc_Flags;
    };
```
Currently, out of all the system standard bitmap fonts (ones loaded from
bitmaps on disk or ROM, not scaled from a bitmap or outline), only one has
a built in aspect ratio: Topaz-9.

For the Compugraphic outline fonts, the X and Y DPI values are built into
the font outline.  Because the format of the Compugraphic outline fonts is
proprietary, information about their layout is available only from
AGFA/Compugraphic.  For most people, the format of the outline fonts is
not important, as the diskfont.library handles converting the fonts to an
Amiga-usable form.

The other place where a font can get an aspect ratio is an application.
When an application opens a font with OpenDiskFont(), it can supply the
TA_DeviceDPI tag that the diskfont.library uses to scale (if necessary)
the font according to the aspect ratio.  To do so, an application has to
pass OpenDiskFont() an extended version of the TextAttr structure called
the TTextAttr:


```c
    struct TTextAttr {
        STRPTR  tta_Name;           /* name of the font */
        UWORD   tta_YSize;          /* height of the font */
        UBYTE   tta_Style;          /* intrinsic font style */
        UBYTE   tta_Flags;          /* font preferences and flags */
        struct TagItem *tta_Tags;   /* extended attributes */
    };
```
The TextAttr and the TTextAttr are identical except that the tta_Tags
field points to a tag list where you place your TA_DeviceDPI tag.  To tell
OpenDiskFont() that it has a TTextAttr structure rather than a TextAttr
structure, set the FSF_TAGGED bit in the tta_Style field.

For example, to ask for Topaz-9 scaled to an aspect ratio of 75 to 50, the
code might look something like this:


...

#define MYXDPI (75L << 16)
#define MYYDPI (50L)

struct TTextAttr mytta = {
   "topaz.font",
   9,
   FSF_TAGGED,
   0L,
   NULL
};

struct TagItem tagitem[2];
struct TextFont *myfont;
ULONG dpivalue;
struct Library *UtilityBase, *DiskfontBase, *GfxBase;
void main(void)
{
   tagitem[0].ti_Tag = TA_DeviceDPI;
   tagitem[0].ti_Data = MYXDPI | MYYDPI;
   tagitem[1].ti_Tag = TAG_END;

...
```c
     if (myfont = OpenDiskFont(&mytta))
     {
        dpivalue = GetTagData(TA_DeviceDPI,
           0L,
           ((struct TextFontExtension *)(myfont->tf_Extension))->tfe_Tags);
        if (dpivalue) printf("XDPI = %d    YDPI = %d\n",
                        ((dpivalue & 0xFFFF0000)>>16),
                        (dpivalue & 0x0000FFFF));
        /* blah, blah, render some text, blah, blah */
        ...

       CloseFont(myfont);
```
   }
...

}

From  [FTA.c](amiga-mail/v-15-fta-c.md) 

---

## See Also

- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
