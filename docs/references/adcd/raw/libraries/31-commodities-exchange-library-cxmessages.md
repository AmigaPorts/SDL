# 31 Commodities Exchange Library / CxMessages


There are actually two types of CxMessages.  The first, [CXM_IEVENT](../Includes_and_Autodocs_2._guide/node00F0.html#line100),
corresponds to an input event and travels through the Commodities Exchange
network.  The other type, [CXM_COMMAND](../Includes_and_Autodocs_2._guide/node00F0.html#line113), carries a command to a commodity.
A CXM_COMMAND normally comes from the controller program and is used to
pass user commands on to a commodity.  A commodity receives these commands
through an Exec message port that the commodity sets up before it calls
[CxBroker()](../Libraries_Manual_guide/node0402.html#line14).  The [NewBroker](../Libraries_Manual_guide/node0402.html#line20)'s [nb_Port](../Libraries_Manual_guide/node0402.html#line32) field points to this message port.  A
commodity can tell the difference between the two types of CxMessages by
calling the [CxMsgType()](../Includes_and_Autodocs_2._guide/node01A5.html) function.


```c
    ULONG  CxMsgType( CxMsg *cxm );
    UBYTE *CxMsgData( CxMsg *cxm );
    LONG   CxMsgID  ( CxMsg *cxm );
```
A CxMessage not only has a type, it can also have a data pointer as well
as an ID associated with it.  The data associated with a [CXM_IEVENT](../Includes_and_Autodocs_2._guide/node00F0.html#line100)
CxMessage is an [InputEvent](../Libraries_Manual_guide/node01D0.html) structure.  By using the [CxMsgData()](../Includes_and_Autodocs_2._guide/node01A3.html) function,
a commodity can obtain a pointer to the corresponding InputEvent of a
CXM_IEVENT message.  Commodities Exchange gives an ID of zero to any
CXM_IEVENT CxMessage that it introduces to the Commodities network but
certain [CxObjects](../Libraries_Manual_guide/node0401.html) can assign an ID to them.

For a [CXM_COMMAND](../Includes_and_Autodocs_2._guide/node00F0.html#line113) CxMessages, the data pointer is generally not used but
the ID specifies a command passed to the commodity from the user operating
the controller program.  The [CxMsgID()](../Includes_and_Autodocs_2._guide/node01A4.html) macro extracts the ID from a
CxMessage.

 [A Simple Commodity Example](../Libraries_Manual_guide/node0586.html) 
 [Controller Commands](../Libraries_Manual_guide/node0404.html) 
 [Shutting Down the Commodity](../Libraries_Manual_guide/node0405.html) 

