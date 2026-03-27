/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    PUTMSG  35,<'%s/Task_Begin'>
    move.l  ABSEXECBASE,a6

    ;------ Grab the argument passed down from our parent
    move.l  4(sp),a3           ; Unit pointer
    move.l  mdu_Device(a3),a5  ; Point to device structure

    IFD   INTRRUPT
     ;------ Allocate a signal for "I/O Complete" interrupts
     moveq   #-1,d0	    ; -1 is any signal at all
     CALLSYS   AllocSignal
     move.b   d0,mdu_SigBit(A3)   ; Save in unit structure
     moveq   #0,d7	   ; Convert bit number signal mask
     bset   d0,d7
     move.l   d7,mdu_SigMask(A3)   ; Save in unit structure
     lea.l   mdu_is(a3),a1      ; Point to interrupt structure
     moveq   #INTB_PORTS,d0	; Portia interrupt bit 3
     CALLSYS AddIntServer	; Now install the server
     move.l   md_Base(a5),a0      ; Get board base address
