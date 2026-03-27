/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    IFD   INTRRUPT
     move.l   mdu_SigMask(a3),d0  ; Get signals to wait for
     LINKSYS  Wait,md_SysLib(a6)  ; Wait for interrupt before proceeding
    ENDC


    lea.l   mdu_RAM(a3),a0      ; Point to RAMDISK "sector" for I/O
    add.l   IO_OFFSET(a2),a0    ; Add offset to ram base
    move.l  IO_LENGTH(a2),d0
    move.l  d0,IO_ACTUAL(a2)    ; Indicate we've moved all bytes
    beq.s   RdWrt_end		;---deal with zero length I/O
    move.l  IO_DATA(a2),a1      ; Point to data buffer
