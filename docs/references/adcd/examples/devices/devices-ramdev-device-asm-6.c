/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    ;------ if the quick bit is still set then we don't need to reply
    ;------ msg -- just return to the user.
    btst    #IOB_QUICK,IO_FLAGS(a1)
    bne.s   TermIO_End
    LINKSYS ReplyMsg,md_SysLib(a6)      ;a1-message
    ;(ReplyMsg sets the LN_TYPE to NT_REPLYMSG)
