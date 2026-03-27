# 10 Printer Device / Printer Device Commands and Functions


Command         Operation
-------         ----------
[CMD_FLUSH](../Includes_and_Autodocs_2._guide/node0513.html)       Remove all queued requests for the printer device.  Does

                not affect active requests.
[CMD_RESET](../Includes_and_Autodocs_2._guide/node0515.html)       Reset the printer device to its initialized state.  All

                active and queued I/O requests will be aborted.
[CMD_START](../Includes_and_Autodocs_2._guide/node0516.html)       Restart all paused I/O requests

[CMD_STOP](../Includes_and_Autodocs_2._guide/node0517.html)        Pause all active and queued I/O requests.

[CMD_WRITE](../Devices_Manual_guide/node0046.html)       Write out a stream of characters to the printer device.

                The number of characters can be specified or a
                NULL-terminated string can be sent.
[PRD_DUMPRPORT](../Devices_Manual_guide/node004F.html)   Dump the specified RastPort to a graphics printer.

[PRD_PRTCOMMAND](../Includes_and_Autodocs_2._guide/node051A.html)  Send a command to the printer.

[PRD_QUERY](../Devices_Manual_guide/node004D.html)       Return the status of the printer port's lines and

                registers.
[PRD_RAWWRITE](../Includes_and_Autodocs_2._guide/node051C.html)    Send unprocessed output to the the printer.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)       Abort a command to the printer device.

[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)   Relinquish use of the printer device.  All requests must

                be complete before closing.
[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)          Start a command and wait for completion (synchronous

```c
                request).
```
[OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)    Obtain use of the printer device.

[SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)        Start a command and return immediately (asynchronous

```c
                request).
```
[WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)        Wait for the completion of an asynchronous request.  When


                the request is complete, the message will be removed from
                the printer message port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)    Create a signal message port for reply messages from the

                audio device.  Exec will signal a task when a message
                arrives at the reply port.
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)   Create an I/O request structure of type printerIO.  This

                structure will be used to send commands to the printer
                device.
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)    Delete the message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)   Delete an I/O request structure created by [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).

