/* Source: ADCD 2.1
 * Section: text-autodocs-audio-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-audio-doc.md
 */

       CMD_START is a standard command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct and the channel was previously stopped (CMD_STOP), CMP_START
       immediately starts all writes (CMD_WRITE) to the channel.  If the
       allocation key is incorrect, CMD_START returns an error
       (ADIOERR_NOALLOCATION).  CMD_START starts multiple channels
       simultaneously to minimize distortion if the channels are playing the
       same waveform and their outputs are mixed. CMD_START is synchronous an
