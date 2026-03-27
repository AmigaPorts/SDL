# cd.device/CD_QCODELSN



   NAME

       CD_QCODELSN -- Report current disk position.
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_QCODELSN
       io_Data         pointer to [QCode](../Includes_and_Autodocs_3._guide/node05E4.html#line284) structure
       io_Length       0 - MUST be zero (for future compatability)
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
```
   FUNCTION

```c
       This command reports current subcode Q channel time information.  This
       command only returns data when CD Audio is playing (or paused).  At
       any other time, an error is returned.  The Q-Code packet consists of:

       struct [QCode](../Includes_and_Autodocs_3._guide/node05E4.html#line284) {

           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        CtlAdr;        /* Data type / [QCode](../Includes_and_Autodocs_3._guide/node05E4.html#line284) type           */
           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        Track;         /* Track number                     */
           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        Index;         /* Track subindex number            */
           [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)        Zero;          /* The "Zero" byte of Q-Code packet */
           union LSNMSF TrackPosition; /* Position from start of track     */
           union LSNMSF DiskPosition;  /* Position from start of disk      */
           };
```
   EXAMPLE


```c
       struct [QCode](../Includes_and_Autodocs_3._guide/node05E4.html#line284) qcode;

       ior->io_Command = CD_QCODELSN;  /* Retrieve TOC information */
       ior->io_Length  = 0;            /* MUST be zero             */
       ior->io_Data    = (APTR)qcode;  /* Here's where we want it  */
       [DoIO](../Includes_and_Autodocs_3._guide/node0204.html) (ior);

       if (!ior->io_Error) {           /* Command succeeded        */

           printf("Current position is: %ldn", qcode.DiskPosition.LSN);
           }
```
   NOTES

```c
       This function may not return immediately.  It may take several frames
       to pass by before a valid Q-Code packet can be returned.  Use [SendIO()](../Includes_and_Autodocs_3._guide/node0236.html)
       and [CheckIO()](../Includes_and_Autodocs_3._guide/node01F5.html) if response time is critical, and the information is
       not.
```
   BUGS

   SEE ALSO

```c
       [CD_PLAYMSF](../Includes_and_Autodocs_3._guide/node00AD.html), [CD_PLAYLSN](../Includes_and_Autodocs_3._guide/node00AC.html), [CD_PLAYTRACK](../Includes_and_Autodocs_3._guide/node00AE.html), [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
```
