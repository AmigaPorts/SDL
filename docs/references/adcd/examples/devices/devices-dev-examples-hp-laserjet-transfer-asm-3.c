/* Source: ADCD 2.1
 * Section: devices-dev-examples-hp-laserjet-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-hp-laserjet-transfer-asm.md
 */

        movea.l pi_ColorInt(a0),a2      ;a2 = ColorInt ptr
        moveq.l #3,d2
        and.w   d0,d2                   ;d2 = y & 3
        lsl.w   #2,d2                   ;d2 = (y & 3) << 2
        movea.l pi_dmatrix(a0),a3       ;a3 = dmatrix
        adda.l  d2,a3                   ;a3 = dmatrix + ((y & 3) << 2)
        move.w  pi_xpos(a0),d2          ;d2 = x
        movea.l pi_ScaleX(a0),a0        ;a0 = ScaleX (sxptr)
