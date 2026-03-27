# 31 Commodities Exchange Library / Controlling CxMessages


A [Custom CxObject](../Libraries_Manual_guide/node040E.html) has the power to directly manipulate the [CxMessages](../Libraries_Manual_guide/node0403.html) that
travel around the Commodities network.  One way is to directly change
values in the corresponding input event.  Another way is to redirect (or
dispose of) the CxMessages.


```c
    void DivertCxMsg ( CxMsg *cxm, CxObj *headobj, CxObj *retobj );
    void RouteCxMsg  ( CxMsg *cxm, CxObj *co );
    void DisposeCxMsg( CxMsg *cxm );
```
[DivertCxMsg()](../Includes_and_Autodocs_2._guide/node01AB.html) and [RouteCxMsg()](../Includes_and_Autodocs_2._guide/node01B1.html) dictate where the [CxMessage](../Libraries_Manual_guide/node0403.html) will go next.
Conceptually, DivertCxMsg() is analogous to a subroutine in a program; the
CxMessage will travel down the personal list of a [CxObject](../Libraries_Manual_guide/node0401.html) (headobj in the
prototype) until it gets to the end of that list.  It then returns and
visits the CxObject that follows the return CxObject (the return CxObject
in the prototype above is retobj).  RouteCxMsg() is analogous to a goto in
a program; it has no CxObject to return to.

[DisposeCxMsg()](../Includes_and_Autodocs_2._guide/node01AA.html) removes a [CxMessage](../Libraries_Manual_guide/node0403.html) from the network and releases its
resources.  The [translate CxObject](../Libraries_Manual_guide/node040A.html) uses this function to remove a
CxMessage.

The example Divert.c shows how to use [DivertCxMsg()](../Includes_and_Autodocs_2._guide/node01AB.html) as well as a
[signal CxObject](../Libraries_Manual_guide/node040D.html).


```c
     [divert.c](../Libraries_Manual_guide/node0585.html) 
```
