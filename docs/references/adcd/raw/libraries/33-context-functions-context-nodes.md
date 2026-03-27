# 33 / Context Functions / Context Nodes


The current context is said to be the top element on the stack.
Contextual information is stored in a structure called a [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line61):


```c
    struct ContextNode {
            struct MinNode  cn_Node;
            LONG            cn_ID;
            LONG            cn_Type;
            LONG            cn_Size; /*  Size of this chunk             */
            LONG            cn_Scan; /*  # of bytes read/written so far */
            /*  There are private fields hiding here.  */
            };
```
 [CurrentChunk()](../Libraries_Manual_guide/node0447.html)    [ParentChunk()](../Libraries_Manual_guide/node0448.html) 

