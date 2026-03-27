# 9 Intuition Input and Output Methods / Intuition Input


The Amiga has an input device to monitor all input activity.  The input
activity nominally includes keyboard and mouse events, but which can be
extended to include other types of input signals.  When the user moves the
mouse, presses a mouse button or types on the keyboard, the input device
detects the activity from the specific device, and constructs an
[InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198).

An [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) is a message describing a single event, such as the
transition of a key on the keyboard from up to down.

The input device then passes the input events down a prioritized chain of
input handlers, which are routines in memory that process the input
events.  The sequence of input events passing through this chain of input
handlers is known as the input stream.  Any handler linked into this chain
can monitor and modify the event stream.

Each input handler may block (consume) events, allow events to pass
through to the next handler in the chain or add new events to the sequence.

Other devices and programs can add input events to the input stream by
sending messages to the input device.  For instance, AmigaDOS is able to
generate an input event whenever a disk is inserted or removed.

See the "[Input Device](../Devices_Manual_guide/node00CA.html)" chapter of the Amiga ROM Kernel Reference Manual:
Devices for more information on the Input device.

 [Intuition as an Input Handler](../Libraries_Manual_guide/node01D1.html) 
 [Receiving Input Events from Intuition](../Libraries_Manual_guide/node01D2.html) 
 [IDCMP Events and the Input Focus](../Libraries_Manual_guide/node01D3.html) 

