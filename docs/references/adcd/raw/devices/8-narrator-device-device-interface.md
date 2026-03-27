# 8 Narrator Device / Device Interface


The narrator device operates like all other Amiga devices.  To use the
narrator device, you must first open it.  This initializes certain global
areas, opens the audio device, allocates audio channels, and performs
other housekeeping functions.  Once open, the device is ready to receive
I/O commands (most typically [CMD_WRITE](../Includes_and_Autodocs_2._guide/node04C7.html) and[CMD_READ](../Includes_and_Autodocs_2._guide/node04C3.html)). Finally, when
finished, the user should close the device.  This will free some buffers
and allow the entire device to be expunged should the system require
memory.  See the [Introduction to Amiga System Devices](../Devices_Manual_guide/node0006.html) chapter for general
information on device usage.

The narrator device uses two extended I/O request structures: narrator_rb
for write commands (to produce speech output) and mouth_rb for read
commands (to receive mouth shape changes and word/syllable synchronization
events).  Both I/O request structures have been expanded (in a backwards
compatible fashion) for the V37 narrator device with several new fields
defined.


```c
    struct narrator_rb
    {
       struct IOStdReq  message; /* Standard IORequest Block       */
       UWORD   rate;             /* Speaking rate (words/minute)   */
       UWORD   pitch;            /* Baseline pitch in Hertz        */
       UWORD   mode;             /* Pitch mode                     */
       UWORD   sex;              /* Sex of voice                   */
       UBYTE   *ch_masks;        /* Pointer to audio allocation maps  */
       UWORD   nm_masks;         /* Number of audio allocation maps   */
       UWORD   volume;           /* Volume. 0 (off) thru 64        */
       UWORD   sampfreq;         /* Audio sampling frequency       */
       UBYTE   mouths;           /* If non-zero, generate mouths   */
       UBYTE   chanmask; /* Which ch mask used (internal - do not modify)*/
       UBYTE   numchan;  /* Num ch masks used (internal- do not modify) */
       UBYTE   flags;            /* New feature flags              */
       UBYTE   F0enthusiasm;     /* F0 excursion factor            */
       UBYTE   F0perturb;        /* Amount of F0 perturbation      */
       BYTE    F1adj;            /* F1 adjustment in +- 5% steps   */
       BYTE    F2adj;            /* F2 adjustment in +- 5% steps   */
       BYTE    F3adj;            /* F3 adjustment in +- 5% steps   */
       BYTE    A1adj;            /* A1 adjustment in decibels      */
       BYTE    A2adj;            /* A2 adjustment in decibels      */
       BYTE    A3adj;            /* A3 adjustment in decibels      */
       UBYTE   articulate;       /* Transition time multiplier     */
       UBYTE   centralize;       /* Degree of vowel centralization */
       char    *centphon;        /* Pointer to central ASCII phon  */
       BYTE    AVbias;           /* Amplitude of voicing bias      */
       BYTE    AFbias;           /* Amplitude of frication bias    */
       BYTE    priority;         /* Priority while speaking        */
       BYTE    pad1;             /* For alignment                  */
    };

    struct mouth_rb
    {
       struct  narrator_rb voice;/* Speech IORequest Block         */
       UBYTE   width;            /* Mouth width (returned value)   */
       UBYTE   height;           /* Mouth height (returned value)  */
       UBYTE   shape;            /* Internal use, do not modify    */
       UBYTE   sync;             /* Returned sync events           */
    };
```
Details on the meaning of the various fields of the two I/O request blocks
can be found in the [Writing to the Narrator Device](../Devices_Manual_guide/node0119.html) and
[Reading from the Narrator Device](../Devices_Manual_guide/node011A.html) sections later in this chapter.  See
the include file devices/[narrator.h](../Includes_and_Autodocs_2._guide/node0042.html) for the complete structure definitions.

 [The Amiga Speech System](../Devices_Manual_guide/node0116.html) 
 [Opening The Narrator Device](../Devices_Manual_guide/node0117.html) 
 [Closing The Narrator Device](../Devices_Manual_guide/node0118.html) 

