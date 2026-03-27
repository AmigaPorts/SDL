/* Source: ADCD 2.1
 * Section: 29-graphics-library-and-text-does-the-text-fit
 * Library: libraries
 * ADCD reference: libraries/29-graphics-library-and-text-does-the-text-fit.md
 */

    WORD TextLength( struct RastPort *my_rp, STRPTR mystring,
                     ULONG mycount );

    void TextExtent( struct RastPort *my_rp, STRPTR mystring, LONG mycount,
                     struct TextExtent *textExtent );

    void FontExtent( struct TextFont *font,
                     struct TextExtent *fontExtent );

    ULONG TextFit  ( struct RastPort *rp, STRPTR mystring, ULONG strLen,
                     struct TextExtent *textExtent,
                     struct TextExtent *constrainingExtent,
                     LONG strDirection, ULONG constrainingBitWidth,
                     ULONG constrainingBitHeight );
