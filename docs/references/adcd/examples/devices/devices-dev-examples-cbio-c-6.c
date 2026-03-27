/* Source: ADCD 2.1
 * Section: devices-dev-examples-cbio-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-cbio-c.md
 */

        movem.l a2/a6,-(sp)     ; protect
        move.l  12(sp),a0       ; hook
        move.l  16(sp),a2       ; object
        move.l  20(sp),a1       ; message
        ; ------ now have registers ready, invoke function
        pea.l   hreturn(pc)
        move.l  h_Entry(a0),-(sp)       ; old rts-jump trick
        rts
