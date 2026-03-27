/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    PUTMSG   75,<'%s/++Wakeup'>
    ;------ see if we are stopped
    btst    #MDUB_STOPPED,UNIT_FLAGS(a3)
    bne.s   Task_MainLoop	; device is stopped, ignore messages
    ;------ lock the device
    bset    #UNITB_ACTIVE,UNIT_FLAGS(a3)
    bne     Task_MainLoop	; device in use (immediate command?)
