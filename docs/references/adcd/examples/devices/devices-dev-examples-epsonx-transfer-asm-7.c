/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-transfer-asm.md
 */

        adda.w  (a2),a1                 ;a1 = ptr + colors[0]
        move.w  pi_width(a0),d1         ;d1 = width
        subq.w  #1,d1                   ;adjust for dbra

        move.w  pi_threshold(a0),d3     ;d3 = threshold, thresholding?
        beq.s   grey_scale              ;no, grey-scaling
