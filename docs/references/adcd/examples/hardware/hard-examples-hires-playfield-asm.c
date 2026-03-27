/* Source: ADCD 2.1
 * Section: hard-examples-hires-playfield-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-hires-playfield-asm.md
 */

        LEA     CUSTOM,a0               ; Address of custom chips
        MOVE.W  #$9204,BPLCON0(a0)      ; Hires, one bitplane, interlaced
        MOVE.W  #0,BPLCON1(a0)          ; Horizontal scroll value = 0
        MOVE.W  #80,BPL1MOD(a0)         ; Modulo = 80 for odd bitplanes
        MOVE.W  #80,BPL2MOD(a0)         ; Ditto for even bitplanes
        MOVE.W  #$003C,DDFSTRT(a0)      ; Set data-fetch start for Hires
        MOVE.W  #$00D4,DDFSTOP(a0)      ; Set data-fetch stop
        MOVE.W  #$2C81,DIWSTRT(a0)      ; Set display window start
        MOVE.W  #$F4C1,DIWSTOP(a0)      ; Set display window stop
