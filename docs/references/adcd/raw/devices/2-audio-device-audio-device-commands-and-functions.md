# 2 Audio Device / Audio Device Commands and Functions


Command          Operation
-------          ---------
 [ADCMD_ALLOCATE](../Devices_Manual_guide/node002A.html)    Allocate one or more of the four audio channels.

 [ADCMD_FINISH](../Devices_Manual_guide/node0034.html)      Abort the current write request on one or more of the

                   channels.  Can be done immediately or at the end of the
                   current cycle.
 [ADCMD_FREE](../Devices_Manual_guide/node002F.html)        Free one or more audio channels.

 [ADCMD_LOCK](../Devices_Manual_guide/node0031.html)        Lock one or more audio channels.

 [ADCMD_PERVOL](../Devices_Manual_guide/node0035.html)      Change the period and volume for writes in progress. Can

                   be done immediately or at the end of the cycle.
 [ADCMD_SETPREC](../Devices_Manual_guide/node0030.html)     Set the allocation precedence of one or more channels.

 [ADCMD_WAITCYCLE](../Devices_Manual_guide/node0038.html)   Wait for the current write cycle to complete on a single

                   channel.  Returns at the end of the cycle or immediately
                   if no cycle is active on the channel.
 [CMD_FLUSH](../Devices_Manual_guide/node0036.html)         Purge all write cycles and waitcycles (in-progress and

```c
                   queued) for one or more channels.
```
 [CMD_READ](../Devices_Manual_guide/node003B.html)          Return a pointer to the I/O block currently writing on a

                   single channel.
 [CMD_RESET](../Devices_Manual_guide/node0037.html)         Reset one or more channels their initialized state.  All

                   active and queued requests will be aborted.
 [CMD_START](../Devices_Manual_guide/node003A.html)         Resume writes to one or more channels that were stopped.

 [CMD_STOP](../Devices_Manual_guide/node0039.html)          Stop any write cycle in progress on one or more

                                   channels.
 [CMD_WRITE](../Devices_Manual_guide/node0033.html)         Start a write cycle on a single channel.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node04A5.html)        Abort a command to the audio device. If in progress, it

                 is stopped immediately, otherwise it is removed from the
                 queue.
[BeginIO()](../Includes_and_Autodocs_2._guide/node04AD.html)        Initiate a command and return immediately (asynchronous

```c
                 request).
```
[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)        Determine the current state of an I/O request.

[CloseDevice()](../Includes_and_Autodocs_2._guide/node04AE.html)    Relinquish use of the audio device.

[OpenDevice()](../Includes_and_Autodocs_2._guide/node04B8.html)     Obtain use of the audio device.

[Wait()](../Includes_and_Autodocs_2._guide/node038A.html)           Wait for a signal from the audio device.

[WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html)       Wait for the audio message port to receive a message.


Exec Support Functions as Used in This Chapter
----------------------------------------------
[AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html)       Allocate a block of memory.

[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)     Create a signal message port for reply messages from the

                 audio device.  Exec will signal a task when a message
                 arrives at the reply port.
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)     Delete the message port created by CreatePort().

[FreeMem()](../Includes_and_Autodocs_2._guide/node0355.html)        Free a block of previously allocated memory.

