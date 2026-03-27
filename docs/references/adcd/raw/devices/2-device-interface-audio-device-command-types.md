# 2 / Device Interface / Audio Device Command Types


Commands for audio use can be divided into two categories:
allocation/arbitration commands and hardware control commands.

There are four allocation/arbitration commands.  These do not actually
produce any sound.  Instead they manage and arbitrate the audio resources
for the many tasks that may be using audio in the Amiga's multitasking
environment.


```c
    [ADCMD_ALLOCATE](../Devices_Manual_guide/node002A.html)   - Reserves an audio channel for your program to use.
    [ADCMD_FREE](../Devices_Manual_guide/node002F.html)       - Frees an audio channel.
    [ADCMD_SETPREC](../Devices_Manual_guide/node0030.html)    - Changes the precedence of a sound in progress.
    [ADCMD_LOCK](../Devices_Manual_guide/node0031.html)       - Tells if a channel has been stolen from you.
```
The hardware control commands are used to set up, start, and stop sounds
on the audio device:


```c
    [CMD_WRITE](../Devices_Manual_guide/node0033.html)        - The main command.  Starts a sound playing.
    [ADCMD_FINISH](../Devices_Manual_guide/node0034.html)     - Aborts a sound in progress.
    [ADCMD_PERVOL](../Devices_Manual_guide/node0035.html)     - Changes the period (speed) and volume of a sound
                        in progress.
    [CMD_FLUSH](../Devices_Manual_guide/node0036.html)        - Clears the audio channels.
    [CMD_RESET](../Devices_Manual_guide/node0037.html)        - Resets and initializes the audio device.
    [ADCMD_WAITCYCLE](../Devices_Manual_guide/node0038.html)  - Signals you when a cycle finishes.
    [CMD_STOP](../Devices_Manual_guide/node0039.html)         - Temporarily stops a channel from playing.
    [CMD_START](../Devices_Manual_guide/node003A.html)        - Restarts an audio channel that was stopped.
    [CMD_READ](../Devices_Manual_guide/node003B.html)         - Returns a pointer to the current IOAudio request.
```
