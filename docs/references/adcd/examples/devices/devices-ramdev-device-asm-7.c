/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    btst.b  #0,IO_DATA+3(a2)    ;check if user's pointer is ODD
    bne.s   IO_LenErr		;bad...
    ;[D0=offset]

    move.l  IO_OFFSET(a2),d0
    move.l  d0,d1
    and.l   #SECTOR-1,d1	;Bad sector boundary or alignment?
    bne.s   IO_LenErr		;bad...
    ;[D0=offset]
