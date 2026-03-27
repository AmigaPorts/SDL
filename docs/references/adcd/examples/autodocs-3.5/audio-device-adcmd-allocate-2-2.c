/* Source: ADCD 2.1
 * Section: audio-device-adcmd-allocate-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/audio-device-adcmd-allocate-2.md
 */

       ln_Pri      - allocation precedence (-128 thru 127)
       mn_ReplyPort- pointer to message port that receives I/O request after
                     the allocation completes is asynchronous or quick flag
                     (ADIOF_QUICK) is set
       io_Device   - pointer to device node, must be set by (or copied from
                     I/O block set by) [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html) function
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
                     [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html) function or previous ADCMD_ALLOCATE command
       ioa_Data    - pointer to channel combination options (byte array, bits
                     0 thru 3 correspond to channels 0 thru 3)
       ioa_Length  - length of the channel combination option array
                     (0 thru 16, 0 always succeeds)
