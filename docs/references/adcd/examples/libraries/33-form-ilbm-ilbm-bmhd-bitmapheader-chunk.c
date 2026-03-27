/* Source: ADCD 2.1
 * Section: 33-form-ilbm-ilbm-bmhd-bitmapheader-chunk
 * Library: libraries
 * ADCD reference: libraries/33-form-ilbm-ilbm-bmhd-bitmapheader-chunk.md
 */

    UWORD w, h;                 /* raster width & height in pixels      */
    WORD  x, y;                 /* pixel position for this image        */
    UBYTE nPlanes;              /* # bitplanes (without mask, if any)   */
    Masking     masking;        /* One of the values above.  Usually 0  */
    Compression compression;    /* One of the values above.  Usually 1  */
    UBYTE reserved1;            /* reserved; ignore on read, write as 0 */
    UWORD transparentColor;     /* transparent color number. Usually 0  */
    UBYTE xAspect, yAspect;     /* pixel aspect, a ratio width : height */
    WORD  pageWidth, pageHeight;    /* source "page" size in pixels */
