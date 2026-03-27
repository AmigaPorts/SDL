# 2 Audio Device / Device Interface


The audio device operates like the other Amiga I/O devices.  To make
sound, you first open the audio device, then send I/O requests to it, and
then close it when finished.  See "[Introduction to Amiga System Devices](../Devices_Manual_guide/node0006.html)"
chapter for general information on device usage.

Audio device commands use an extended I/O request block named IOAudio to
send commands to the audio device.  This is the standard IORequest block
with some extra fields added at the end.

struct IOAudio
{
```c
    struct IORequest ioa_Request;/* I/O request block. See exec/io.h.    */
    WORD   ioa_AllocKey;       /* Alloc. key filled in by audio device   */
    UBYTE  *ioa_Data;          /* Pointer to a sample or allocation mask */
    ULONG  ioa_Length;         /* Length of sample or allocation mask.   */
    UWORD  ioa_Period;         /* Sample playback speed                  */
    UWORD  ioa_Volume;         /* Volume of sound                        */
    UWORD  ioa_Cycles;         /* # of times to play sample. 0=forever.  */
    struct Message ioa_WriteMsg;/* Filled in by device- usually not used */
```
};

See the include file devices/[audio.h](../Includes_and_Autodocs_2._guide/node0038.html) for the complete structure definition.

 [Opening The Audio Device](../Devices_Manual_guide/node001F.html) 	 [Audio And System I/O Functions](../Devices_Manual_guide/node0022.html) 
 [Audio Device Command Types](../Devices_Manual_guide/node0020.html)      [Closing The Audio Device](../Devices_Manual_guide/node0026.html) 
 [Scope Of Audio Commands](../Devices_Manual_guide/node0021.html) 

