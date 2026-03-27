/* Source: ADCD 2.1
 * Section: cd-device-cd-playlsn
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-playlsn.md
 */

       This command causes the drive to start playing CD audio from the
       specified position until the specified length has passed.

       io_Offset specifies the starting position.  io_Length contains
       the amount of time to play.  All data is specified in LSN format.

       A [DoIO()](../Includes_and_Autodocs_3._guide/node0204.html) will not return until the requested number of sectors
       have been played.  A [SendIO()](../Includes_and_Autodocs_3._guide/node0236.html) will return as soon as the PLAY
       has been started.  At this time other commands can be sent (like
       CD_PAUSE).  To stop a play before the specified length has been
       reached, use [AbortIO()](../Includes_and_Autodocs_3._guide/node0574.html).
