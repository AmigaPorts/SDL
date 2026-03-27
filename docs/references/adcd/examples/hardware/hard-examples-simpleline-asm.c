/* Source: ADCD 2.1
 * Section: hard-examples-simpleline-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-simpleline-asm.md
 */

        neg.w   d3              ; calculate abs(dy)
        cmp.w   d3,d2           ; cmp |dx|,|dy|, octant is [7,8]
        bmi     ynygtx          ; if y>x, octant is 7
        moveq.l #OCTANT8+LINEMODE,d5    ; otherwise octant is 8
        bra     lineagain
