/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    PUTMSG  160,<'%s/TermIO'>
    move.w  IO_COMMAND(a1),d0

    move.w  #IMMEDIATES,d1
    btst    d0,d1
    bne.s   TermIO_Immediate	;IO was immediate, don't do task stuff...

    ;------ we may need to turn the active bit off.
    btst    #UNITB_INTASK,UNIT_FLAGS(a3)
    bne.s   TermIO_Immediate	;IO was came from task, don't clear ACTIVE...

    ;------ the task does not have more work to do
    bclr    #UNITB_ACTIVE,UNIT_FLAGS(a3)
