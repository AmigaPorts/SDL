/* Source: ADCD 2.1
 * Section: hard-examples-hires-playfield-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-hires-playfield-asm.md
 */

        AND.W   #$0020,d0               ; Mask off all but vertical blank
        BEQ     VLOOP                   ; Loop until vertical blank comes
        MOVE.W  #$0020,INTREQ(a0)       ; Reset vertical interrupt
        MOVE.W  VPOSR(a0),d0            ; Read LOF bit into d0 bit 15
        BPL     VL1                     ; If LOF = 0, jump
        MOVE.L  #$20000,BPL1PTH(a0)     ; LOF = 1, point to $20000
        BRA     VLOOP                   ; Back to top
