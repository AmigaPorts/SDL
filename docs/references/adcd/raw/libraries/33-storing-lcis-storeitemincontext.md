# 33 / / Storing LCIs / StoreItemInContext()


[StoreItemInContext()](../Includes_and_Autodocs_2._guide/node01DC.html) is used when you already have a pointer to the
[ContextNode](../Libraries_Manual_guide/node0446.html) to which you want to attach your [LCI](../Libraries_Manual_guide/node044A.html).  It is called like so:


```c
    StoreItemInContext (iff, lci, contextnode);
```
[StoreItemInContext()](../Includes_and_Autodocs_2._guide/node01DC.html) links your [LCI](../Libraries_Manual_guide/node044A.html) into the specified [ContextNode](../Libraries_Manual_guide/node0446.html).  Then
it searches the ContextNode to see if there is another LCI with the same
type, ID, and identification values.  If so, the old one is deleted.

