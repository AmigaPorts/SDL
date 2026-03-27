/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    move.l  a1,-(sp)
    ;------ turn processing back on
    bclr   #MDUB_STOPPED,UNIT_FLAGS(a3)
    ;------ kick the task to start it moving
    move.b  MP_SIGBIT(a3),d1
    CLEAR   d0
    bset    d1,d0		    ;prepared signal mask
    move.l  MP_SIGTASK(a3),a1       ;:FIXED:marco-task to signal
    LINKSYS Signal,md_SysLib(a6)    ;:FIXED:marco-a6 not a3
    move.l  (sp)+,a1
    rts
