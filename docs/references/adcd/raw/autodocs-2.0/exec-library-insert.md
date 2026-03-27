# exec.library/Insert



NAME

    Insert -- insert a node into a list
SYNOPSIS

```c
    Insert(list, node, listNode)
           A0    A1    A2

    void Insert(struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *, struct [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *, struct [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *);
```
FUNCTION

```c
    Insert a node into a doubly linked list AFTER a given node
    position.  Insertion at the head of a list is possible by passing a
    zero value for listNode, though the [AddHead](../Includes_and_Autodocs_2._guide/node0325.html) function is slightly
    faster for that special case.
```
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    list - a pointer to the target list header
    node - the node to insert
    listNode - the node after which to insert
SEE ALSO

```c
    [AddHead](../Includes_and_Autodocs_2._guide/node0325.html), [AddTail](../Includes_and_Autodocs_2._guide/node032C.html), [Enqueue](../Includes_and_Autodocs_2._guide/node034D.html), [RemHead](../Includes_and_Autodocs_2._guide/node0370.html), Remove, [RemTail](../Includes_and_Autodocs_2._guide/node0377.html)
```
