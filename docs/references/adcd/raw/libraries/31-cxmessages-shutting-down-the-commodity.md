# 31 / CxMessages / Shutting Down the Commodity


Shutting down a commodity is easy.  After replying to all [CxMessages](../Libraries_Manual_guide/node0403.html)
waiting at the [broker](../Libraries_Manual_guide/node0402.html)'s message port, a commodity can delete its
[CxObjects](../Libraries_Manual_guide/node0401.html).  The [DeleteCxObj()](../Includes_and_Autodocs_2._guide/node01A8.html) function removes a single CxObject from the
Commodities network.  [DeleteCxObjAll()](../Includes_and_Autodocs_2._guide/node01A9.html) removes multiple objects.


```c
    void DeleteCxObj( CxObj *co );
    void DeleteCxObjAll( CxObj *delete_co );
```
If a commodity has a lot of [CxObjects](../Libraries_Manual_guide/node0401.html), deleting each individually can be a
bit tedious.  [DeleteCxObjAll()](../Includes_and_Autodocs_2._guide/node01A9.html) will delete a CxObject and any other
CxObjects that are attached to it.  The [HotKey.c](../Libraries_Manual_guide/node0587.html) example given later in
this chapter uses this function to delete all its CxObjects.  A commodity
that uses DeleteCxObjAll() to delete all its CxObjects should make sure
that they are all connected to the main one.  (See the section
"[Connecting CxObjects](../Libraries_Manual_guide/node0408.html)" below.)

After deleting its [CxObjects](../Libraries_Manual_guide/node0401.html), a commodity must take care of any [CxMessages](../Libraries_Manual_guide/node0403.html)
that might have arrived at the message port just before the commodity
deleted its objects.


```c
    while(msg = (CxMsg *)GetMsg(broker_mp))
        ReplyMsg((struct Message *)msg);
```
