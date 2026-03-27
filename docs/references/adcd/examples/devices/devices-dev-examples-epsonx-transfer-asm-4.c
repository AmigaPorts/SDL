/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-transfer-asm.md
 */

        movea.l pi_ColorInt(a0),a2      ;a2 = ColorInt ptr
        move.w  pi_width(a0),width      ;# of pixels to do
        move.w  pi_xpos(a0),d2          ;d2 = x
        movea.l pi_ScaleX(a0),a0        ;a0 = ScaleX (sxptr)
        move.b  d6,d7                   ;d7 = bit to set
