/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    IFGE INFO_LEVEL-150
     clr.l    -(sp)
     move.w   IO_COMMAND(a1),2(sp)  ;Get entire word
     PUTMSG   150,<'%s/PerformIO -- $%lx'>
     addq.l   #4,sp
    ENDC

    moveq   #0,d0
    move.b  d0,IO_ERROR(A1)     ; No error so far
    move.b  IO_COMMAND+1(a1),d0 ;Look only at low byte
    lsl.w   #2,d0		; Multiply by 4 to get table offset
    lea.l   cmdtable(pc),a0
    move.l  0(a0,d0.w),a0

    jmp     (a0)    ;iob:a1  unit:a3  devprt:a6
