/* Source: ADCD 2.1
 * Section: hard-examples-clearmem-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-clearmem-asm.md
 */

        move.w  #$ffc0,d1       ; look at some more upper bits
        and.w   d0,d1           ; extract 10 more bits
        beq     dorest2         ; any to do?
        sub.l   d1,d0           ; pull of the ones we're doing here
        bsr     waitblit        ; wait for prev blit to complete
        move.w  [d0](#footnote1),BLTSIZE(a1)  ; do another blit
