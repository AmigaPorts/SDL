/* Source: ADCD 2.1
 * Section: hard-examples-sprite-display-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-sprite-display-asm.md
 */

        MOVE.W  #$2C81,DIWSTRT(a0)      ;Set display window start
                                        ;Vertical start in high byte.
                                        ;Horizontal start * 2 in low byte.
        MOVE.W  #$F4C1,DIWSTOP(a0)      ;Set display window stop
                                        ;Vertical stop in high byte.
                                        ;Horizontal stop * 2 in low byte.
