# 9 Parallel Device / Parallel Device Commands and Functions


Command          Operation
-------          ---------
[CMD_FLUSH](../Includes_and_Autodocs_2._guide/node04EC.html)        Purge all queued requests for the parallel device.  Does

                 not affect active requests.
[CMD_READ](../Devices_Manual_guide/node0012.html)         Read a stream of characters from the parallel port.  The

```c
                 number of characters can be specified or a termination
                 character(s) can be used.
```
[CMD_RESET](../Includes_and_Autodocs_2._guide/node04EE.html)        Reset the parallel port to its initialized state.  All

                 active and queued I/O requests will be aborted.
[CMD_START](../Includes_and_Autodocs_2._guide/node04EF.html)        Restart all paused I/O over the parallel port.

                 Reactivates the handshaking sequence.
[CMD_STOP](../Includes_and_Autodocs_2._guide/node04F0.html)         Pause all active I/O over the parallel port.  Deactivates

                 the handshaking sequence.
[CMD_WRITE](../Devices_Manual_guide/node0013.html)        Write out a stream of characters to the parallel port.

                 The number of characters can be specified or a
                 NULL-terminated string can be sent.
[PDCMD_QUERY](../Devices_Manual_guide/node0018.html)      Return the status of the parallel port lines and

                 registers.
[PDCMD_SETPARAMS](../Devices_Manual_guide/node0016.html)  Set the parameters of the parallel port.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)        Abort a command to the parallel device. If the command is

                 in progress, it is stopped immediately.  If it is queued,
                 it is removed from the queue.
[BeginIO()](../Includes_and_Autodocs_2._guide/node0141.html)        Initiate a command and return immediately (asynchronous

```c
                 request).  This is used to minimize the amount of system
                 overhead.
```
[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)        Determine the current state of an I/O request.

[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)    Relinquish use of the parallel device.  All requests must

                 be complete.
[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)           Initiate a command and wait for completion (synchronous

```c
                 request).
```
[OpenDevice()](../Includes_and_Autodocs_2._guide/node04F2.html)     Obtain use of the parallel device.

[SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)         Initiate a command and return immediately (asynchronous

```c
                 request).
```
[WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)         Wait for the completion of an asynchronous request.  When


                 the request is complete the message will be removed from
                 your reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)    Create an extended I/O request structure of type

                 IOExtPar.  This structure will be used to communicate
                 commands to the parallel device.
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)     Create a signal message port for reply messages from the

                 parallel device.  Exec will signal a task when a message
                 arrives at the port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)    Delete an extended I/O request structure created by

```c
                 CreateExtIO().
```
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)     Delete the message port created by CreatePort().

