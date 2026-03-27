# exec.library/Remove



NAME

    Remove -- remove a node from a list
SYNOPSIS

```c
    Remove(node)
           A1

    void Remove(struct [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *);
```
FUNCTION

    Unlink a node from whatever list it is in.  Nodes that are not part
    of a list must not be passed to this funcion!  Assembly programmers
    may prefer to use the REMOVE macro from "exec/lists.i".
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    node - the node to remove
SEE ALSO

```c
    [AddHead](../Includes_and_Autodocs_2._guide/node0325.html), [AddTail](../Includes_and_Autodocs_2._guide/node032C.html), [Enqueue](../Includes_and_Autodocs_2._guide/node034D.html), Insert, [RemHead](../Includes_and_Autodocs_2._guide/node0370.html), [RemTail](../Includes_and_Autodocs_2._guide/node0377.html)
```
