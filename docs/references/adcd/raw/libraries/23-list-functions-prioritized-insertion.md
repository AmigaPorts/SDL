# 23 / List Functions / Prioritized Insertion


The list functions discussed so far do not make use of the priority field
in a [Node](../Libraries_Manual_guide/node02D9.html#line19). The [Enqueue()](../Includes_and_Autodocs_2._guide/node034D.html) function is equivalent to [Insert()](../Libraries_Manual_guide/node02DE.html), except it
inserts nodes into a list sorting them according to their priority.  It
keeps the higher-priority nodes towards the head of the list.  All nodes
passed to this function must have their priority and name assigned prior
to the call. Enqueue([header](../Libraries_Manual_guide/node02DD.html#line21),mynode) inserts mynode behind the lowest
priority node with a priority greater than or equal to mynode's. For
Enqueue() to work properly, the list must already be sort according to
priority.  Because the highest priority node is at the head of the list,
the [RemHead()](../Libraries_Manual_guide/node02E0.html) function will remove the highest-priority node.  Likewise,
[RemTail()](../Libraries_Manual_guide/node02E0.html) will remove the lowest-priority node.


```c
    FIFO Is Used For The Same Priority.
    -----------------------------------
    If you add a node that has the same priority as another node in the
    queue, [Enqueue()](../Includes_and_Autodocs_2._guide/node034D.html) will use [FIFO](../Libraries_Manual_guide/node02E0.html) ordering.  The new node is inserted
    following the last node of equal priority.
```
