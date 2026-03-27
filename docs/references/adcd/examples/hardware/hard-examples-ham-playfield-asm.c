/* Source: ADCD 2.1
 * Section: hard-examples-ham-playfield-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-ham-playfield-asm.md
 */

        LEA     CUSTOM,a0               ; Point a0 at custom chips
        MOVE.W  #$6A00,BPLCON0(a0)      ; Six bitplanes, hold-and-modify mode
        MOVE.W  #0,BPLCON1(a0)          ; Horizontal scroll = 0
        MOVE.W  #0,BPL1MOD(a0)          ; Modulo for odd bitplanes = 0
        MOVE.W  #0,BPL2MOD(a0)          ; Ditto for even bitplanes
        MOVE.W  #$0038,DDFSTRT(a0)      ; Set data-fetch start
        MOVE.W  #$00D0,DDFSTOP(a0)      ; Set data-fetch stop
        MOVE.W  #$2C81,DIWSTRT(a0)      ; Set display window start
        MOVE.W  #$F4C1,DIWSTOP(a0)      ; Set display window stop
