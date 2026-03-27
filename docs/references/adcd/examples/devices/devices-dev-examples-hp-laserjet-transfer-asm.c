/* Source: ADCD 2.1
 * Section: devices-dev-examples-hp-laserjet-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-hp-laserjet-transfer-asm.md
 */

        movem.l d2-d6/a2-a3,-(sp)       ;save regs used

        movea.l 32(sp),a0               ;a0 = PInfo
        move.l  36(sp),d0               ;d0 = y
        movea.l 40(sp),a1               ;a1 = ptr

        move.w  pi_width(a0),d1         ;d1 = width
        subq.w  #1,d1                   ;adjust for dbra

        move.w  pi_threshold(a0),d3     ;d3 = threshold, thresholding?
        beq.s   grey_scale              ;no, grey-scale
