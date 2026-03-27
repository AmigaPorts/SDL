---
title: FONS (0x464F4E53)       / Font chunk (Same as FTXT FONS chunk) /
manual: amiga-mail
chapter: amiga-mail
section: fons-0x464f4e53-font-chunk-same-as-ftxt-fons-chunk
functions: []
libraries: []
---

# FONS (0x464F4E53)       / Font chunk (Same as FTXT FONS chunk) /

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The FONS chunk contains information about a font used in the DR2D
FORM.  ProVector does not include support for Amiga fonts.  Instead,
ProVector uses fonts defined in the OFNT FORM which is documented
later in this article.


```c
    struct FONSstruct {
        ULONG       ID;
        ULONG       Size;
        UBYTE       FontID;         /* ID the font is referenced by */
        UBYTE       Pad1;           /* Always 0 */
        UBYTE       Proportional;   /* Is it proportional? */
        UBYTE       Serif;          /* does it have serifs? */
        CHAR        Name[Size-4];   /* The name of the font */
    };
```
The UBYTE FontID field is the number DR2D assigns to this font.
References to this font by other DR2D chunks are made using this
number.

The Proportional and Serif fields indicate properties of this font.
Specifically, Proportional indicates if this font is proportional, and
Serif indicates if this font has serifs.  These two options were
created to allow for font substitution in case the specified font is
not available.  They are set according to these values:


    0       The DR2D writer didn't know if this font is
              proportional/has serifs.
    1       No, this font is not proportional/does not have
              serifs.
    2       Yes, this font is proportional/does have serifs.
The last field, Name[], is a NULL terminated string containing the
name of the font.

