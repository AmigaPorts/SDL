# cd.device/CD_PLAYTRACK



   NAME

       CD_PLAYTRACK -- Play one or more tracks of CD audio.
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_PLAYTRACK
       io_Data         NULL
       io_Length       number of tracks to play
       io_Offset       start playing at beginning of this track
```
   RESULTS
```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
```
   FUNCTION

```c
       This command causes the drive to play the specified audio track(s).
       The command will return when the audio has completed.

       io_Offset specifies the track number (starting from 1).

       io_Length specifies the number of tracks to play (0 is invalid).
```
   EXAMPLE


```c
       ior->io_Command = CD_PLAYTRACK;    /* Play audio tracks     */
       ior->io_Offset  = STARTTRACK;      /* Start with this track */
       ior->io_Length  = 3;               /* Play three tracks     */
       DoIO(ior);
```
   NOTES


       PLAY commands are asynchronous with many other CD commands.
       Using a separate I/O request, other commands can be sent to the device
       that can change the behavior of the PLAY command.
   BUGS

   SEE ALSO

```c
       [CD_PLAYMSF](../Includes_and_Autodocs_3._guide/node00AD.html), [CD_PLAYLSN](../Includes_and_Autodocs_3._guide/node00AC.html), [CD_PAUSE](../Includes_and_Autodocs_3._guide/node00AB.html), [CD_SEARCH](../Includes_and_Autodocs_3._guide/node00B6.html), [CD_ATTENUATE](../Includes_and_Autodocs_3._guide/node00A3.html)
```
