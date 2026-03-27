# 6 Input Device / Input Device Commands and Functions


Command          Operation
-------          ---------
CMD_FLUSH        Purge all active and queued requests for the input device.

CMD_RESET        Reset the input port to its initialized state.  All

                 active and queued I/O requests will be aborted.  Restarts
                 the device if it has been stopped.
CMD_START        Restart the currently active input (if any) and resume

                 queued I/O requests.
CMD_STOP         Stop any currently active input and prevent queued I/O

                 requests from starting.
[IND_ADDHANDLER](../Devices_Manual_guide/node00D2.html)   Add an input-stream handler into the handler chain.

[IND_REMHANDLER](../Devices_Manual_guide/node00D4.html)   Remove an input-stream handler from the handler chain.

[IND_SETMPORT](../Devices_Manual_guide/node00D0.html)     Set the controller port to which the mouse is connected.

[IND_SETMTRIG](../Devices_Manual_guide/node00D1.html)     Set conditions that must be met by a mouse before a

                 pending read request will be satisfied.
[IND_SETMTYPE](../Includes_and_Autodocs_2._guide/node04E5.html)     Set the type of device at the mouse port.

[IND_SETPERIOD](../Devices_Manual_guide/node00D8.html)    Set the period at which a repeating key repeats.

[IND_SETTHRESH](../Devices_Manual_guide/node00D7.html)    Set the repeating key hold-down time before repeat starts.

[IND_WRITEEVENT](../Devices_Manual_guide/node00D6.html)   Propagate an input event stream to all devices.


Input Device Function
---------------------
[PeekQualifier()](../Includes_and_Autodocs_2._guide/node04E9.html)  Return the input device's current qualifiers. (V36)


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)        Abort a command to the input device.

[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)        Return the status of an I/O request.

[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)    Relinquish use of the input device.

[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)           Initiate a command and wait for completion (synchronous

```c
                 request).
```
[OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)     Obtain shared use of the input device.

[SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)         Initiate a command and return immediately (asynchronous

```c
                 request).
```
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)    Create an extended I/O request structure of type

```c
                 [IOStdReq](../Devices_Manual_guide/node00CC.html#line12).  This structure will be used to communicate
                 commands to the input device.
```
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)     Create a signal message port for reply messages from the

                 input device.  Exec will signal a task when a message
                 arrives at the reply port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)    Delete an I/O request structure created by [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).

[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)     Delete the message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

