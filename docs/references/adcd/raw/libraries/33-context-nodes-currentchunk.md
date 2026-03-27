# 33 / / Context Nodes / CurrentChunk()


You can obtain a pointer to the current [ContextNode](../Libraries_Manual_guide/node0446.html) through the function
[CurrentChunk()](../Includes_and_Autodocs_2._guide/node01BE.html):


```c
    currentnode = CurrentChunk (iff);
```
The [ContextNode](../Libraries_Manual_guide/node0446.html) tells you the type, ID, and size of the currently active
chunk.  If there is no currently active context, NULL is returned.

