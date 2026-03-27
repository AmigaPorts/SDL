# 31 Commodities Exchange Library / Sender CxObjects


A [filter CxObject](../Libraries_Manual_guide/node0407.html) by itself is not especially useful.  It needs some other
[CxObjects](../Libraries_Manual_guide/node0401.html) attached to it.  A commodity interested in knowing if a specific
key was pressed uses a filter to detect and divert the corresponding
[CxMessage](../Libraries_Manual_guide/node0403.html) down the filter's personal list.  The filter does this without
letting the commodity know what happened.  The sender CxObject can be
attached to a filter to notify a commodity that it received a CxMessage.
[CxSender()](../Includes_and_Autodocs_2._guide/node014E.html) is a macro that creates a sender CxObject.


```c
    senderCxObj = CxObj *CxSender(struct MsgPort *senderport, LONG cxmID);
```
[CxSender()](../Includes_and_Autodocs_2._guide/node014E.html) supplies the sender with an Exec message port and an ID.  For
every [CxMessage](../Libraries_Manual_guide/node0403.html) a sender receives, it sends a new CxMessage to the Exec
message port passed in CxSender().  Normally, the commodity creates this
port.  It is not unusual for a commodity's [broker](../Libraries_Manual_guide/node0402.html) and sender(s) to share
an Exec message port.  The [HotKey.c](../Libraries_Manual_guide/node0587.html) example does this to avoid creating
unnecessary message ports.  A sender uses the ID (cxmID) passed to
CxSender() as the ID for all the CxMessages that the it transmits.  A
commodity uses the ID to monitor CxMessages from several senders at a
single message port.

A sender does several things when it receives a [CxMessage](../Libraries_Manual_guide/node0403.html).  First, it
duplicates the CxMessage's corresponding input event and creates a new
CxMessage.  Then, it points the new CxMessage's data field to the copy of
the input event and sets the new CxMessage's ID to the ID passed to
[CxSender()](../Includes_and_Autodocs_2._guide/node014E.html).  Finally, it sends the new CxMessage to the port passed to
CxSender(), asynchronously.

Because HotKey uses only one message port between its [broker](../Libraries_Manual_guide/node0402.html) and sender
object, it has to extract the [CxMessage](../Libraries_Manual_guide/node0403.html)'s type so it can tell if it is a
CXM_IEVENT or a CXM_COMMAND.  If HotKey gets a CXM_IEVENT, it compares the
CxMessage's ID to the sender's ID, EVT_HOTKEY, to see which sender sent
the CxMessage.  Of course HotKey has only one sender, so it only checks
for only one ID.  If it had more senders, HotKey would check for the ID of
each of the other senders as well.

Although HotKey doesn't use it, a [CXM_IEVENT CxMessage](../Libraries_Manual_guide/node0403.html) contains a pointer
to the copy of an input event.  A commodity can extract this pointer
( using [CxMsgData()](../Libraries_Manual_guide/node0403.html#line10) ) if it needs to examine the input event copy.  This
pointer is only valid before the CxMessage reply.  Note that it does not
make any sense to modify the input event copy.

Senders are attached almost exclusively to [CxObjects](../Libraries_Manual_guide/node0401.html) that filter out most
input events (usually a [filter CxObject](../Libraries_Manual_guide/node0407.html)).  Because a sender sends a
[CxMessage](../Libraries_Manual_guide/node0403.html) for every single input event it gets, it should only get a
select few input events.  The [AttachCxObj()](../Libraries_Manual_guide/node0408.html) function can add a CxObject to
the end of a filter's (or some other filtering CxObject's) personal list.
A commodity should not attach a CxObject to a sender as a sender ignores
any CxObjects in its personal list.

