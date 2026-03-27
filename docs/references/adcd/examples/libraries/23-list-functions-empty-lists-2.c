/* Source: ADCD 2.1
 * Section: 23-list-functions-empty-lists
 * Library: libraries
 * ADCD reference: libraries/23-list-functions-empty-lists.md
 */

    ; Use this method...
    CMP.L   LH_TAILPRED(A0),A0
    BEQ     list_is_empty

    ; Or use this method
    MOVE.L  LH_HEAD(A0),A1
    TST.L   LN_SUCC(A1)
    BEQ     list_is_empty
