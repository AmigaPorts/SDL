/* Source: ADCD 2.1
 * Section: include-graphics-gels-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-graphics-gels-h.md
 */

    /* NOTE: This table actually consists of two different types of
     *       pointers. The first table entry is for collision testing,
     *       the other are for reporting collisions. The first function
     *       pointer looks like this:
     *
     *          LONG (*collPtrs[0])(struct VSprite *,WORD);
     *
     *       The remaining 15 function pointers look like this:
     *
     *          VOID (*collPtrs[1..15])(struct VSprite *,struct VSPrite *);
     */
    LONG (*collPtrs[16]) __CLIB_PROTOTYPE((struct VSprite *,struct VSPrite *));
