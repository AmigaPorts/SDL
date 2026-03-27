# 5 Gameport Device / Gameport Device Commands and Functions


Command         Operation
-------         ---------
CMD_CLEAR       Clear the gameport input buffer.

[GPD_ASKCTYPE](../Devices_Manual_guide/node00B9.html)    Return the type of gameport controller being used.

[GPD_ASKTRIGGER](../Devices_Manual_guide/node00B7.html)  Return the conditions that have been preset for triggering.

[GPD_READEVENT](../Devices_Manual_guide/node00B5.html)   Read one or more gameport events.

[GPD_SETCTYPE](../Devices_Manual_guide/node00BA.html)    Set the type of the controller to be used.

[GPD_SETTRIGGER](../Devices_Manual_guide/node00B6.html)  Preset the conditions that will trigger a gameport event.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)       Abort a command to the gameport device.

[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)       Return the status of an I/O request.

[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)   Relinquish use of the gameport device.  All requests must

                be complete before closing.
[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)          Initiate a command and wait for completion (synchronous

```c
                request).
```
[OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)    Obtain shared use of one unit of the gameport device. The

                unit number specified is placed in the I/O request
                structure for use by gameport commands.
[SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)        Initiate a command and return immediately (asynchronous

```c
                request).
```
[WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)        Wait for the completion of an asynchronous request.  When


                the request is complete the message will be removed from
                reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)   Create an extended I/O request structure of type [IOStdReq](../Devices_Manual_guide/node00B0.html#line7).

                This structure will be used to communicate commands to the
                gameport device.
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)    Create a signal message port for reply messages from the

                gameport device.  Exec will signal a task when a message
                arrives at the port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)   Delete an I/O request structure created by [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).

[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)    Delete the message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

   Who Runs The Mouse?
   -------------------
   When the input device or Intution is operating, unit 0 is usually
   dedicated to gathering mouse events.  The input device uses the
   gameport device to read the mouse events.  (For applications that
   take over the machine without starting up the input device or
   Intuition, unit 0 can perform the same functions as unit 1.)  See the
   "[Input Device](../Devices_Manual_guide/node00CA.html)" chapter for more information on the input device.

