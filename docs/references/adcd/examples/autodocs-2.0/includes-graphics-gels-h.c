/* Source: ADCD 2.1
 * Section: includes-graphics-gels-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-graphics-gels-h.md
 */

    struct AnimComp  *NextSeq;
    struct AnimComp  *PrevSeq;

    WORD (*AnimCRoutine)(); /* address of special animation procedure */

    WORD YTrans;     /* initial y translation (if this is a component) */
    WORD XTrans;     /* initial x translation (if this is a component) */

    struct AnimOb    *HeadOb;

    struct Bob	     *AnimBob;
