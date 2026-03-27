# 3 Clipboard Device / Clipboard Device Commands and Functions


Command             Command Operation
-------             -----------------
[CBD_CHANGEHOOK](../Devices_Manual_guide/node0070.html)      Specify a hook to be called when the data on the

```c
                    clipboard has changed (V36).
```
[CBD_CURRENTREADID](../Devices_Manual_guide/node006D.html#line13)   Return the Clip ID of the current clip to read.  This

                    is used to determine if a clip posting is still the
                    latest cut.
[CBD_CURRENTWRITEID](../Devices_Manual_guide/node006D.html#line18)  Return the Clip ID of the latest clip written.  This

                    is used to determine if the clip posting data is
                    obsolete.
[CBD_POST](../Includes_and_Autodocs_2._guide/node04DC.html)            Post the availability of clip data.

[CMD_READ](../Devices_Manual_guide/node006E.html)            Read data from the clipboard for a paste.  Data can be

                    read from anywhere in the clipboard by specifying an
                    offset >0 in the I/O request.
[CMD_UPDATE](../Devices_Manual_guide/node006C.html)          Indicate that the data provided with a write command

                    is complete and available for subsequent read/pastes.
[CMD_WRITE](../Devices_Manual_guide/node006B.html)           Write data to the clipboard as a cut.


Exec Functions as Used in This Chapter
--------------------------------------
[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)       Relinquish use of the clipboard device.  All requests

                    must be complete before closing.
[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)              Initiate a command and wait for completion

```c
                    (synchronous request).
```
[GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html)            Get next message from a message port.

[OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)        Obtain use of the clipboard device.

[SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)            Initiate a command and return immediately


```c
                    (asynchronous request).
```
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)       Create an I/O request structure of type IOClipReq.

                    This structure will be used to communicate commands to
                    the clipboard device.
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)        Create a signal message port for reply messages from

                    the clipboard device.  Exec will signal a task when a
                    message arrives at the port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)       Delete an I/O request structure created by

```c
                    CreateExtIO().
```
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)        Delete the message port created by CreatePort().

