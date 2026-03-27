/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    ENDC

    ;------ Allocate a signal
    moveq   #-1,d0	    ; -1 is any signal at all
    CALLSYS AllocSignal
    move.b  d0,MP_SIGBIT(a3)
    move.b  #PA_SIGNAL,MP_FLAGS(a3) ;Make message port "live"
    ;------ change the bit number into a mask, and save in d7
    moveq   #0,d7	;Clear D7
    bset    d0,d7

    IFGE INFO_LEVEL-40
     move.l  $114(a6),-(sp)
     move.l  a5,-(sp)
     move.l  a3,-(sp)
     move.l  d0,-(sp)
     PUTMSG  40,<'%s/Signal=%ld, Unit=%lx Device=%lx Task=%lx'>
     add.l   #4*4,sp
    ENDC

    bra.s   Task_StartHere
