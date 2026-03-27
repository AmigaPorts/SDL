/* Source: ADCD 2.1
 * Section: hard-examples-hires-playfield-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-hires-playfield-asm.md
 */

        MOVE.W  #20,d0          ; Reset long word counter
        ADDQ.L  #4,a2           ; Point at next word in char list
        CMPI.L  #$FFFFFFFF,(a2) ; End of char list?
        BNE     L2
        LEA     CHARLIST(pc),a2 ; Yes, reset a2 to beginning of list
