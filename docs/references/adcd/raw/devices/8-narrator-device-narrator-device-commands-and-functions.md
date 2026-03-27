# 8 Narrator Device / Narrator Device Commands and Functions


Command         Operation
-------         ---------
[CMD_FLUSH](../Includes_and_Autodocs_2._guide/node04C2.html)       Purge all active and queued requests for the narrator

                device.
[CMD_READ](../Devices_Manual_guide/node011A.html)        Read mouth shapes associated with an active write from the

                narrator device.
[CMD_RESET](../Includes_and_Autodocs_2._guide/node04C4.html)       Reset the narrator port to its initialized state. All

                active and queued I/O requests will be aborted.  Restarts
                the device if it has been stopped.
[CMD_START](../Includes_and_Autodocs_2._guide/node04C5.html)       Restart the currently active speech (if any) and resume

                queued I/O requests.
[CMD_STOP](../Includes_and_Autodocs_2._guide/node04C6.html)        Stop any currently active speech and prevent queued I/O

                requests from starting.
[CMD_WRITE](../Devices_Manual_guide/node0119.html)       Write a stream of characters to the narrator device and


                generate mouth movement data for reads.
Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node04C0.html)       Abort a command to the narrator device. If the command is

                in progress, it is stopped immediately.  If it is queued,
                it is removed from the queue.
[BeginIO()](../Includes_and_Autodocs_2._guide/node0141.html)       Initiate a command and return immediately (asynchronous

```c
                request).  This is used to minimize the amount of system
                overhead.
```
[CloseDevice()](../Includes_and_Autodocs_2._guide/node04C1.html)   Relinquish use of the narrator device.  All requests must

                be complete.
[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)       Return the status of an I/O request.

[CloseLibrary()](../Includes_and_Autodocs_2._guide/node0340.html)  Relinquish use of a previously opened library.

[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)          Initiate a command and wait for completion (synchronous

```c
                request). Should be used with care because it will not
                return control if the request does not complete.
```
[OpenDevice()](../Includes_and_Autodocs_2._guide/node04C8.html)    Obtain use of the narrator device.

[OpenLibrary()](../Includes_and_Autodocs_2._guide/node0367.html)   Obtain use of a library.

[SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)        Initiate a command and return immediately (asynchronous

```c
                request).
```
[WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)        Wait for the completion of an asynchronous request. When


                the request is complete the message will be removed from
                reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)   Create an extended I/O request structure of type

                narrator_rb.  This structure will be used to communicate
                commands to the narrator device.
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)    Create a signal message port for reply messages from the

                narrator device.  Exec will signal a task when a message
                arrives at the port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)   Delete an extended I/O request structure created by

```c
                [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).
```
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)    Delete the message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

