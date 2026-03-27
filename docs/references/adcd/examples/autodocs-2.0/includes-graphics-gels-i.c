/* Source: ADCD 2.1
 * Section: includes-graphics-gels-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-graphics-gels-i.md
 */

    APTR    ac_NextSeq        ; struct *animComp
    APTR    ac_PrevSeq        ; struct *animComp
    APTR    ac_AnimCRoutine   ; address of special animation procedure
    WORD    ac_YTrans         ; initial y translation (if this is a component)
    WORD    ac_XTrans         ; initial x translation (if this is a component)
    APTR    ac_HeadOb         ; struct *animOb
    APTR    ac_AnimBob        ; struct *bob
    LABEL   ac_SIZE
