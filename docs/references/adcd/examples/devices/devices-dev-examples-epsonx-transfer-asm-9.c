/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-transfer-asm.md
 */

        move.b  PCMBLACK(a2),d4         ;d4 = Black
        addq.l  #ce_SIZEOF,a2           ;advance to next entry

        move.w  (a0)+,d5                ;d5 = # of times to use this pixel

        cmp.b   d3,d4                   ;render this pixel?
        ble.s   tsx_end                 ;no, skip to next pixel.
        subq.w  #1,d5                   ;adjust for dbra
