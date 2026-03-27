/* Source: ADCD 2.1
 * Section: 23-list-functions-scanning-a-list
 * Library: libraries
 * ADCD reference: libraries/23-list-functions-scanning-a-list.md
 */

            MOVE.L  (A1),D1         ; first node
    scan:   MOVE.L  D1,A1
            MOVE.L  (A1),D1         ; lookahead to next
            BEQ.S   not_found       ; end of list...
            TST.B   LN_PRI(A1)
            BNE.S   scan
            ...                     ; found one

    not_found:

     [Exec List Example](../Libraries_Manual_guide/node058B.html) 
