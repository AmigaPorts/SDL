/* Source: ADCD 2.1
 * Section: hard-examples-8520-timing-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-8520-timing-asm.md
 */

        move.b  ciacra(a4),d0           ;Set control register A on CIAA
        and.b   #%11000000,d0           ;Don't trash bits we are not
        or.b    #%00001000,d0           ;using...
        move.b  d0,ciacra(a4)
        move.b  #%01111111,ciaicr(a4)   ;Clear all 8520 interrupts
