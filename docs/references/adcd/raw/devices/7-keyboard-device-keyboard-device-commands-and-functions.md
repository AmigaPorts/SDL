# 7 Keyboard Device / Keyboard Device Commands and Functions


Command               Operation
-------               ---------
[CMD_CLEAR](../Includes_and_Autodocs_2._guide/node050C.html)             Clear the keyboard input buffer.  Removes any key

                      transitions from the input buffer.
[KBD_ADDRESETHANDLER](../Devices_Manual_guide/node0103.html)   Add a reset handler function to the list of

                      functions called  by the keyboard device to clean up
                      before a hard reset.
[KBD_REMRESETHANDLER](../Devices_Manual_guide/node0104.html)   Remove a previously added reset handler from the

                      list of functions called by the keyboard device to
                      clean up before a hard reset.
[KBD_RESETHANDLERDONE](../Devices_Manual_guide/node0105.html)  Indicate that a handler has completed its job and

                      reset could possibly occur now.
[KBD_READMATRIX](../Devices_Manual_guide/node0101.html)        Read the state of every key in the keyboard.  Tells

                      the up/down state of every key.
[KBD_READEVENT](../Includes_and_Autodocs_2._guide/node050E.html)         Read one (or more) raw key event from the keyboard


                      device.
Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)             Abort a command to the keyboard device.

[AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html)            Allocate a block of memory.

[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)             Return the status of an I/O request.

[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)         Relinquish use of the keyboard device.

[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)                Initiate a command and wait for it to complete

```c
                      (synchronous request).
```
[FreeMem()](../Includes_and_Autodocs_2._guide/node0355.html)             Free a block of previously allocated memory.

[OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)          Obtain use of the keyboard device.

[SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)              Initiate a command and return immediately

```c
                      (asynchronous request).
```
[WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)              Wait for the completion of an asynchronous request.


                      When the request is complete the message will be
                      removed from reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)         Create an extended I/O request structure.  This

                      structure will be used to communicate commands to
                      the keyboard device.
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)          Create a signal message port for reply messages from

                      the keyboard device.  Exec will signal a task when a
                      message arrives at the port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)         Delete an extended I/O request structure created by

```c
                      [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).
```
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)          Delete the message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

