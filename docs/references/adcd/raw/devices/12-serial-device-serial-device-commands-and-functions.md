# 12 Serial Device / Serial Device Commands and Functions


Device Command   Operation
--------------   ---------
[CMD_CLEAR](../Includes_and_Autodocs_2._guide/node04CD.html)        Reset the serial port's read buffer pointers.

[CMD_FLUSH](../Includes_and_Autodocs_2._guide/node04CE.html)        Purge all queued requests for the serial device (does not

```c
                 affect active requests).
```
[CMD_READ](../Devices_Manual_guide/node009E.html)         Read a stream of characters from the serial port buffer.

```c
                 The number of characters can be specified or a
                 termination character(s) used.
```
[CMD_RESET](../Includes_and_Autodocs_2._guide/node04D0.html)        Reset the serial port to its initialized state.  All

                 active and queued I/O requests will be aborted and the
                 current buffer will be released.
[CMD_START](../Includes_and_Autodocs_2._guide/node04D1.html)        Restart all paused I/O over the serial port.  Also sends

                 an "xON".
[CMD_STOP](../Includes_and_Autodocs_2._guide/node04D2.html)         Pause all active I/O over the serial port.  Also sends an

                 "xOFF".
[CMD_WRITE](../Devices_Manual_guide/node009F.html)        Write out a stream of characters to the serial port.  The

                 number of characters can be specified or a
                 NULL-terminated string can be sent.
[SDCMD_BREAK](../Devices_Manual_guide/node00A9.html)      Send a break signal out the serial port.  May be done

```c
                 immediately or queued. Duration of the break (in
                 microseconds) can be set by the application.
```
[SDCMD_QUERY](../Devices_Manual_guide/node00A8.html)      Return the status of the serial port lines and registers,

                 and the number of bytes in the serial port's read buffer.
[SDCMD_SETPARAMS](../Devices_Manual_guide/node00A6.html)  Set the parameters of the serial port.  This ranges from


                 baud rate to number of microseconds a break will last.
Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node04CA.html)        Abort a command to the serial device. If the command is

                 in progress, it is stopped immediately.  If it is queued,
                 it is removed from the queue.
[BeginIO()](../Includes_and_Autodocs_2._guide/node04CB.html)         Initiate a command and return immediately (asynchronous

```c
                 request).  This is used to minimize the amount of system
                 overhead.
```
[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)        Determine the current state of an I/O request.

[CloseDevice()](../Includes_and_Autodocs_2._guide/node04CC.html)    Relinquish use of the serial device.  All requests must

                 be complete.
[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)           Initiate a command and wait for completion (synchronous

```c
                 request).
```
[OpenDevice()](../Includes_and_Autodocs_2._guide/node04D4.html)     Obtain use of the serial device.

[SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)         Initiate a command and return immediately (asynchronous

```c
                 request).
```
[WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)         Wait for the completion of an asynchronous request. When


                 the request is complete the message will be removed from
                 your reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)    Create an extended I/O request structure of type

```c
                 [IOExtSer](../Devices_Manual_guide/node009C.html#line7).  This structure will be used to communicate
                 commands to the serial device.
```
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)     Create a signal message port for reply messages from the

                 serial device.  Exec will signal a task when a message
                 arrives at the port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)    Delete an extended I/O request structure created by

```c
                 [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).
```
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)     Delete the message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

