/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-transfer-asm.md
 */

        eori.b  #15,d3                  ;d3 = dvalue
        movea.l pi_ColorInt(a0),a2      ;a2 = ColorInt ptr
        move.w  pi_xpos(a0),d2          ;d2 = x
        movea.l pi_ScaleX(a0),a0        ;a0 = ScaleX (sxptr)
        adda.w  d2,a1                   ;ptr += x
