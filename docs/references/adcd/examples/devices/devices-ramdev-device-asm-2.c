/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    ENDC
    IFGE INFO_LEVEL-3
     clr.l    -(sp)
     move.w   IO_COMMAND(a1),2(sp)  ;Get entire word
     PUTMSG   3,<'%s/BeginIO  -- $%lx'>
     addq.l   #4,sp
    ENDC

    movem.l   d1/a0/a3,-(sp)

    move.b  #NT_MESSAGE,LN_TYPE(a1) ;So WaitIO() is guaranteed to work
    move.l  IO_UNIT(a1),a3          ;bookkeeping -> what unit to play with
    move.w  IO_COMMAND(a1),d0

    ;Do a range check & make sure ETD_XXX type requests are rejected
    cmp.w   #MYDEV_END,d0	;Compare all 16 bits
    bcc     BeginIO_NoCmd	;no, reject it.  (bcc=bhs - unsigned)

    ;------ process all immediate commands no matter what
    move.l  #IMMEDIATES,d1
    DISABLE a0			;<-- Ick, nasty stuff, but needed here.
    btst.l  d0,d1
    bne     BeginIO_Immediate

    IFD   INTRRUPT   ; if using interrupts,
     ;------ queue all NEVERIMMED commands no matter what
     move.w  #NEVERIMMED,d1
     btst    d0,d1
     bne.s   BeginIO_QueueMsg
    ENDC


    ;------ see if the unit is STOPPED.  If so, queue the msg.
    btst    #MDUB_STOPPED,UNIT_FLAGS(a3)
    bne     BeginIO_QueueMsg


    ;------ This is not an immediate command.  See if the device is
    ;------ busy.  If the device is not, do the command on the
    ;------ user schedule.  Else fire up the task.
    ;------ This type of arbitration is not really needed for a ram
    ;------ disk, but is essential for a device to reliably work
    ;------ with shared hardware
    ;------
    ;------ When the lines below are ";" commented out, the task gets
    ;------ a better workout.  When the lines are active, the calling
    ;------ process is usually used for the operation.
    ;------
    ;------ REMEMBER:::: Never Wait() on the user's schedule in BeginIO()!
    ;------ The only exception is when the user has indicated it is ok
    ;------ by setting the "quick" bit.  Since this device copies from
    ;------ ram that never needs to be waited for, this subtlely may not
    ;------ be clear.
    ;------
    bset    #UNITB_ACTIVE,UNIT_FLAGS(a3)   ;<---- comment out these
    beq.s   BeginIO_Immediate		   ;<---- lines to test task.


    ;------ we need to queue the device.  mark us as needing
    ;------ task attention.  Clear the quick flag
