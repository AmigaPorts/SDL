# cd.device/CD_PLAYMSF



   NAME

```c
        CD_PLAYMSF -- Play a selected portion of CD audio (MSF form).
```
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_PLAYMSF
       io_Data         NULL
       io_Length       length of play
       io_Offset       starting position
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
```
   FUNCTION

```c
       This command causes the drive to start playing CD audio from the
       specified position until the specified length has passed.

       io_Offset specifies the starting position.  io_Length contains
       the amount of time to play.  All data is specified in MSF format.

       A [DoIO()](../Includes_and_Autodocs_3._guide/node0204.html) will not return until the requested number of sectors
       have been played.  A [SendIO()](../Includes_and_Autodocs_3._guide/node0236.html) will return as soon as the PLAY
       has been started.  At this time other commands can be sent (like
       CD_PAUSE).  To stop a play before the specified length has been
       reached, use [AbortIO()](../Includes_and_Autodocs_3._guide/node0574.html).
```
   EXAMPLE

```c
       /* Play two minutes, ten seconds of audio starting at 20 minutes, */
       /* 58 seconds, and 10 frames.                                     */

       ior->io_Command = CD_PLAYMSF;   /* Play CD audio          */
       ior->io_Offset  = 0x00143A0A;   /* $14=20, $3A=58, $0A=10 */
       ior->io_Length  = 0x00020A00;   /* $02=02, $0A=10, $00=00 */
       [DoIO](../Includes_and_Autodocs_3._guide/node0204.html) (ior);
```
   NOTES

   BUGS

   SEE ALSO

```c
       [CD_PLAYTRACK](../Includes_and_Autodocs_3._guide/node00AE.html), [CD_PAUSE](../Includes_and_Autodocs_3._guide/node00AB.html), [CD_SEARCH](../Includes_and_Autodocs_3._guide/node00B6.html), [CD_ATTENUATE](../Includes_and_Autodocs_3._guide/node00A3.html)
```
