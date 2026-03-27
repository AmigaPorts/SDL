---
title: 29 Graphics Library and Text / What Fonts Are Available?
manual: libraries
chapter: libraries
section: 29-graphics-library-and-text-what-fonts-are-available
functions: [AvailFonts]
libraries: [diskfont.library]
---

# 29 Graphics Library and Text / What Fonts Are Available?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The diskfont.library function [AvailFonts()](autodocs-2.0/diskfont-library-availfonts.md) fills in a memory area
designated by you with a list of all of the fonts available to the system.
AvailFonts() searches the AmigaDOS directory path currently assigned to
FONTS: and locates all available fonts.  If you haven't issued a DOS
Assign command to change the FONTS: directory path, it defaults to the
sys:fonts directory.


```c
    LONG AvailFonts( struct AvailFontsHeader *mybuffer, LONG bufBytes,
                     LONG flags );
```
[AvailFonts()](autodocs-2.0/diskfont-library-availfonts.md) fills in a memory area, mybuffer, which is bufBytes bytes
long, with an [AvailFontsHeader](libraries/includes-diskfont-diskfont-h.md) structure:


```c
    struct AvailFontsHeader {
        UWORD   afh_NumEntries;      /* number of AvailFonts elements */
        /* struct AvailFonts afh_AF[], or struct TAvailFonts afh_TAF[]; */
    };
```
This structure is followed by an array of [AvailFonts](libraries/includes-diskfont-diskfont-h.md) structures with the
number of entries in the array equal to afh_NumEntries:


```c
    struct AvailFonts {
        UWORD   af_Type;            /* MEMORY, DISK, or SCALED */
        struct TextAttr af_Attr;    /* text attributes for font */
    };
```
Each [AvailFonts](libraries/includes-diskfont-diskfont-h.md) structure describes a font available to the OS.  The flags
field lets [AvailFonts()](autodocs-2.0/diskfont-library-availfonts.md) know which fonts you want to hear about.  At
present, there are four possible flags:

AFF_MEMORY  Create AvailFonts structures for all [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md)'s currently in

            the system list.
AFF_DISK    Create AvailFonts structures for all [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md)'s that are

            currently available from disk.
AFF_SCALED  Create AvailFonts structures for [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md)'s that do not have

```c
            their [FPF_DESIGNED](libraries/29-the-text-function-choosing-the-font.md) flag set.  If the AFF_SCALED flag is not
            present, [AvailFonts()](autodocs-2.0/diskfont-library-availfonts.md) will not create AvailFonts structures
            for fonts that have been scaled, which do not have the
            FPF_DESIGNED flag set.
```
AFF_TAGGED  These AvailFonts structures are really [TAvailFonts](libraries/includes-diskfont-diskfont-h.md) structures.

```c
            These structures were created for Release 2 to allow
            [AvailFonts()](autodocs-2.0/diskfont-library-availfonts.md) to list tag values:

            struct TAvailFonts {
                UWORD   taf_Type;           /* MEMORY, DISK, or SCALED */
                struct TTextAttr taf_Attr;  /* text attributes for font */
            };
```
Notice that AFF_MEMORY and AFF_DISK are not mutually exclusive; a font
that is currently in memory may also be available for loading from disk.
In this case, the font will appear twice in the array of [AvailFonts](libraries/includes-diskfont-diskfont-h.md) (or
TAvailFonts) structures.

If [AvailFonts()](autodocs-2.0/diskfont-library-availfonts.md) fails without any major system problems, it will be
because the buffer for the [AvailFontsHeader](libraries/includes-diskfont-diskfont-h.md) structure was not big enough
to contain all of the AvailFonts or TAvailFonts structures.  In this case,
AvailFonts() returns the number of additional bytes that mybuffer needed
to contain all of the TAvailFonts or AvailFonts structures.  You can then
use that return value to figure out how big the buffer needs to be,
allocate that memory, and try AvailFonts() again:

int afShortage, afSize;
struct AvailFontsHeader *afh;
 . . .


```c
    afSize = AvailFonts(afh, 0L, AFF_MEMORY|AFF_DISK|AFF_SCALED|
                                                     AFF_TAGGED);
    do
    {
        afh = (struct AvailFontsHeader *) AllocMem(afSize, 0);
        if (afh)
        {
            afShortage = AvailFonts(afh, afSize, AFF_MEMORY|AFF_DISK|
                                                 AFF_SCALED|AFF_TAGGED);
            if (afShortage)
            {
                FreeMem(afh, afSize);
                afSize += afShortage;
            }
        }
        else
        {
            fail("AllocMem of AvailFonts buffer afh failed\n");
            break;
        }
    } while (afShortage); /* if (afh) non-zero here, then:             */
                          /* 1. it points to a valid AvailFontsHeader, */
                          /* 2. it must have FreeMem(afh, afSize)      */
                          /* called for it after use. */
```
The following code, AvailFonts.c, uses [AvailFonts()](autodocs-2.0/diskfont-library-availfonts.md) to find out what fonts
are available to the system.  It uses this information to open every
available font (one at a time), print some information about the font
(including the [TA_DeviceDPI](libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md) tag values if they are present), and renders a
sample of the font into a clipping region.


```c
     [AvailFonts.c](libraries/lib-examples-availfonts-c.md) 
```

---

## See Also

- [AvailFonts — diskfont.library](../autodocs/diskfont.library.md#availfonts)
