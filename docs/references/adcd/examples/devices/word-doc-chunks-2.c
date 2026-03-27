/* Source: ADCD 2.1
 * Section: word-doc-chunks
 * Library: devices
 * ADCD reference: devices/word-doc-chunks.md
 */

      UWORD         Width, Height;   /* In pixels */
      UWORD         Page;         /* Which page picture is on (0..max) */
      UWORD         XPos, YPos;      /* Location on page in decipoints */
      Masking       Masking;      /* Like ILBM format */
      Compression   Compression;   /* Like ILBM format */
      UBYTE         TransparentColor;   /* Like ILBM format */
      UBYTE         pad;
