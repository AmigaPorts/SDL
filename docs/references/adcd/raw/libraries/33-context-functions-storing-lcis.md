# 33 / Context Functions / Storing LCIs


Once you've created and initialized an [LCI](../Libraries_Manual_guide/node044A.html), you'll want to attach it to a
[ContextNode](../Libraries_Manual_guide/node0446.html).  Though a ContextNode can have many LCIs, a given LCI can be
linked to only one ContextNode.  Once linked, an LCI cannot be removed
from a ContextNode (this may change in the future).  Storing an LCI in a
ContextNode is done with the functions StoreLocalItem() and
StoreItemInContext().

 [StoreLocalItem()](../Libraries_Manual_guide/node044E.html)    [StoreItemInContext()](../Libraries_Manual_guide/node044F.html)    [FindLocalItem()](../Libraries_Manual_guide/node0450.html) 

