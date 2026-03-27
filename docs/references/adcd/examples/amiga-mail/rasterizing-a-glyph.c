/* Source: ADCD 2.1
 * Section: rasterizing-a-glyph
 * Library: amiga-mail
 * ADCD reference: amiga-mail/rasterizing-a-glyph.md
 */

    UWORD  glm_BMModulo;    /* # of bytes in row: always multiple of 4 */
    UWORD  glm_BMRows;      /* # of rows in bitmap */
    UWORD  glm_BlackLeft;   /* # of blank pixel columns at left of */
                            /* glyph */
    UWORD  glm_BlackTop;    /* # of blank rows at top of glyph */
    UWORD  glm_BlackWidth;  /* span of non-blank columns (horizontal */
                            /* span of the glyph) */
    UWORD  glm_BlackHeight; /* span of non-blank rows (vertical span of */
                            /* the glyph) */
    FIXED  glm_XOrigin;     /* distance from upper left corner of */
                            /* bitmap to lower */
    FIXED  glm_YOrigin;     /* left of glyph (baseline), in fractional */
                            /* pixels */
    WORD   glm_X0;          /* approximation of XOrigin in whole pixels */
    WORD   glm_Y0;          /* approximation of YOrigin in whole pixels */
    WORD   glm_X1;          /* approximation of XOrigin + Width */
    WORD   glm_Y1;          /* approximation of YOrigin + Width */
    FIXED  glm_Width;       /* character advance, as fraction of em */
                            /* width */
    UBYTE *glm_BitMap;      /* actual glyph bitmap */
