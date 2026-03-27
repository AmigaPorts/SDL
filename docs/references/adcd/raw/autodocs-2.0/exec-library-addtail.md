# exec.library/AddTail



NAME

    AddTail -- append node to tail of a list
SYNOPSIS

```c
    AddTail(list, node)
            A0    A1

    void AddTail(struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *, struct [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *);
```
FUNCTION

    Add a node to the tail of a doubly linked list.  Assembly
    programmers may prefer to use the ADDTAIL macro from
    "exec/lists.i".
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    list - a pointer to the target list header
    node - a pointer to the node to insert at tail of the list
SEE ALSO

```c
    [AddHead](../Includes_and_Autodocs_2._guide/node0325.html), [Enqueue](../Includes_and_Autodocs_2._guide/node034D.html), Insert, Remove, [RemHead](../Includes_and_Autodocs_2._guide/node0370.html), [RemTail](../Includes_and_Autodocs_2._guide/node0377.html)
```
