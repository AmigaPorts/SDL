# exec.library/AddHead



NAME

    AddHead -- insert node at the head of a list
SYNOPSIS

```c
    AddHead(list, node)
            A0    A1

    void AddHead(struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *, struct [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *)
```
FUNCTION

    Add a node to the head of a doubly linked list. Assembly
    programmers may prefer to use the ADDHEAD macro from
    "exec/lists.i".
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    list - a pointer to the target list header
    node - the node to insert at head
SEE ALSO

```c
    [AddTail](../Includes_and_Autodocs_2._guide/node032C.html), [Enqueue](../Includes_and_Autodocs_2._guide/node034D.html), Insert, Remove, [RemHead](../Includes_and_Autodocs_2._guide/node0370.html), [RemTail](../Includes_and_Autodocs_2._guide/node0377.html)
```
