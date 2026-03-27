/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    bset    #UNITB_INTASK,UNIT_FLAGS(a3)
    bclr    #IOB_QUICK,IO_FLAGS(a1)   ;We did NOT complete this quickly
    ENABLE  a0


    IFGE INFO_LEVEL-250
     move.l  a1,-(sp)
     move.l  a3,-(sp)
     PUTMSG  250,<'%s/PutMsg: Port=%lx Message=%lx'>
     addq.l  #8,sp
    ENDC

    move.l  a3,a0
    LINKSYS  PutMsg,md_SysLib(a6)   ;Port=a0, Message=a1
    bra.s   BeginIO_End
    ;----- return to caller before completing


    ;------ Do it on the schedule of the calling process
    ;------
