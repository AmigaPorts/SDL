---
title: Standard Data and Property Chunks / Property Chunk FONS
manual: devices
chapter: devices
section: standard-data-and-property-chunks-property-chunk-fons
functions: []
libraries: []
---

# Standard Data and Property Chunks / Property Chunk FONS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The optional property "FONS" holds a FontSpecifier as defined in the C
declaration below.  It assigns a font to a numbered "font register" so it
can be referenced by number within subsequent [CHRS](devices/standard-data-and-property-chunks-data-chunk-chrs.md) chunks.  (This function
is not provided within the ISO and ANSI standards.)  The font specifier
gives both a name and a description for the font so the recipient program
can do font substitution. 

By default, [CHRS](devices/standard-data-and-property-chunks-data-chunk-chrs.md) text uses font 1 until it selects another font.  A
minimal text reader always uses font 1.  If font 1 hasn't been specified,
the reader may use the local system font as font 1.


typedef struct {
  UBYTE id;     /* 0 through 9 is a font id number referenced by an SGR
                   control sequence selective parameter of 10 through 19.
                   Other values are reserved for future standardization. */
  UBYTE pad1;   /* reserved for future use; store 0 here                 */
  UBYTE proportional; /* proportional font-- 0=unknown, 1=no, 2=yes      */
  UBYTE serif;  /* serif font-- 0 = unknown, 1 = no, 2 = yes             */
  char  name[]; /* A NUL-terminated string naming the preferred font.    */
  } FontSpecifier;


Fields are filed in the order shown.  The UBYTE fields are byte-packed (2
per 16-bit word).  The field pad1 is reserved for future standardization.
Programs should store 0 there for now.

The field proportional indicates if the desired font is proportional width
as opposed to fixed width.  The field serif indicates if the desired font
is serif as opposed to sans serif. [Issue: Discuss font substitution!]

