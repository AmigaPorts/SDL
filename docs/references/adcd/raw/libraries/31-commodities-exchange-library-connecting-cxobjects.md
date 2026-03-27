# 31 Commodities Exchange Library / Connecting CxObjects


A [CxObject](../Libraries_Manual_guide/node0401.html) has to be inserted into the Commodities network before it can
process any [CxMessages](../Libraries_Manual_guide/node0403.html).  [AttachCxObj()](../Includes_and_Autodocs_2._guide/node019F.html) adds a CxObject to the personal
list of another CxObject.  The HotKey.c example uses it to attach its
[filter](../Libraries_Manual_guide/node0407.html) to a [broker](../Libraries_Manual_guide/node0402.html).


```c
    void AttachCxObj ( CxObj *headobj, CxObj *co);
    void InsertCxObj ( CxObj *headobj, CxObj *co, CxObj *co_pred );
    void EnqueueCxObj( CxObj *headobj, CxObj *co );
    void SetCxObjPri ( CxObj *co, long pri );
    void RemoveCxObj ( CxObj *co );
```
[AttachCxObj()](../Includes_and_Autodocs_2._guide/node019F.html) adds the [CxObject](../Libraries_Manual_guide/node0401.html) to the end of headobj's personal list.
The ordering of a CxObject list determines which object gets [CxMessages](../Libraries_Manual_guide/node0403.html)
first.  [InsertCxObj()](../Includes_and_Autodocs_2._guide/node01AD.html) also inserts a CxObject, but it inserts it after
another CxObject already in the personal list (co_pred in the prototype
above).

[Brokers](../Libraries_Manual_guide/node0402.html) aren't the only [CxObjects](../Libraries_Manual_guide/node0401.html) with a priority.  All CxObjects have a
priority associated with them.  To change the priority of any CxObject,
use the [SetCxObjPri()](../Includes_and_Autodocs_2._guide/node01B2.html) function.  A commodity can use the priority to keep
CxObjects in a personal list sorted by their priority.  The
commodities.library function [EnqueueCxObj()](../Includes_and_Autodocs_2._guide/node01AC.html) inserts a CxObject into
another CxObject's personal list based on priority.

Like its name implies, the [RemoveCxObj()](../Includes_and_Autodocs_2._guide/node01B0.html) function removes a [CxObject](../Libraries_Manual_guide/node0401.html) from
a personal list.  Note that it is not necessary to remove a CxObject from
a list in order to delete it.


```c
     [HotKey.c](../Libraries_Manual_guide/node0587.html) 
```
