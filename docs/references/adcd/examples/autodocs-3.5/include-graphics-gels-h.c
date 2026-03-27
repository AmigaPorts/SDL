/* Source: ADCD 2.1
 * Section: include-graphics-gels-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-graphics-gels-h.md
 */

    WORD (*AnimCRoutine) __CLIB_PROTOTYPE((struct AnimComp *));

    WORD YTrans;     /* initial y translation (if this is a component) */
    WORD XTrans;     /* initial x translation (if this is a component) */

    struct AnimOb    *HeadOb;

    struct Bob	     *AnimBob;
