/* Source: ADCD 2.1
 * Section: text-autodocs-audio-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-audio-doc.md
 */

       ln_Pri      - allocation precedence (-128 thru 127)
       mn_ReplyPort- pointer to message port that receives I/O request after
                     the allocation completes is asynchronous or quick flag
                     (ADIOF_QUICK) is set
       io_Device   - pointer to device node, must be set by (or copied from
                     I/O block set by) OpenDevice function
       io_Command  - command number for ADCMD_ALLOCATE
       io_Flags    - flags, must be cleared if not used:
                     IOF_QUICK   - (CLEAR) reply I/O request
                                   (SET) only reply I/O request only if
                                         asynchronous (see above text)
                     ADIOF_NOWAIT- (CLEAR) if allocation fails, wait till is
                                           succeeds
                                   (SET) if allocation fails, return error
                                         (ADIOERR_ALLOCFAILED)
       ioa_AllocKey- allocation key, zero to generate new key; otherwise,
                     it must be set by (or copied from I/O block set by)
                     OpenDevice function or previous ADCMD_ALLOCATE command
       ioa_Data    - pointer to channel combination options (byte array, bits
                     0 thru 3 correspond to channels 0 thru 3)
       ioa_Length  - length of the channel combination option array
                     (0 thru 16, 0 always succeeds)
