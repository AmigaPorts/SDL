# 13 Timer Device / Timer Device Commands and Functions


Command        Operation
-------        ---------
[TR_ADDREQUEST](../Devices_Manual_guide/node00C4.html)  Request that the timer device wait a specified period of

               time before replying to the request.
[TR_GETSYSTIME](../Devices_Manual_guide/node00C3.html#line13)  Get system time and place in a [timeval](../Devices_Manual_guide/node00BF.html#line25) structure.

[TR_SETSYSTIME](../Devices_Manual_guide/node00C3.html#line8)  Set the system time from the value in a  [timeval](../Devices_Manual_guide/node00BF.html#line25) structure.


Device Functions
----------------
[AddTime()](../Includes_and_Autodocs_2._guide/node04F8.html)      Add one  [timeval](../Devices_Manual_guide/node00BF.html#line25) structure to another.  The result is placed

               in the first timeval structure.
[CmpTime()](../Includes_and_Autodocs_2._guide/node04F9.html)      Compare one  [timeval](../Devices_Manual_guide/node00BF.html#line25) structure to another.  The result is

               returned as a longword.
[GetSysTime()](../Includes_and_Autodocs_2._guide/node04FA.html)   Get system time and place in a  [timeval](../Devices_Manual_guide/node00BF.html#line25) structure.

[ReadEClock()](../Includes_and_Autodocs_2._guide/node04FB.html)   Read the current 64 bit value of the E-Clock into an

```c
               [EClockVal](../Devices_Manual_guide/node00BF.html#line31) structure.  The count rate of the E-Clock is also
               returned. (V36)
```
[SubTime()](../Includes_and_Autodocs_2._guide/node04FC.html)      Subtract one [timerequest](../Devices_Manual_guide/node00BF.html#line16) structure from another. The result


```c
               is placed in the first [timerequest](../Devices_Manual_guide/node00BF.html#line16) structure.
```
Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)      Abort a command to the timer device.

[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)      Return the status of an I/O request.

[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)  Relinquish use of the timer device. All requests must be

               complete before closing.
[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)         Initiate a command and wait for completion (synchronous

```c
               request).
```
[OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)   Obtain use of the timer device.  The timer device may be

               opened multiple times.
[SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)       Initiate a command and return immediately (asynchronous


```c
               request).
```
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)  Create an extended I/O request structure of type

```c
               [timerequest](../Devices_Manual_guide/node00BF.html#line16).  This structure will be used to communicate
               commands to the timer device.
```
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)   Create a signal message port for reply messages from the

               timer device.  Exec will signal a task when a message
               arrives at the reply port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)  Delete the [timerequest](../Devices_Manual_guide/node00BF.html#line16) extended I/O request structure

```c
               created by [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).
```
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)   Delete the message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

