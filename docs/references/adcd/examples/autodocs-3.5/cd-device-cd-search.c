/* Source: ADCD 2.1
 * Section: cd-device-cd-search
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-search.md
 */

       This command causes a play command to play in fast-forward,
       fast-reverse, or normal play mode.  These modes are defined as:

       CDMODE_NORMAL   0   Normal play (current speed setting)
       CDMODE_FFWD     1   Play in fast forward mode
       CDMODE_FREV     2   Play in fast reverse mode

       The search mode can be set before the play command is sent, or during
       a play.  If CD_SEARCH is sent before a play command is sent, the
       mode is set and the command immediately returns.  If the mode is set
       to REV mode, when the play command is sent the play will begin at the
       requested end position and work backwards to the start position.

       If CD_SEARCH is sent during a play, the play will automatically
       switch to the desired mode and continue playing until the original
       play command is completed.  If REV mode is set and the beginning of
       the play is encountered before switching back to forward play, the
       play command will terminate with no error.
