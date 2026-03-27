# 4 Console Device / Console Device Commands and Functions


Command              Operation
-------              ---------
[CD_ASKDEFAULTKEYMAP](../Devices_Manual_guide/node0096.html#line5)  Get the current default keymap.

[CD_ASKKEYMAP](../Includes_and_Autodocs_2._guide/node0502.html)         Get the current key map structure for this console.

[CD_SETDEFAULTKEYMAP](../Devices_Manual_guide/node0096.html#line5)  Set the current default keymap.

[CD_SETKEYMAP](../Includes_and_Autodocs_2._guide/node0504.html)         Set the current key map structure for this console.

[CMD_CLEAR](../Includes_and_Autodocs_2._guide/node0506.html)            Remove any reports waiting to satisfy read requests

                     from the console input buffer.
[CMD_READ](../Devices_Manual_guide/node008F.html)             Read the next input, generally from the keyboard.

                     The form of this input is as an ANSI byte stream.
[CMD_WRITE](../Devices_Manual_guide/node008A.html)            Write a text record to the display interpreting


                     any ANSI control characters in the record.
Console Device Function
-----------------------
[CDInputHandler()](../Includes_and_Autodocs_2._guide/node0505.html)     Handle an input event for the console device.

[RawKeyConvert()](../Includes_and_Autodocs_2._guide/node050A.html)      Decode raw input classes and convert input events of


                     type IECLASS_RAWKEY to ANSI bytes based on the keymap
                     in use.
Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)            Abort an I/O request to the console device.

[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)            Return the status of an I/O request.

[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)        Relinquish use of the console device.  All requests

                     must be complete before closing.
[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)               Initiate a command and wait for completion

```c
                     (synchronous request).
```
[GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html)             Get the next message from the reply port.

[OpenDevice()](../Includes_and_Autodocs_2._guide/node0509.html)         Obtain use of the console device.  You specify the

```c
                     type of unit and its characteristics in the call to
                     OpenDevice().
```
[OpenLibrary()](../Includes_and_Autodocs_2._guide/node0367.html)        Gain access to a library.

[OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html)         Open an intuition window.

[SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)             Initiate a command and return immediately

```c
                     (asynchronous request).
```
[Wait()](../Includes_and_Autodocs_2._guide/node038A.html)               Wait for one or more signals.

[WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)             Wait for completion of an I/O request and remove it

                     from the reply port.
[WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html)           Wait for the reply port to be non-empty. Does not


                     remove the message from port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)        Create an extended I/O request structure for use in

                     communicating with the console device.
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)         Create a message port for reply messages from the

                     console device.  Exec will signal a task when a
                     message arrives at the port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)        Delete the extended I/O request structure created by

```c
                     [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).
```
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)         Delete the message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

