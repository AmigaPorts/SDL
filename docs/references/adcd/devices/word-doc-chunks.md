---
title: WORD.doc / Chunks
manual: devices
chapter: devices
section: word-doc-chunks
functions: []
libraries: []
---

# WORD.doc / Chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 *   FONT - Font name/number table
 *   There are one of these for each font/size combination
 *   These chunks should appear at the top of the file
 *   (before document data)
 */

   typedef struct {
```c
      UBYTE   Num;         /* 0 .. 255 */
      UWORD   Size;
```
   /* UBYTE   Name[];      */   /* NULL terminated, without ".font" */
   } FontID;

/*
 *   COLR - Color translation table
 *   Translates from color numbers used in file to ISO color numbers
 *   Should be at top of file (before document data)
 *   Note:  Currently ProWrite only checks these values to be its
 *      current map, it does no translation as it does for FONT chunks
 */

   typedef struct {
```c
      UBYTE   ISOColors[8];
```
   } ISOColors;

/*
 *   DOC - Begin document section
 *   All text and paragraph formatting following this chunk and up to a
 *   HEAD, FOOT, or PICT chunk belong to the document section
 */

   #define PAGESTYLE_1   0      /* 1, 2, 3 */
   #define PAGESTYLE_I   1      /* I, II, III */
   #define PAGESTYLE_i   2      /* i, ii, iii */
   #define PAGESTYLE_A   3      /* A, B, C */
   #define PAGESTYLE_a   4      /* a, b, c */

   typedef struct {
```c
      UWORD   StartPage;      /* Starting page number */
      UBYTE   PageNumStyle;   /* From defines above */
      UBYTE   pad1;
      LONG    pad2;
```
   } DocHdr;

/*
 *   HEAD/FOOT - Begin header/footer section
 *   All text and paragraph formatting following this chunk and up to a
 *   DOC, HEAD, FOOT, or PICT chunk belong to this header/footer
 *   Note:  This format supports multiple headers and footers, but
 *      currently ProWrite only allows a single header and footer per
 *      document
 */

   #define PAGES_NONE   0
   #define PAGES_LEFT   1
   #define PAGES_RIGHT  2
   #define PAGES_BOTH   3

   typedef struct {
```c
      UBYTE   PageType;       /* From defines above */
      UBYTE   FirstPage;      /* 0 = Not on first page */
      LONG   pad;
```
   } HeadHdr;

/*
 *   PCTS - Begin picture section
 *   Note:  ProWrite currently requires NPlanes to be three (3)
 */

   typedef struct {
```c
      UBYTE   NPlanes;      /* Number of planes used in picture bitmaps */
      UBYTE   pad;
```
   } PictHdr;

/*
 *   PARA - New paragraph format
 *   This chunk should be inserted first when a new section is started
 *      (DOC, HEAD, or FOOT), and again whenever the paragraph format
 *      changes
 */

   #define SPACE_SINGLE   0
   #define SPACE_DOUBLE   0x10

   #define JUSTIFY_LEFT    0
   #define JUSTIFY_CENTER  1
   #define JUSTIFY_RIGHT   2
   #define JUSTIFY_FULL    3

   #define MISCSTYLE_NONE   0
   #define MISCSTYLE_SUPER  1      /* Superscript */
   #define MISCSTYLE_SUB    2      /* Subscript */

   typedef struct {
```c
      UWORD   LeftIndent; /* In decipoints (720 dpi) */
      UWORD   LeftMargin;
      UWORD   RightMargin;
      UBYTE   Spacing;    /* From defines above */
      UBYTE   Justify;    /* From defines above */
      UBYTE   FontNum;    /* FontNum, Style, etc. for first char in para*/
      UBYTE   Style;      /* Standard Amiga style bits */
      UBYTE   MiscStyle;  /* From defines above */
      UBYTE   Color;      /* Internal number, use COLR to translate */
      LONG    pad;
```
   } ParaFormat;

/*
 *   TABS - New tab stop types/locations
 *   Use an array of values in each chunk
 *   Like the PARA chunk, this should be inserted whenever the tab
 *      settings for a paragraph change
 *   Note:  ProWrite currently does not support TAB_CENTER
 */

   #define TAB_LEFT     0
   #define TAB_CENTER   1
   #define TAB_RIGHT    2
   #define TAB_DECIMAL  3

   typedef struct {
```c
      UWORD   Position;      /* In decipoints */
      UBYTE   Type;
      UBYTE   pad;
```
   } TabStop;

/*
 *   PAGE - Page break
 *   Just a marker - this chunk has no data
 */

/*
 *   TEXT - Paragraph text (one block per paragraph)
 *   Block is actual text, no need for separate structure
 *   If the paragraph is empty, this is an empty chunk -- there MUST be
 *   a TEXT block for every paragraph
 *   Note:  The only ctrl characters ProWrite can currently handle in TEXT
 *   chunks are Tab and PAGENUM_CHAR, ie no Return's, etc.
 */

/*
 *   FSCC - Font/Style/Color changes in previous TEXT block
 *   Use an array of values in each chunk
 *   Only include this chunk if the previous TEXT block did not have
 *      the same Font/Style/Color for all its characters
 */

   typedef struct {
```c
      UWORD   Location;  /* Character location in TEXT chunk of change */
      UBYTE   FontNum;
      UBYTE   Style;
      UBYTE   MiscStyle;
      UBYTE   Color;
      UWORD   pad;
```
   } FSCChange;

/*
 *   PINF - Picture info
 *   This chunk must only be in a PCTS section
 *   Must be followed by ILBM BODY chunk
 *   Pictures are treated independently of the document text (like a
 *      page-layout system), this chunk includes information about what
 *      page and location on the page the picture is at
 *   Note:  ProWrite currently only supports mskTransparentColor and
 *      mskHasMask masking
 */

   typedef struct {
```c
      UWORD         Width, Height;   /* In pixels */
      UWORD         Page;         /* Which page picture is on (0..max) */
      UWORD         XPos, YPos;      /* Location on page in decipoints */
      Masking       Masking;      /* Like ILBM format */
      Compression   Compression;   /* Like ILBM format */
      UBYTE         TransparentColor;   /* Like ILBM format */
      UBYTE         pad;
```
   } PictInfo;

/* end */

