# 33 / Context Functions / The Default Context


When you first obtain an [IFFHandle](../Libraries_Manual_guide/node042C.html) through [AllocIFF()](../Libraries_Manual_guide/node042C.html), a hidden default
context node is created.  You cannot get direct access to this node
through [CurrentChunk()](../Libraries_Manual_guide/node0447.html) or [ParentChunk()](../Libraries_Manual_guide/node0448.html).  However, using [StoreLocalItem()](../Libraries_Manual_guide/node044E.html),
you can store information in this context.

