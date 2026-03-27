/* Source: ADCD 2.1
 * Section: word-doc-chunks
 * Library: devices
 * ADCD reference: devices/word-doc-chunks.md
 */

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
