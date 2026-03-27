/* Source: ADCD 2.1
 * Section: hard-examples-lores-playfield-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-lores-playfield-asm.md
 */

        LEA     CUSTOM,a0               ; a0 points at custom chips
        MOVE.W  #$1200,BPLCON0(a0)      ; One bitplane, enable composite color
        MOVE.W  #0,BPLCON1(a0)          ; Set horizontal scroll value to 0
        MOVE.W  #0,BPL1MOD(a0)          ; Set modulo to 0 for all odd bitplanes
        MOVE.W  #$0038,DDFSTRT(a0)      ; Set data-fetch start to $38
        MOVE.W  #$00D0,DDFSTOP(a0)      ; Set data-fetch stop to $D0
        MOVE.W  #$2C81,DIWSTRT(a0)      ; Set DIWSTRT to $2C81
        MOVE.W  #$F4C1,DIWSTOP(a0)      ; Set DIWSTOP to $F4C1
        MOVE.W  #$0F00,COLOR00(a0)      ; Set background color to red
        MOVE.W  #$0FF0,COLOR01(a0)      ; Set color register 1 to yellow
