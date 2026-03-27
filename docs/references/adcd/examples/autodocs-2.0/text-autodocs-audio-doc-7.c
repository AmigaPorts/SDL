/* Source: ADCD 2.1
 * Section: text-autodocs-audio-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-audio-doc.md
 */

       ADCMD_SETPREC is a command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, ADCMD_SETPREC sets the allocation precedence to a new value
       (ln_Pri) and checks if there are allocation requests (ADCMD_ALLOCATE)
       waiting for the channel which now have higher precedence; otherwise,
       ADCMD_SETPREC returns an error (ADIOERR_NOALLOCATION).  ADCMD_SETPREC
       is synchronous and only replies (mn_ReplyPort) if the quick flag
       (IOF_QUICK) is clear.  Do not use ADCMD_SETPREC in interrupt code.
