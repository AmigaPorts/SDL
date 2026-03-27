/* Source: ADCD 2.1
 * Section: hard-examples-rotatebits-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-rotatebits-asm.md
 */

        lea     _custom,a2      ; We need to access the custom registers
        tst     d0              ; if no words, just return
        beq     gone
        lea     DMACONR(a2),a3  ; get the address of dmaconr
        moveq.l #DMAB_BLTDONE-8,d2      ; get the bit number BLTDONE
        btst    d2,(a3)         ; check to see if we're done
