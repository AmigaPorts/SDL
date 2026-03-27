/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-transfer-asm.md
 */

        addq.w  #1,d2                   ;x++
        subq.w  #1,sx                   ;sx--
        bne.s   csx_loop
        subq.w  #1,width                ;width--
        bne.s   cwidth_loop

        movem.l (sp)+,d7/a5-a6          ;restore regs used
        bra     exit
