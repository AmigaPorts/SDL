# exec.library/Enqueue



NAME

    Enqueue -- insert or append node to a system queue
SYNOPSIS

```c
    Enqueue(list, node)
            A0    A1

    void Enqueue(struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *, struct [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *);
```
FUNCTION

    Insert or append a node into a system queue.  The insert is
    performed based on the node priority -- it will keep the list
    properly sorted.  New nodes will be inserted in front of the first
    node with a lower priority.   Hence a FIFO queue for nodes of equal
    priority
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    list - a pointer to the system queue header
    node - the node to enqueue.  This must be a full featured list
           with type, priority and name fields.
SEE ALSO

```c
    [AddHead](../Includes_and_Autodocs_2._guide/node0325.html), [AddTail](../Includes_and_Autodocs_2._guide/node032C.html), Insert, Remove, [RemHead](../Includes_and_Autodocs_2._guide/node0370.html), [RemTail](../Includes_and_Autodocs_2._guide/node0377.html)
```
