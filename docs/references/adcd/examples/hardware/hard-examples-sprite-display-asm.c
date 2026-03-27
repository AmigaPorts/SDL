/* Source: ADCD 2.1
 * Section: hard-examples-sprite-display-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-sprite-display-asm.md
 */

        LEA     CUSTOM,a0               ;Point a0 at custom chips
        MOVE.W  #$1200,BPLCON0(a0)      ;1 bitplane color is on
        MOVE.W  #$0000,BPL1MOD(a0)      ;Modulo = 0
        MOVE.W  #$0000,BPLCON1(a0)      ;Horizontal scroll value = 0
        MOVE.W  #$0024,BPLCON2(a0)      ;Sprites have priority over playfields
        MOVE.W  #$0038,DDFSTRT(a0)      ;Set data-fetch start
        MOVE.W  #$00D0,DDFSTOP(a0)      ;Set data-fetch stop
