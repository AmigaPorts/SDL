/* Source: ADCD 2.1
 * Section: hard-examples-8520-timing-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-8520-timing-asm.md
 */

        btst.b  #0,ciaicr(a4)           ;Wait for timer expired flag
        beq.s   busy_wait
        bchg.b  #CIAB_LED,ciapra(a4)    ;Blink light
        bset.b  #0,ciacra(a4)           ;Restart timer
        bra.s   busy_wait

        END
