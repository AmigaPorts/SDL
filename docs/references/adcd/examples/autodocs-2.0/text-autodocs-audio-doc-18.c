/* Source: ADCD 2.1
 * Section: text-autodocs-audio-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-audio-doc.md
 */

       unitNumber- not used
       iORequest - pointer to audio request block (struct IOAudio)
               ln_Pri      - allocation precedence (-128 thru 127), only
                             necessary for allocation (non-zero length)
               mn_ReplyPort- pointer to message port for allocation, only
                             necessary for allocation (non-zero length)
               ioa_AllocKey- allocation key; zero to generate new key.
                             Otherwise, it must be set by (or copied from I/O
                             block that is set by) previous OpenDevice
                             function or ADCMD_ALLOCATE command (non-zero
                             length)
               ioa_Data    - pointer to channel combination options (byte
                             array, bits 0 thru 3 correspond to channels 0
                             thru 3), only necessary for allocation (non-zero
                             length)
               ioa_Length  - length of the channel combination option array
                             (0 thru 16), zero for no allocation
       flags     - not used
