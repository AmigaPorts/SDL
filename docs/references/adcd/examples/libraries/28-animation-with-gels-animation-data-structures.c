/* Source: ADCD 2.1
 * Section: 28-animation-with-gels-animation-data-structures
 * Library: libraries
 * ADCD reference: libraries/28-animation-with-gels-animation-data-structures.md
 */

    struct AnimComp
    {
        WORD Flags;                 /* AnimComp flags for system & user */
        WORD Timer;
        WORD TimeSet;
        struct AnimComp  *NextComp;
        struct AnimComp  *PrevComp;
        struct AnimComp  *NextSeq;
        struct AnimComp  *PrevSeq;
        WORD (*AnimCRoutine)();
        WORD YTrans;
        WORD XTrans;
        struct AnimOb    *HeadOb;
                           /* Pointer back to the controlling AnimOb */
        struct Bob       *AnimBob;
                           /* Underlying Bob structure for this AnimComp */
    };
