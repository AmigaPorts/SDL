---
title: ILBM.CLUT.DOC / Specifications
manual: devices
chapter: devices
section: ilbm-clut-doc-specifications
functions: []
libraries: []
---

# ILBM.CLUT.DOC / Specifications

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* Here is the IFF chunk ID macro for a CLUT chunk */

#define ID_CLUT MakeID('C','L','U','T')

/*
 * Defines for different flavors of 8-bit CLUTs.
 */
#define CLUT_MONO       0L   /* A Monochrome, contrast or intensity LUT */
#define CLUT_RED        1L   /* A LUT for reds               */
#define CLUT_GREEN      2L   /* A LUT for greens             */
#define CLUT_BLUE       3L   /* A LUT for blues              */
#define CLUT_HUE        4L   /* A LUT for hues               */
#define CLUT_SAT        5L   /* A LUT for saturations        */
#define CLUT_UNUSED6    6L   /* How about a Signed Data flag */
#define CLUT_UNUSED7    7L   /* Or an Assumed Negative flag  */

/* All types > 7 are reserved until formally claimed */
#define CLUT_RESERVED_BITS 0xfffffff8L

/* The struct for Color Look-Up-Tables of all types */
typedef struct
{
  ULONG type;		/* See above type defines */
  ULONG res0;		/* RESERVED FOR FUTURE EXPANSION */
  UBYTE lut[256];	/* The 256 byte look up table */
} ColorLUT;

