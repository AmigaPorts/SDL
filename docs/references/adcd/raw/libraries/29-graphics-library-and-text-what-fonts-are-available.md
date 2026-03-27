# 29 Graphics Library and Text / What Fonts Are Available?


The diskfont.library function [AvailFonts()](../Includes_and_Autodocs_2._guide/node01F3.html) fills in a memory area
designated by you with a list of all of the fonts available to the system.
AvailFonts() searches the AmigaDOS directory path currently assigned to
FONTS: and locates all available fonts.  If you haven't issued a DOS
Assign command to change the FONTS: directory path, it defaults to the
sys:fonts directory.


```c
    LONG AvailFonts( struct AvailFontsHeader *mybuffer, LONG bufBytes,
                     LONG flags );
```
[AvailFonts()](../Includes_and_Autodocs_2._guide/node01F3.html) fills in a memory area, mybuffer, which is bufBytes bytes
long, with an [AvailFontsHeader](../Libraries_Manual_guide/node05F9.html#line104) structure:


```c
    struct AvailFontsHeader {
        UWORD   afh_NumEntries;      /* number of AvailFonts elements */
        /* struct AvailFonts afh_AF[], or struct TAvailFonts afh_TAF[]; */
    };
```
This structure is followed by an array of [AvailFonts](../Libraries_Manual_guide/node05F9.html#line94) structures with the
number of entries in the array equal to afh_NumEntries:


```c
    struct AvailFonts {
        UWORD   af_Type;            /* MEMORY, DISK, or SCALED */
        struct TextAttr af_Attr;    /* text attributes for font */
    };
```
Each [AvailFonts](../Libraries_Manual_guide/node05F9.html#line94) structure describes a font available to the OS.  The flags
field lets [AvailFonts()](../Includes_and_Autodocs_2._guide/node01F3.html) know which fonts you want to hear about.  At
present, there are four possible flags:

AFF_MEMORY  Create AvailFonts structures for all [TextFont](../Libraries_Manual_guide/node03DE.html)'s currently in

            the system list.
AFF_DISK    Create AvailFonts structures for all [TextFont](../Libraries_Manual_guide/node03DE.html)'s that are

            currently available from disk.
AFF_SCALED  Create AvailFonts structures for [TextFont](../Libraries_Manual_guide/node03DE.html)'s that do not have

```c
            their [FPF_DESIGNED](../Libraries_Manual_guide/node03D6.html#line70) flag set.  If the AFF_SCALED flag is not
            present, [AvailFonts()](../Includes_and_Autodocs_2._guide/node01F3.html) will not create AvailFonts structures
            for fonts that have been scaled, which do not have the
            FPF_DESIGNED flag set.
```
AFF_TAGGED  These AvailFonts structures are really [TAvailFonts](../Libraries_Manual_guide/node05F9.html#line99) structures.

```c
            These structures were created for Release 2 to allow
            [AvailFonts()](../Includes_and_Autodocs_2._guide/node01F3.html) to list tag values:

            struct TAvailFonts {
                UWORD   taf_Type;           /* MEMORY, DISK, or SCALED */
                struct TTextAttr taf_Attr;  /* text attributes for font */
            };
```
Notice that AFF_MEMORY and AFF_DISK are not mutually exclusive; a font
that is currently in memory may also be available for loading from disk.
In this case, the font will appear twice in the array of [AvailFonts](../Libraries_Manual_guide/node05F9.html#line94) (or
TAvailFonts) structures.

If [AvailFonts()](../Includes_and_Autodocs_2._guide/node01F3.html) fails without any major system problems, it will be
because the buffer for the [AvailFontsHeader](../Libraries_Manual_guide/node05F9.html#line104) structure was not big enough
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
The following code, AvailFonts.c, uses [AvailFonts()](../Includes_and_Autodocs_2._guide/node01F3.html) to find out what fonts
are available to the system.  It uses this information to open every
available font (one at a time), print some information about the font
(including the [TA_DeviceDPI](../Libraries_Manual_guide/node03DB.html#line65) tag values if they are present), and renders a
sample of the font into a clipping region.


```c
     [AvailFonts.c](../Libraries_Manual_guide/node05B7.html) 
```
