---
title: Width Lists
manual: amiga-mail
chapter: amiga-mail
section: width-lists
functions: []
libraries: []
---

# Width Lists

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An application can find the widths of a typeface's glyphs using the
OT_WidthList tag with one of the ObtainInfo() functions.  The engine
expects the OT_WidthList value to be an address where it can place
the address of a MinList structure.  This MinList points to a list of
GlyphWidthEntry structures.  The GlyphWidthEntry structure (defined
in <diskfont/glyph.h>) is for reading only and looks like this:

struct GlyphWidthEntry {
```c
    struct MinNode gwe_Node;  /* on list returned by OT_WidthList */
                              /* inquiry */
    UWORD          gwe_Code;  /* entry's character code value */
    FIXED          gwe_Width; /* character advance, as fraction of */
                              /* em width */
```
};

The MinList contains an entry for each valid Unicode glyph ranging
from the primary glyph, OT_GlyphCode, through the secondary glyph,
OT_GlyphCode2.  The engine does not create a GlyphWidthEntry
structure for codes without glyphs (for example the codes before the
space character in the Latin-1 character set).

When an application is finished with the width list, it must use one
of the ReleaseInfo() functions to relinquish the list.  This function
uses the same format as the ObtainInfo() functions, except the data
value of the OT_WidthList tag is a pointer to the MinList (rather
than a pointer to a pointer).  The primary and secondary code values
do not have to remain constant while an application is using a width
list.  The engine deallocates the width list resources independently
of the primary and secondary code values, so these can change after
obtaining a width list.

The following code fragment asks the scaling engine, ge, for a list
of character widths of the Unicode glyphs ranging from unicode
(OT_GlyphCode) to unicode2 (OT_GlyphCode2), inclusive.  The fragment
steps through the list of widths, printing each one.


struct MinList *widthlist;
struct GlyphWidthEntry *widthentry;
.  .  .

if (SetInfo(ge,
```c
            OT_GlyphCode,   unicode,
            OT_GlyphCode2,  unicode2,
            TAG_END) == OTERR_Success)
```
{
```c
    if (ObtainInfo(ge, OT_WidthList, &widthlist, TAG_END) == OTERR_Success)
    {
        for (widthentry = (struct GlyphWidthEntry *) widthlist->mlh_Head;
            widthentry->gwe_Node.mln_Succ;
            widthentry = (struct GlyphWidthEntry *)
            widthentry->gwe_Node.mln_Succ)
        {
            printf("$%lx: %ld.%ld\n",
                widthentry->gwe_Code,
                widthentry->gwe_Width>>16,
                ((widthentry->gwe_Width&0xffff)*10000)>>16);
        }
        ReleaseInfo(ge, OT_WidthList, widthlist, TAG_END);
    }
```
}
.  .  .


Notice that the ObtainInfo() functions (as well as the SetInfo()
functions) return an error code (the error codes are defined in
<diskfont/oterrors.h>).  If that error code is equal to
OTERR_Success, the operation was successful.

