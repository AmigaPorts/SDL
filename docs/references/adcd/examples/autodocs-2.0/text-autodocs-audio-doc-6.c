/* Source: ADCD 2.1
 * Section: text-autodocs-audio-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-audio-doc.md
 */

       ADCMD_PERVOL is a command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct and there is a write (CMD_WRITE) in progress, ADCMD_PERVOL
       loads a new volume and period immediately or at the end of the current
       cycle depending on the sync flag (ADIOF_SYNCCYCLE).  If the allocation
       key in incorrect, ADCMD_PERVOL returns an error
       (ADIOERR_NOALLOCATION).  ADCMD_PERVOL is synchronous and only replies
       (mn_ReplyPort) if the quick flag (IOF_QUICK) is clear.  Do not use
       ADCMD_PERVOL in interrupt code at interrupt level 5 or higher.
