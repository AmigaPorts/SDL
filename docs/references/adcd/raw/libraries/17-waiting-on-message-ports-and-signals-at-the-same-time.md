# 17 / / Waiting on Message Ports and Signals at the Same Time


Most applications need to wait for a variety of messages and signals from
a variety of sources.  For example, an application might be waiting for
Window events and also timer.device messages.  In this case, an
application must [Wait()](../Libraries_Manual_guide/node02D4.html) on the combined signal bits of all signals it is
interested in, including the signals for the message ports where any
messages might arrive.

The [MsgPort](../Libraries_Manual_guide/node02EB.html#line12) structure, which is defined in <exec/[ports.h](../Includes_and_Autodocs_2._guide/node0099.html#line27)>, is what Exec
uses to keep track of a message port.  The [UserPort](../Libraries_Manual_guide/node0121.html#line29) field from the [example](../Libraries_Manual_guide/node028C.html#line53)
above points to one of these structures.  In this structure is a field
called [mp_SigBit](../Libraries_Manual_guide/node02EB.html#line32), which contains the number (not the actual bit mask) of
the message port's signal bit.  To [Wait()](../Libraries_Manual_guide/node02D4.html) on the signal of a message port,
Wait() on a bit mask created by shifting 1L to the left mp_SigBit times
(1L << msgport->mp_SigBit).  The resulting bit mask can be OR'd with the
bit masks for any other signals you wish to simultaneously wait on.

