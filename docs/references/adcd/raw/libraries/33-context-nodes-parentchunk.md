# 33 / / Context Nodes / ParentChunk()


To find the parent of a context, you call [ParentChunk()](../Includes_and_Autodocs_2._guide/node01D0.html) on the relevant
[ContextNode](../Libraries_Manual_guide/node0446.html):


```c
    parentnode = ParentChunk(currentnode);
```
If there is no parent context, NULL is returned.

