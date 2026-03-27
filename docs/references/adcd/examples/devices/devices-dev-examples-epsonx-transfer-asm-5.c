/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-transfer-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-transfer-asm.md
 */

        move.b  PCMBLACK(a2),d1         ;d1 = Black
        move.b  PCMYELLOW(a2),d4        ;d4 = Yellow
        move.b  PCMMAGENTA(a2),d5       ;d5 = Magenta
        move.b  PCMCYAN(a2),d6          ;d6 = Cyan
        addq.l  #ce_SIZEOF,a2           ;advance to next entry

        move.w  (a0)+,sx                ;# of times to use this pixel
