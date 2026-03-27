/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-transfer-asm.md
 */

        movem.l d2-d6/a2-a4,-(sp)       ;save regs used

        movea.l 36(sp),a0               ;a0 = PInfo
        move.l  40(sp),d0               ;d0 = y
        movea.l 44(sp),a1               ;a1 = ptr
        movea.l 48(sp),a2               ;a2 = colors
        move.l  52(sp),d1               ;d1 = BufOffset

        move.l  d0,d3                   ;save y
        moveq.l #3,d2
        and.w   d0,d2                   ;d2 = y & 3
        lsl.w   #2,d2                   ;d2 = (y & 3) << 2
        movea.l pi_dmatrix(a0),a3       ;a3 = dmatrix
        adda.l  d2,a3                   ;a3 = dmatrix + ((y & 3) << 2)

        movea.l _PED,a4                 ;a4 = ptr to PED
        cmpi.w  #216,ped_YDotsInch(a4)  ;triple interleaving?
        bne.s   10$                     ;no
        divu.w  #3,d0                   ;y /= 3
        swap.w  d0                      ;d0 = y % 3
        mulu.w  d0,d1                   ;BufOffset *= y % 3
        swap.w  d0                      ;d0 = y / 3
        bra.s   30$
