/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-transfer-asm.md
 */

        movem.l d7/a5-a6,-(sp)          ;save regs used

        movea.l a1,a4
        movea.l a1,a5
        movea.l a1,a6
        adda.w  (a2)+,a1                ;a1 = ptr + colors[0] (bptr)
        adda.w  (a2)+,a4                ;a4 = ptr + colors[1] (yptr)
        adda.w  (a2)+,a5                ;a5 = ptr + colors[2] (mptr)
        adda.w  (a2)+,a6                ;a6 = ptr + colors[3] (cptr)
