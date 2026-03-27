/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-transfer-asm.md
 */

        not.b   d6                      ;d6 = bit to set
        adda.l  d1,a1                   ;ptr += BufOffset

        movea.l _PD,a4                  ;a4 = ptr to PD
        cmpi.w  #SHADE_COLOR,pd_Preferences+pf_PrintShade(a4)   ;color dump?
        bne     not_color               ;no
