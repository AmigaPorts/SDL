/* Source: ADCD 2.1
 * Section: audio-device-adcmd-finish
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/audio-device-adcmd-finish.md
 */

    ADCMD_FINISH is a command for multiple audio channels.  For each
    selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
    correct and there is a write (CMD_WRITE)in progress, ADCMD_FINISH
    aborts the current write immediately or at the end of the current
    cycle depending on the sync flag (ADIOF_SYNCCYCLE).  If the allocation
    key is incorrect ADCMD_FINISH returns an error (ADIOERR_NOALLOCATION).
    ADCMD_FINISH is synchronous and only replies (mn_ReplyPort) if the
    quick flag (IOF_QUICK) is clear.  Do not use ADCMD_FINISH in interrupt
    code at interrupt level 5 or higher.
