/* Source: ADCD 2.1
 * Section: hard-examples-clearmem-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-clearmem-asm.md
 */

        moveq   #$3f,d1         ; Mask out mod 64 words
        and.w   d0,d1
        beq     dorest          ; none?  good, do one blit
        sub.l   d1,d0           ; otherwise remove remainder
        or.l    #$40,d1         ; set the height to 1, width to n
        move.w  d1,BLTSIZE(a1)  ; trigger the blit
