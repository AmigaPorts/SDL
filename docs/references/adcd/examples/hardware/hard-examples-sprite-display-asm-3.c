/* Source: ADCD 2.1
 * Section: hard-examples-sprite-display-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-sprite-display-asm.md
 */

        MOVE.W  #$0008,COLOR00(a0)      ;Background color = dark blue
        MOVE.W  #$0000,COLOR01(a0)      ;Foreground color = black
        MOVE.W  #$0FF0,COLOR17(a0)      ;Color 17 = yellow
        MOVE.W  #$00FF,COLOR18(a0)      ;Color 18 = cyan
        MOVE.W  #$0F0F,COLOR19(a0)      ;Color 19 = magenta
