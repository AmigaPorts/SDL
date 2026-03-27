/* Source: ADCD 2.1
 * Section: cd-device-cd-attenuate
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-attenuate.md
 */

       This command will ramp the CD audio volume up or down from its
       current value to the value contained in io_Offset.  The range is 0
       (silence) to 0x7FFF (full volume).  If -1 is specified as the target,
       the attenuation will not be modified; the current attenuation value
       will be returned in io_Actual.

       io_Length contains the duration of the fade.  In seconds, this is
       io_Length divided by the current frame rate (usually 75).

       Note that this command returns before the fade has completed.  Thus,
       once started, a fade cannot be aborted.  You can, however, send a
       new CD_ATTENUATE command, which will immediately override any fade
       currently in progress.  An io_Length of zero means attenuate
       immediately.

       If a gradual attenuation command is sent before the play command, the
       fade will begin as soon as the play command is sent.
