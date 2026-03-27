/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    ;[D0=offset]
    add.l   IO_LENGTH(a2),d0    ;Add length to offset
    bcs.s   IO_LenErr		;overflow... (important test)
    cmp.l   #RAMSIZE,d0 	;Last byte is highest acceptable total
    bhi.s   IO_LenErr		;bad... (unsigned compare)
    and.l   #SECTOR-1,d0	;Even sector boundary?
    bne.s   IO_LenErr		;bad...
